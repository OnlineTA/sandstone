// Copyright (c) 2015 OnlineTA.
//
// Sandstone Basic License - Version 3.0 - May 4, 2015.

#include "ctrl-flow.h"

#define _GNU_SOURCE     // execvpe

#include <error.h>      // error
#include <stdarg.h>     // va_list, va_start, va_end
#include <syslog.h>     // vsyslog, LOG_*
#include <stdlib.h>     // exit, EXIT_*
#include <string.h>     // strerror
#include <unistd.h>     // execvpe

static void
log_error(int errnum, const char *format, va_list arglist)
{
  vsyslog(LOG_USER | LOG_ERR, format, arglist);

  if (errnum != 0) {
    syslog(LOG_USER | LOG_ERR, "%s", strerror(errnum));
  }
}

void
stone_break(int errnum, const char *format, ...)
{
  va_list arglist;

  va_start(arglist, format);
  log_error(errnum, format, arglist);
  va_end(arglist);
  exit(EXIT_FAILURE);
}

inline void
stone_continue(int argc, char *const argv[], const char *format, ...)
{
  va_list arglist;

  if (argc > 1)
  {
    execvp(argv[1], argv + 1, NULL);

    // Setting envp (last argument of execvpe) to NULL results in execvpe
    // deriving a default PATH environment variable. From the documentation it
    // seems that this should be something like the result of confstr(_CS_PATH,
    // ...), but it doesn't seem that way. Anyhow, it cleans the environment.

    va_start(arglist, format);
    log_error(0, format, arglist);
    va_end(arglist);
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
