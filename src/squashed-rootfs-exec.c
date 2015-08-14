// Copyright (C) 2015 OnlineTA.
//
// Sandstone Basic License - Version 3.0 - May 4, 2015.

// mntns-exec
//
// Execute a program contained in a mount namespace. Largely equivalent to
// unshare -m, but no reliance on a preexisting shell.
//
// Note, we use libmount to get (the rather intricate) squashfs mount/umount
// procedure for free.

#include <libmount/libmount.h>

#include "ctrl-flow.h"  // stone_break, stone_continue

void
mount_squashfs(const char *source)
{
  struct libmnt_context *cxt;

  cxt = mnt_new_context();
  if (!cxt)
  {
    stone_break("libmount couldn't allocate new context");
  }

  if (mnt_context_set_options(cxt, "ro") != 0)
  {
    stone_break("couldn't append readonly option");
  }

  if (mnt_context_set_fstype(cxt, "squashfs") != 0)
  {
    stone_break("couldn't set fs type to squashfs");
  }

  if (mnt_context_set_source(cxt, source) != 0)
  {
    stone_break("couldn't set source");
  }

  if (mnt_context_set_target(cxt, "rootfs") != 0)
  {
    stone_break("couldn't set target");
  }

  if (mnt_context_mount(cxt) != 0)
  {
    stone_break("couldn't mount squashfs");
  }
}

int
main(int argc, char *argv[])
{
  const char *source;

  if (argc < 2)
  {
    stone_break("Expecting a squashfs path!");
  }

  source = argv[1];

  mount_squashfs(source);

  stone_continue("execvp", argc - 1, argv + 1);
}
