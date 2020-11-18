#include <iostream>
#include <string>
#include <sstream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main(int argc,const char** argv)
{
    int i{1};
    int n;
    char deli;
    int result{0};
    stringstream ss;

    for(; i<argc; i++)
    {
        ss << argv[i];
    }

    int id = fork();

    if(id==0)
    {
        // In child process
        while(ss>>n)
        {
            ss >> deli;
            result += n;
        }

        cout << "In child - Addition: " << result << endl;

        // Exit Child
        exit(EXIT_SUCCESS);
    }
    else 
    {
        // Wait for Child
        wait(NULL);
        
        // In parent process
        result = 1;

        while(ss>>n)
        {
            ss >> deli;
            result *= n;
        }

        cout << "In parent - Multiply: " << result << endl;
    }

    return 0;
}
