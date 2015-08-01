// Copyright (c) 2015 OnlineTA.
//
// Sandstone Basic License - Version 3.0 - May 4, 2015.

// Execute a program contained in a new mount namespace. All mount points get
// blatanetly copied into the sandbox, and so all mount points below '/'
// (inside the sandbox) are also (recursively) marked as private.
//
// A private mark is the default, but someone might've made something shared on
// the host. A private mark means that mount events are neither propagated from
// host to sandbox, nor from sandbox to host. (See also
// Documentation/filesystems/sharedsubtree.txt.)
//
// This combo also has the added-in benefit that all things mounted within the
// sandbox will be automatically unmounted when the last (grand)child of this
// process terminates.
//
// This is equivalent to the following sequence of shell commands:
// $ unshare -m
// $ mount --make-rprivate /

#ifndef SANDSTONE_PRIVATE_MNTNS_H
#define SANDSTONE_PRIVATE_MNTNS_H

void
private_mntns_exec(int argc, char *const argv[]);

#endif // SANDSTONE_PRIVATE_MNTNS_H
