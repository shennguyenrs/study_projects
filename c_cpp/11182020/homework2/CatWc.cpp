#include <iostream>
#include <fstream>
#include <sstream>

#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <pthread.h>

#include "CatWc.hpp"
using namespace std;

/*
 * Class Multi Threads functions
 */

/*
 * Class CatWc functions
 */

void CatWc::setMaxLine(unsigned int const lines)
{
  maxLine = lines;
}

void CatWc::setIsHelp(bool const result)
{
  isHelp = result;
}

void CatWc::setIsFork(const bool result)
{
  isFork = result;
}

void CatWc::setIsThread(const bool result)
{
  isThread = result;
}

void CatWc::setIsCount(const bool result)
{
  isCount = result;
}

bool CatWc::isExist(char* const filename)
{
  struct stat buffer;
  return (stat(filename, &buffer)==0);
}

void CatWc::printHelp()
{
  // Introduction
  cout << RED 
    << "Usage: catwc [OPTION]... [FILE]..." 
    << RESET << endl;
  cout << "Concatenate FILE(s) and count words, lines." << endl;
  cout << "Two features can be processed in concurrent by using fork and threads" << endl;
  cout << endl;

  // Long options and alias
  cout << GRN << "Options:" << RESET << endl;
  cout << "  -h, --help" << "\t" 
    << "display help menu" << endl;
  cout << "  -f, --fork" << "\t" 
    << "using fork to run features in concurrent" << endl;
  cout << "  -t, --thread" << "\t" 
    << "using threads to run features in concurrent" << endl;
  cout << "      --max-line" << "\t" 
    << "change maximum display lines. " 
    << RED 
    << "By default maximum display line is 5." 
    << RESET << endl;
  cout << endl;

  // Examples
  cout << GRN << "Examples:" << RESET << endl;
  cout << "  cat file1 file2" << "\t" 
    << "Display the content of file1, its words count and lines count, then do the same with file2." << endl;
  cout << "  cat -wl file" << "\t" 
    << "Display only the words count and lines count of file" << endl;
  cout << "  cat -f file" << "\t" 
    << "Display the content of file, its words count and line count using concurrent" << endl;
  cout << endl;
}

void CatWc::parseArg()
{
  int c;

  while(1)
  {
    int index{0};

    c = getopt_long(
        argc, argv, 
        shortOpts, longOpts,
        &index);

    // Break when meet the end of options
    if(c==-1) break;

    // Switch case to divide options
    switch(c)
    {
      // Get max lines
      case 0:
        {
          if(longOpts[index].flag!=0) break;
          unsigned int newMax = atoi(optarg);
          setMaxLine(newMax);
          break;
        }

      case 'h':
        {
          setIsHelp(true);
          break;
        }

      case 'c':
        {
          setIsCount(true);
          break;
        }

      case 'f':
        {
          setIsFork(true);
          break;
        }
      
      case 'p':
        {
          setIsThread(true);
          break;
        }

      case '?':
        break;

      default:
        abort();
    }
  }

  // Push filename to queue
  if(optind>argc)
  {
    cout << "Missing files name" << endl;
    return;
  }

  while(optind<argc)
  {
    files.push(argv[optind++]);
  }
}

void CatWc::doCommand()
{
  // If argv has help flag
  if(isHelp)
  {
    printHelp();
    return;
  }

  // If argv have fork and thread at the same time
  if(isFork && isThread)
  {
    cout
      << RED 
      << "Can not use fork and thread at the same time" 
      << RESET 
      << endl;
    return;
  }

  // If argv has count-only
  if(isCount)
  {
    while(!files.empty())
    {
      // Print the word and line count if file is exist
      if(isExist(files.front()))
      {
        wcFile(files.front());
        files.pop();
        continue;
      }

      // If file is not exist, print out the messages
      cout << RED << files.front() 
        << " is not exist!" 
        << RESET << endl;
      files.pop();
    }

    return;
  }

  // Not use multi threads
  if(!isFork && !isThread)
  {
    useDefault();
    return;
  }

  // Use fork concurrent 
  if(isFork)
  {
    useFork();
    return;
  }

  // Use threads concurrent 
  //if(isThread)
  //{
    //useThread();
    //return;
  //}
}

void CatWc::catFile(char* const filename)
{
  ifstream file;

  file.open(filename);

  // Display messages if open file is fail
  if(!file.is_open())
  {
    cout << "Error to open file" << endl;
    return;
  }

  // Display the content of the file
  string line;
  unsigned int i{0};

  cout << GRN << breakLine << RESET << endl;

  while(getline(file, line) || i<=maxLine)
  {
    cout << line << endl;
    i++;
  }

  // Close file when done
  file.close();
}

void CatWc::wcFile(char* const filename)
{
  // Create open file for share memory
  int fd = open(filename, O_RDONLY, S_IRUSR | S_IWUSR);
  struct stat sb;

  if(fstat(fd, &sb))
  {
    cout << "Could not get file size" << endl;
  }

  char* fileInMemory = 
    static_cast<char*> 
    (mmap(NULL, sb.st_size, PROT_READ, MAP_SHARED, fd, 0));

  // Print break line after cat file
  cout << GRN << breakLine << RESET << endl;

  // Create fork
  pid_t pid;
  pid = fork();

  if(pid<0)
  {
    cout << "In WcFile function:" << endl;
    cout << "Could not create child process" << endl;
  }
  else if(pid==0)
  {
    // In Child process
    stringstream ss(fileInMemory);
    unsigned int counter{0};

    for(string word; ss >> word; counter++) {};

    cout << GRN 
      << "Word count: " << counter << " words" 
      << RESET << endl;

    exit(0);
  }
  else 
  {
    // In parent process
    waitpid(pid, NULL, 0);

    stringstream ss(fileInMemory);
    unsigned int counter{0};
    
    for(string line; getline(ss, line); counter++) {};

    cout << GRN 
      << "Line count: " << counter << " lines" 
      << RESET << endl;
  }

  // Unmap the shared file
  munmap(fileInMemory, sb.st_size);

  // Close file
  close(fd);
}

void CatWc::useDefault()
{
  while(!files.empty())
  {
    if(isExist(files.front()))
    {
      catFile(files.front());
      wcFile(files.front());
      files.pop();
      continue;
    }

    // Print messages if file is not exist
    cout << RED 
      << files.front() << " is not exist" 
      << RESET << endl;
    files.pop();
  }
}

void CatWc::useFork()
{
  while(!files.empty())
  {
    if(isExist(files.front()))
    {
      pid_t pid;
      pid =fork();

      if(pid<0)
      {
        cout << "In useFork()" << endl;
        cout << "Can not create child process!" << endl;
      }
      else if(pid==0)
      {
        // In child process, do cat file
        catFile(files.front());
        exit(0);
      }
      else
      {
        // In parent process, do wc file
        waitpid(pid, NULL, 0);
        wcFile(files.front());
      }

      files.pop();
      continue;
    }

    // Print messages if file is not exist
    cout << RED 
      << files.front() << " is not exist" 
      << RESET << endl;
    files.pop();
  }
}
