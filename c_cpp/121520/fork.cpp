#include <iostream>
#include <fstream>
#include <mutex>
#include <unistd.h>
#include <sys/wait.h>

std::mutex locker; 

void job(std::ofstream& file) 
{ 
  locker.lock();

  file << "Enter from " << getpid() << std::endl;

  for(size_t i{0}; i<=10; i++)
  {
    file << i << std::endl;
  }

  file << "Exit from " << getpid() << std::endl;

  locker.unlock();
}

int main() 
{  
  std::ofstream file;

  file.open("test.txt");

  pid_t pid = fork();

  if(pid==0)
  {
    file << "Child Process" << std::endl;
    job(file);
    exit(0);
  }
  else
  {
    waitpid(pid, NULL, 0);
    file << "Parent Process" << std::endl;
    job(file);
  }

  file.close();

	return 0; 
} 