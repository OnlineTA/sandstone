// Copyright (c) 2015 OnlineTA.
//
// Sandstone Basic License - Version 3.0 - May 4, 2015.

#include "ctrl-flow.h"

#define _GNU_SOURCE     // execvpe

#include <stdarg.h>     // va_list, va_start, va_end
//#include <syslog.h>     // vsyslog, LOG_*
#include <stdlib.h>     // exit, EXIT_*
#include <string.h>     // strerror
#include <unistd.h>     // execvpe

#include <sys/stat.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

static void
log_error(int errnum, const char *format, va_list arglist)
{
  vfprintf(stderr, format, arglist);
//  vsyslog(LOG_USER | LOG_ERR, format, arglist);

  if (errnum != 0) {
    fprintf(stderr, "%s\n", strerror(errnum));
//    syslog(LOG_USER | LOG_ERR, "%s", strerror(errnum));
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

  if (argc > 0)
  {
    char cwd[1024];
    printf("CWD: %s\n", getcwd(cwd, 1024));

    execvpe(*argv, argv, NULL);

    // Setting envp (last argument of execvpe) to NULL results in execvpe
    // deriving a default PATH environment variable. From the documentation it
    // seems that this should be something like the result of confstr(_CS_PATH,
    // ...), but it doesn't seem that way. Anyhow, it cleans the environment.

    printf("HMMM %s %s\n", *argv, strerror(errno));

    struct stat info;
    if(lstat("/lib64/",&info) != 0) {
      printf("Doesn't exist\n");
    } else {
      printf("Exists\n");
    }

    va_start(arglist, format);
    log_error(0, format, arglist);
    va_end(arglist);
    exit(EXIT_FAILURE);
  }

  exit(EXIT_SUCCESS);
}
