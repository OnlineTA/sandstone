// Copyright (c) 2015 OnlineTA.
//
// Sandstone Basic License - Version 3.0 - May 4, 2015.

#include "pivot-root.h"

#include <errno.h>      // errno
#include <string.h>
#include <syscall.h>    // SYS_pivot_root
#include <unistd.h>     // syscall, chdir

#include <stdio.h>

#include "ctrl-flow.h"  // stone_break, stone_continue

static inline void
pivot_root(const char *newroot)
{
  size_t newroot_len = strlen(newroot);
  char oldroot[newroot_len + sizeof(OLDROOT)];

  memcpy(oldroot, newroot, newroot_len);
  memcpy(oldroot + newroot_len, OLDROOT, sizeof(OLDROOT));

  printf("NEWROOT %s\n", newroot);
  printf("OLDROOT %s\n", oldroot);

  if (syscall(SYS_pivot_root, newroot, oldroot) != 0)
  {
    stone_break(errno, "pivot root\n");
  }
}

static inline void
chdir_to_root()
{
  if (chdir("/") != 0)
  {
    stone_break(errno, "chdir to /\n");
  }
}

void
pivot_root_exec(int argc, char *argv[])
{
  if (argc > 1)
  {
    char cwd[1024];
    printf("# CWD: %s\n", getcwd(cwd, 1024));

    pivot_root(argv[0]);

    printf("# CWD: %s\n", getcwd(cwd, 1024));

    chdir_to_root();

    printf("# CWD: %s\n", getcwd(cwd, 1024));

    printf("PID %d\n", getpid());
    stone_continue(argc - 1, argv + 1, "continue from pivot_root\n");
  }
  else
  {
    stone_break(0, "new root argument missing\n");
  }
}
