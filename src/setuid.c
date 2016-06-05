// Copyright (c) 2016 OnlineTA.
//
// Sandstone Basic License - Version 3.0 - May 4, 2015.

#include "setuid.h"

#include "ctrl-flow.h"  // stone_break, stone_continue

#include <errno.h>      // errno
#include <limits.h>     // UID_MAX
#include <stdlib.h>     // strtoul
#include <unistd.h>     // syscall, chdir

#include <stdio.h>

void
setuid_exec(int argc, char *argv[])
{
  unsigned long int uid;
  char *endptr;

  if (argc > 1)
  {
    uid = strtoul(*argv, &endptr, 10);
    if (uid == ULONG_MAX && errno == ERANGE) {
      stone_break(errno, "couldn't parse uid given to setuid\n");
    } else if (uid == 0) {
      stone_break(0, "If you want uid 0, why are you using setuid?\n");
//    } else if (uid > UID_MAX) {
//      stone_break(0, "uid is too big\n");
    }

    if (setuid(uid) != 0) {
      stone_break(0, "couldn't setuid\n");
    }

    stone_continue(argc - 1, argv + 1, "continue from setuid\n");
  }
  else
  {
    stone_break(0, "uid argument missing\n");
  }
}
