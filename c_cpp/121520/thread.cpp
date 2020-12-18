#include <iostream>
#include <sstream>
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

  file << "Exit from " << this_id << std::endl;
  file << std::endl;

  locker.unlock();
}

int main() 
{  
  // Write file
  std::ofstream write;

  write.open("test.txt");

  std::thread th1( [&]
  {
    job(write);
  });

  std::thread th2( [&]
  {
    job(write);
  });

  th1.join();
  th2.join();

  write.close();

  // Read file
  std::ifstream read;
  read.open("test.txt");

  std::thread th3( [&]
  {
    locker.lock();

    // Count words
    unsigned int counter{0};

    read.clear();
    read.seekg(0, std::ios::beg);

    std::thread::id this_id = std::this_thread::get_id();
    
    for(std::string line; getline(read, line);)
    {
      std::stringstream ss(line);
      for(std::string word; ss >> word; counter++) {}
    }

    std::cout << this_id << " count word: " << counter << " words" << std::endl;

    locker.unlock();
  });

  std::thread th4( [&]
  {
    locker.lock();

    // Count lines
    unsigned int counter{0};

    read.clear();
    read.seekg(0, std::ios::beg);

    std::thread::id this_id = std::this_thread::get_id();
    
    for(std::string line; getline(read, line); counter++) {}

    std::cout << this_id << " count line: " << counter << " lines" << std::endl;
    
    locker.unlock();
  });

  th3.join();
  th4.join();

  read.close();

  return 0; 
} 