// Copyright (c) 2016 OnlineTA.
//
// Sandstone Basic License - Version 3.0 - May 4, 2015.

#include "setuid.h"

int
main(int argc, char * argv[])
{
  setuid_exec(argc - 1, argv + 1);
  return 0;
}
