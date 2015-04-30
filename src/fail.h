// Copyright (C) 2014 Kiy Avenue.
//
// Sandstone Basic License - Version 0.2 - June 16, 2014.

#ifndef SANDSTONE_ERROR_H
#define SANDSTONE_ERROR_H

#include <errno.h>  // errno
#include <libgen.h> // basename
#include <stdio.h>  // fprintf, stderr
#include <string.h> // strerror

#define ERROR_REPORT(msg) (fprintf(stderr, "%s:%d: %s - %s.\n", \
  basename(__FILE__), __LINE__, (msg), strerror(errno)))

// Note, the macro will fail if no msg argument is passed, or if the passed
// msg is not a C string.

#endif // SANDSTONE_ERROR_H
