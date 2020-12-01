#include <iostream>
#include <getopt.h>

#include "CatWc.hpp"
using namespace std;

int main(int argc, char** argv)
{
  CatWc cmd(argc, argv);
  cmd.parseArg();
  cmd.doCommand();

  return 0;
}
