#include <iostream>
#include <fstream>
#include <sstream>

#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/mman.h>

#include "CatWc.hpp"
using namespace std;

void CatWc::setMaxThreads(const unsigned int threads)
{
  // Set max thread worker
  // if it smaller than hardware limit
  if(threads<maxThreads) maxThreads = threads;
}

void CatWc::setMaxLine(unsigned int const lines)
{
  maxLine = lines;
}

void CatWc::setIsHelp(bool const value)
{
  isHelp = value;
}

void CatWc::setIsFork(bool const value)
{
  isFork = value;
}

void CatWc::setIsThread(bool const value)
{
  isThread = value;
}

void CatWc::setIsCount(bool const value)
{
  isCount = value;
}

void CatWc::setIsPool(bool const value)
{
  isPool = value;
}

void CatWc::setReturnHC(bool const value)
{
  isReturnHC = value;
}

unsigned int CatWc::getMaxThreads()
{
  return maxThreads;
}

bool CatWc::isExist(char* const filename)
{
  struct stat buffer;
  return (stat(filename, &buffer)==0);
}

void CatWc::sharedFile(
    char* filename,
    char** fileInMemory,
    struct stat* fileSize)
{
  int fd = open(filename, O_RDONLY, S_IRUSR | S_IWUSR);

  if(fstat(fd, fileSize))
  {
    cout << RED << "Could not get file size" << RESET << endl;
  }

  *fileInMemory = 
    static_cast<char*> 
    (mmap(NULL, (*fileSize).st_size, PROT_READ, MAP_SHARED, fd, 0));
}

void CatWc::printHelp()
{
  // Introduction
  cout << RED 
    << "Usage: catwc [OPTION]... [FILE]..." 
    << RESET << endl;
  cout << "Concatenate FILE(s) and count words, lines." << endl;
  cout << "Two features can be processed in concurrent by using fork and threads." << endl;
  cout << endl;

  // Long options and alias
  cout << GRN << "Options:" << RESET << endl;
  cout << "  -h, --help" << "\t\t" 
    << "display help menu." << endl;
  cout << "  -c, --count-only" << "\t\t"
    << "display count words and line only." << endl;
  cout << "  -f, --fork" << "\t\t" 
    << "using fork to run features in concurrent." << endl;
  cout << "  -p, --pthread" << "\t\t" 
    << "using threads to run features in concurrent." << endl;
  cout << "  -P, --threads-pool" << "\t\t"
    << "using threads pool to run features in concurrent." << endl;
  cout << "  -g, --get-max-threads" << "\t\t"
    << "get hardware max threads." << endl;
  cout << "      --max-thread" << "\t\t"
    << "change the maximum thread worker in pool. "
    << RED << "The new value must be smaller than hardware limit."
    << RESET << endl;
  cout << "      --max-line" << "\t\t" 
    << "change maximum display lines. " 
    << RED 
    << "By default maximum display line is 5." 
    << RESET << endl;
  cout << endl;

  // Examples
  cout << GRN << "Examples:" << RESET << endl;
  cout << "  catwc file1 file2" << "\t\t" 
    << "Display the content of file1, its words count and lines count, then do the same with file2." << endl;
  cout << "  catwc -c file" << "\t\t" 
    << "Display only the words count and lines count of file." << endl;
  cout << "  catwc -f file" << "\t\t" 
    << "Display the content of file, its words count and line count using fork." << endl;
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

      // Get max thread
      case 1:
        {
          if(longOpts[index].flag!=0) break;
          unsigned int newThread = atoi(optarg);
          setMaxThreads(newThread);
          break;
        }

      // Get help
      case 'h':
        {
          setIsHelp(true);
          break;
        }

      // Get count-only
      case 'c':
        {
          setIsCount(true);
          break;
        }

      // Get fork
      case 'f':
        {
          setIsFork(true);
          break;
        }
      
      // Get pthread
      case 'p':
        {
          setIsThread(true);
          break;
        }

      // Get pool
      case 'P':
        {
          setIsPool(true);
          break;
        }

      // Get return max thread
      case 'g':
        {
          setReturnHC(true);
          break;
        }

      // Case ?
      default:
        {
          cout << RED 
            << "Your option(s) is not availabe!" << endl;
          cout << "Use -h or --help to check user guide!" 
            << RESET << endl;
        exit(1);
        }
    }
  }

  // Push filename to queue
  if(optind>=argc && !isHelp)
  {
    cout << RED
      << "Expected argument after options!"
      << RESET << endl;
    return;
  }

  while(optind<argc)
  {
    files.push(argv[optind++]);
    workLoads++;
  }
}

