// Copyright (C) 2015 OnlineTA.
//
// Sandstone Basic License - Version 3.0 - May 4, 2015.

// mntns-exec
//
// Execute a program contained in a mount namespace. Largely equivalent to
// unshare -m, but no reliance on a preexisting shell.

#define _GNU_SOURCE     // Necessary to get CLONE_NEWNS from <sched.h>.
#include <sched.h>      // CLONE_NEWNS

#include "ctrl-flow.h"  // stone_break, stone_continue

int
main(int argc, char *argv[])
{
  if (unshare(CLONE_NEWNS) == -1)
  {
    stone_break("unshare");
  }

  stone_continue("continue", argc, argv);
}
