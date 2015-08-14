// Copyright (c) 2015 OnlineTA.
//
// Sandstone Basic License - Version 3.0 - May 4, 2015.

#include "mount-squashfs.h"

int
main(int argc, char *const argv[])
{
  mount_squashfs_exec(argc - 1, argv + 1);
  return 0;
}
