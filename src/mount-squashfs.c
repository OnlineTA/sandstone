// Copyright (c) 2015 OnlineTA.
//
// Sandstone Basic License - Version 3.0 - May 4, 2015.

#include "mount-squashfs.h"

#include <errno.h>                // errno
#include <libmount/libmount.h>    // mnt_*

#include "ctrl-flow.h"

void
mount_squashfs(const char *volume, const char *mntpnt)
{
  struct libmnt_context *cxt;
  int mnt_retval;

  cxt = mnt_new_context();

  if (mnt_context_set_source(cxt, volume) != 0)
  {
    stone_break(errno, "set given volume as squashfs mount source");
  }

  if (mnt_context_set_target(cxt, mntpnt) != 0)
  {
    stone_break(errno, "set given mntpnt as squashfs mount target");
  }

  if (mnt_context_set_fstype(cxt, "squashfs") != 0)
  {
    stone_break(errno, "set squashfs fs type on mount");
  }

  if (mnt_context_set_options(cxt, "loop") != 0)
  {
    stone_break(errno, "set loopback device option for squashfs mount");
  }

  mnt_retval = mnt_context_mount(cxt);

  if (mnt_retval != 0)
  {
    stone_break(mnt_retval, "mount squashfs");
  }

  mnt_free_context(cxt);
}

void
mount_squashfs_exec(int argc, char *const argv[])
{
  const char *volume, *mntpnt;

  volume = NULL;
  mntpnt = NULL;

  if (argc > 1)
  {
    volume = argv[0];
    mntpnt = argv[1];

    mount_squashfs(volume, mntpnt);

    stone_continue(argc - 2, argv + 2, "continue from mount_squashfs");
  } else if (argc == 1) {
    stone_break(0, "squashfs mntpnt argument missing");
  } else {
    stone_break(0, "squashfs volume and mntpoint argument missing");
  }
}
