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
