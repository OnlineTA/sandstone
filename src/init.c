#include "pivot-root.h"

#include <errno.h>      // errno
#include <sys/mount.h>  // umount
#include <unistd.h>     // setuid

#include <stdio.h>
#include <string.h>
#include <sys/wait.h>   // waitpid

#include "ctrl-flow.h"

#define NOBODY (99)

static inline void
umount_oldroot()
{
  pid_t pid;
  int status;

  printf("OLDROOT %s\n", OLDROOT);

  pid = fork();
  if (pid == 0)
  {
    execlp("umount", "-R", OLDROOT, NULL);
    printf("umount didn't fire! %s\n", strerror(errno));
  }
  else
  {
    pid = waitpid(pid, &status, 0);
    printf("DONE WAITING %d %d\n", pid, status);
  }

//  if (umount(OLDROOT) != 0)
//  {
//    stone_break(errno, "umount oldroot\n");
//  }
}

static inline void
setuid_nobody()
{
  if (setuid(NOBODY) != 0)
  {
    printf("PROBLEM %s\n", strerror(errno));
    stone_break(errno, "set real user id to nobody\n");
  }
}

int main(int argc, char *argv[])
{
  printf("HELLO THERE\n");
  printf("PID %d\n", getpid());

  char cwd[1024];
  getcwd(cwd, sizeof(cwd));
  printf("Working directory: %s\n", cwd);

  umount_oldroot();
  setuid_nobody();

  printf("CONTINUE\n");
  stone_continue(argc - 1, argv + 1, "continue from init\n");

  return 0;
}
