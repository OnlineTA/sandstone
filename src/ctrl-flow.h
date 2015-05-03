// Copyright (C) 2015 OnlineTA.
//
// Sandstone Basic License - Version 0.2 - June 16, 2014.

#ifndef SANDSTONE_CTRL_FLOW_H
#define SANDSTONE_CTRL_FLOW_H

#include <errno.h>      // errno
#include <error.h>      // error
#include <stdlib.h>     // exit, EXIT_FAILURE, EXIT_SUCCESS
#include <unistd.h>     // execvp

static inline void
stone_break(const char *msg)
{
  error(EXIT_FAILURE, errno, msg);
}

static inline void
stone_continue(const char *fail_msg, int argc, char *argv[])
{
  if (argc > 1)
  {
    execvp(argv[1], argv + 1);

    stone_break(fail_msg);
  }

  exit(EXIT_SUCCESS);
}

#endif // SANDSTONE_CTRL_FLOW_H
