// Copyright (C) 2014 Kiy Avenue.
//
// Sandstone Basic License - Version 0.2 - June 16, 2014.

#ifndef SANDSTONE_FAIL_H
#define SANDSTONE_FAIL_H

#include <errno.h>      // errno
#include <error.h>      // error
#include <stdlib.h>     // EXIT_FAILURE

#define FAIL(msg) (error(EXIT_FAILURE, errno, (msg)))

// Note, the macro will fail if no msg argument is passed, or if the passed
// msg is not a C string.

#endif // SANDSTONE_FAIL_H
