// Copyright (C) 2014 Kiy Avenue.
//
// Sandstone Basic License - Version 0.2 - June 16, 2014.

// Execute a program contained in a mount namespace. Largely equivalent to
// unshare -m, but no reliance on a preexisting shell.

#define _GNU_SOURCE     // Necessary to get CLONE_*.

#include <stdlib.h>     // exit, EXIT_*
#include <unistd.h>     // execvp
#include <sched.h>      // CLONE_*

#include "error.h"

int
main(int argc, char *argv[])
{
  if (unshare(CLONE_NEWNS) == -1)
  {
    ERROR_REPORT("unshare");
    exit(EXIT_FAILURE);
  }

  if (argc > 1)
  {
    execvp(argv[1], argv + 1);

    ERROR_REPORT("execvp");
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
