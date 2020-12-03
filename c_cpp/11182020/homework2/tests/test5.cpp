#include <iostream>
#include <stdio.h>
#include <getopt.h>
using namespace std;

static int verbose_flag;

int main(int argc, char** argv)
{
  int c;

  while(1)
  {
    const struct option long_options[] =
    {
      {"help", no_argument, 0, 'h'},
      {"fork", no_argument, 0, 'f'},
      {"thread", no_argument, 0, 't'},
      {"max-line", required_argument, 0, 0},
      {"max-thread", required_argument, 0, 1},
      {0, 0, 0, 0}
    };

    const char* short_opts = "::hftwl";

    int option_index{0};

    c = getopt_long(argc, argv, short_opts, long_options, &option_index);

    if(c==-1) break;

    switch(c)
    {
      case 0:
        if(long_options[option_index].flag!=0) break;
        cout << long_options[option_index].name << endl;

        if(optarg)
          cout << optarg << endl;
      
        break;

      case 1:
        if(long_options[option_index].flag!=0) break;
        cout << long_options[option_index].name << endl;

        if(optarg)
          cout << optarg << endl;
      
        break;

      case 'h':
        cout << "h" << endl;
        break;

      case 'f':
        cout << "f" << endl;
        break;

      case 't':
        cout << "t" << endl;
        break;

      case '?':
        cout << argv[optind] << endl;
        cout << "Do not known" << endl;
        break;
      
      default:
        abort();
    }
  }

  if(verbose_flag)
    cout << "Verbose flag is set" << endl;

  while(optind<argc)
  {
    cout << "!" << argv[optind++] << endl;
  }

  return 0;
}