void CatWc::doCommand()
{
  // If argv has help
  if(isHelp)
  {
    printHelp();
    return;
  }

  // If argv has return hardware concurrency
  if(isReturnHC)
  {
    getMaxThreads();
    return;
  }

  // If argv has fork, thread or thread pool with count-only at the same time
  if(
      (isCount && (isFork || isThread || isPool))
      || (isFork && (isCount || isThread || isPool))
      || (isThread && (isCount || isFork || isPool))
      || (isPool && (isCount || isFork || isThread))
    )
  {
    cout
      << RED 
      << "Can not use fork, thread or thread pool with count-only at the same time" 
      << RESET 
      << endl;
    return;
  }

  // If argv has count-only
  if(isCount)
  {
    useCount();
    return;
  }

  // Not use multi threads
  if(!isFork && !isThread && !isPool)
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
  if(isThread)
  {
    useThread();
    return;
  }

  // Use thread pool concurrent
  if(isPool)
  {
    usePool();
    return;
  }
}

void CatWc::catFile(char* const filename)
{
  ifstream file;

  file.open(filename);

  // Display messages if open file is fail
  if(!file.is_open())
  {
    cout << RED << "In catFile()" << RESET << endl;
    cout << RED << "Error to open file" << RESET << endl;
    return;
  }

  // Display the content of the file
  string line;
  unsigned int i{0};

  cout << GRN << breakLine << RESET << endl;

  while(getline(file, line) && i<=maxLine)
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
  char* fileInMemory;
  struct stat fileSize;
  sharedFile(filename, &fileInMemory, &fileSize);

  // Print break line after cat file
  cout << GRN << breakLine << RESET << endl;

  // Create fork
  pid_t pid;
  pid = fork();

  if(pid<0)
  {
    cout << "In wcFile()" << endl;
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
  munmap(fileInMemory, fileSize.st_size);

  // Close file
  //close(fd);
}

void CatWc::catWcFile(char *const filename)
{
  locker.lock();

  catFile(filename);
  wcFile(filename);

  locker.unlock();
}

void CatWc::useCount()
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
    cout << RED << "File \""
      << files.front() 
      << "\" is not exist!" 
      << RESET << endl;
    files.pop();
  }
}

void CatWc::useDefault()
{
  while(!files.empty())
  {
    if(isExist(files.front()))
    {
      catWcFile(files.front());
      files.pop();
      continue;
    }

    // Print messages if file is not exist
    cout << RED << "File \""
      << files.front() << "\" is not exist" 
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
        cout << "Could not create child process" << endl;
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
    cout << RED << "File \""
      << files.front() << "\" is not exist" 
      << RESET << endl;
    files.pop();
  }
}

void CatWc::tCatFile(char* const filename)
{
  // Lock
  locker.lock();

  catFile(filename);

  // Unlock
  locker.unlock();
}

void CatWc::tWcFile(char* const filename)
{
  // Lock
  locker.lock();

  wcFile(filename);

  // Unlock
  locker.unlock();
}

void CatWc::useThread()
{
  while(!files.empty())
  {
    if(isExist(files.front()))
    {
      // Create ptr to call member function
      //CatWc* ptr1 = new CatWc();
      //CatWc* ptr2 = new CatWc();

      //ptr1->setMaxLine(maxLine);
      //ptr2->setMaxLine(maxLine);

      //thread th1(&CatWc::tCatFile, ptr1, files.front());
      //thread th2(&CatWc::tWcFile, ptr2, files.front());
      
      thread th1([=] 
          {
            tCatFile(files.front());
          });

      thread th2([=] 
          {
            tWcFile(files.front());
          });

      th1.join();
      th2.join();

      files.pop();
      //delete ptr1;
      //delete ptr2;

      continue;
    }

    // Print messages if file is not exist
    cout << RED << "File \""
      << files.front() << "\" is not exist" 
      << RESET << endl;
    files.pop();
  }
}

void CatWc::usePool()
{
  // If the worker is less than the work load
  if(maxThreads<workLoads)
  {
    while(workLoads>0)
    {
      unsigned int workerOnWork = maxThreads;

      // Submit work to workers
      while(workerOnWork>0)
      {
        if(isExist(files.front()))
        {
          char * file = new char;
          file = files.front();

          workers.push(thread( [=] 
                {
                catWcFile(file);
                }));

          files.pop();

          workerOnWork--;
          workLoads--;

          if(workLoads==0) break;
          continue;
        }

        // Print messages if file is not exist
        cout << RED << "File \""
          << files.front() << "\" is not exist" 
          << RESET << endl;
        files.pop();
      }

      // Terminate the workers
      while(!workers.empty())
      {
        workers.front().join();
        workers.pop();
      }
    }

    return;
  }

  // If the worker is more than the work load
  // Submit works to workers
  while(!files.empty())
  {
    if(isExist(files.front()))
    {
      char* file = new char;
      file = files.front();

      workers.push(thread( [=] 
            {
            catWcFile(file);
            }));

      files.pop();
      continue;
    }

    // Print messages if file is not exist
    cout << RED << "File \""
      << files.front() << "\" is not exist" 
      << RESET << endl;
    files.pop();
  }

  // Terminate the workers
  while(!workers.empty())
  {
    workers.front().join();
    workers.pop();
  }
}
