#pragma once

#include <queue>
#include <mutex>
#include <string>

#include <getopt.h>

// Text colors
#define RED   "\x1B[31m"
#define GRN   "\x1B[32m"
#define YEL   "\x1B[33m"
#define BLU   "\x1B[34m"
#define MAG   "\x1B[35m"
#define CYN   "\x1B[36m"
#define WHT   "\x1B[37m"
#define RESET "\x1B[0m"

const std::string breakLine = "------------------------------";

//#ifndef _CAT_WC_
//#define _CAT_WC_

class CatWc
{
  private:
    int argc;
    char** argv;

    std::queue<char*> files;

    unsigned int maxLine{5};
    bool isHelp{false};
    bool isFork{false};
    bool isThread{false};
    bool isCount{false};

    const struct option longOpts[6] =
    {
      {"help", no_argument, 0, 'h'},
      {"count-only", no_argument, 0, 'c'},
      {"fork", no_argument, 0, 'f'},
      {"pthread", no_argument, 0, 'p'},
      {"max-line", required_argument, 0, 0},
      {0, 0, 0, 0}
    };

    const char* shortOpts = ":hcfp";

    std::mutex locker;

  public:
    // Initializer
    CatWc(int argc, char** argv):
      argc{argc},
      argv{argv}
    {}

    // Constructor
    CatWc() {}

    // Destructor
    ~CatWc() {}

    // Set max lines
    void setMaxLine(unsigned int const lines);

    // Set exit from help
    void setIsHelp(bool const result);

    // Set isFork
    void setIsFork(bool const result);

    // Set isThread
    void setIsThread(bool const result);

    // Set isInfo
    void setIsCount(bool const result);

    // Check if file is exist
    bool isExist(char* const filename);

    // Create shared file in memory
    void sharedFile(
        char* filename,
        char** fileInMemory,
        struct stat* fileSize);
    
    // Print out help of the funtions
    void printHelp();
    
    // Parse arguments to vector
    void parseArg();

    // Excute command
    void doCommand();

    // Display file content
    void catFile(char* const filename);

    // Display words and lines count
    // Using explicit concurrent to count lines and words
    void wcFile(char* const filename);

    // Not using multi threads
    void useDefault();

    // Using fork to cat and wc
    void useFork();

    // Display file content used by threads
    void tCatFile(char* const filename);

    // Display words and lines count used by thread
    // Using explicit concurrent to count lines and words
    void tWcFile(char* const filename);

    // Using thread to cat and wc
    void useThread();
};

//#endif
