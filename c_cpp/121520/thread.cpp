#include <iostream>
#include <fstream>
#include <mutex>
#include <unistd.h>
#include <thread>

std::mutex locker; 

void job(std::ofstream& file) 
{ 
  locker.lock(); 

  std::thread::id this_id = std::this_thread::get_id();

  file << "Enter thread ID: " << this_id << std::endl;

  for(size_t i{0}; i<=10; i++)
  {
    file << i << std::endl;
  }

  file << "Exit from thread " << this_id << std::endl;

  locker.unlock();
}

int main() 
{  
  std::ofstream file;

  file.open("test.txt");

  std::thread th1( [&]
  {
    job(file);
  });

  std::thread th2( [&]
  {
    job(file);
  });

  th1.join();
  th2.join();

  file.close();

	return 0; 
} 