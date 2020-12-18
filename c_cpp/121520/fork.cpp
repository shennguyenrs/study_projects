#include <iostream>
#include <sstream>
#include <fstream>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <fcntl.h>

void write(std::ofstream& file) 
{ 
  file << "Enter from process id " << getpid() << std::endl;

  for(size_t i{0}; i<=10; i++)
  {
    file << i << std::endl;
  }

  file << "Exit from " << getpid() << std::endl;
  file << std::endl;
}

int main() 
{  
  // Write file
  std::ofstream file;

  file.open("test.txt");

  pid_t pid = fork();

  if(pid==0)
  {
    // In Child process
    file << "Child Process" << std::endl;
    write(file);
    exit(0);
  }
  else
  {
    // In Parent process
    waitpid(pid, NULL, 0);
    file << "Parent Process" << std::endl;
    write(file);
  }

  file.close();

  // Read file
  int fd = open("test.txt", O_RDONLY, S_IRUSR | S_IWUSR);
  struct stat fileSize;
  char* fileInMemory;

  if(fstat(fd, &fileSize))
  {
    std::cout << "Could not get file size" << std::endl;
  }

  // Make shared memory
  fileInMemory = static_cast<char*> 
    (mmap(NULL, fileSize.st_size, PROT_READ, MAP_SHARED, fd, 0));

  pid = fork();

  if(pid==0)
  {
    // In Child process
    std::stringstream ss(fileInMemory);
    unsigned int counter{0};

    for(std::string word; ss >> word; counter++) {};

    std::cout << getpid() << " count word: " << counter << " words" << std::endl;

    exit(0);
  }
  else 
  {
    // In parent process
    waitpid(pid, NULL, 0);

    std::stringstream ss(fileInMemory);
    unsigned int counter{0};
    
    for(std::string line; getline(ss, line); counter++) {};

    std::cout << getpid() << " count line: " << counter << " lines" << std::endl;
  }

  // Unmap the shared file
  munmap(fileInMemory, fileSize.st_size);

  // Close file
  close(fd);

  return 0; 
}