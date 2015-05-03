// Copyright (C) 2015 OnlineTA.
//
// Sandstone Basic License - Version 3.0 - May 4, 2015.

// mntns-exec
//
// Execute a program contained in a new mount namespace, with all mounts below
// / marked as private. Private is default, but someone might've made something
// shared. This means that new mounts are neither propagated from host to
// sandbox, nor from sandbox to host.
//
// This is equivalent to the following shell command:
// $ unshare -m mount --make-rprivate /
//
// See also Documentation/filesystems/sharedsubtree.txt.

#define _GNU_SOURCE     // Necessary to get CLONE_NEWNS from <sched.h>.
#include <sched.h>      // CLONE_NEWNS
#include <sys/mount.h>  // mount, MS_REC, MS_PRIVATE

#include "ctrl-flow.h"  // stone_break, stone_continue

static inline void
unshare_mntns()
{
  if (unshare(CLONE_NEWNS) == -1)
  {
    stone_break("unshare mntns");
  }
}

static inline void
mark_root_rprivate()
{
  if (mount("none", "/", NULL, MS_REC | MS_PRIVATE, NULL) == -1)
  {
    stone_break("mark root rprivate");
  }
}

int
main(int argc, char *argv[])
{
  unshare_mntns();
  mark_root_rprivate();

  stone_continue("continue", argc, argv);
}
