// Copyright (C) 2014-2015 Oleksandr Shturmov.
//
// Sandstone Basic License - Version 3.0 - March 20, 2015.

// mntns-exec
//
// Execute a program contained in a mount namespace. Largely equivalent to
// unshare -m, but no reliance on a preexisting shell.

#define _GNU_SOURCE     // Necessary to get CLONE_NEWNS from <sched.h>.

#include <sched.h>      // CLONE_NEWNS
#include <stdlib.h>     // exit, EXIT_SUCCESS
#include <unistd.h>     // execvp

#include "fail.h"       // FAIL

int
main(int argc, char *argv[])
{
  if (unshare(CLONE_NEWNS) == -1)
  {
    FAIL("unshare");
  }

  if (argc > 1)
  {
    execvp(argv[1], argv + 1);

    FAIL("execvp");
  }

  exit(EXIT_SUCCESS);
}
