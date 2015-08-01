// Copyright (c) 2015 OnlineTA.
//
// Sandstone Basic License - Version 3.0 - May 4, 2015.

#ifndef SANDSTONE_CTRL_FLOW_H
#define SANDSTONE_CTRL_FLOW_H

void
stone_break(int errnum, const char *format, ...);

void
stone_continue(int argc, char *const argv[], const char *format, ...);

#endif // SANDSTONE_CTRL_FLOW_H
