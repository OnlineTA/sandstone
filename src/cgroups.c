#include <errno.h>  // errno
#include <stddef.h> // NULL
#include <stdio.h>  // fpintf
#include <unistd.h> // pid_t, getpid

#include "ctrl-flow.h"
#include "cgroups.h"

void
attach_self_to_cgroup(const char *tasks_path)
{
  FILE *tasks_file;

  tasks_file = fopen(tasks_path, "ae"); // O_APPEND and O_CLOEXEC
  if (tasks_file == NULL)
  {
    stone_break(errno, "open cgroup tasks file");
  }

  if (fprintf(tasks_file, "%d", getpid()) != 1)
  {
    stone_break(0, "couldn't attach pid to cgroup");
  }

  if (fclose(tasks_file) != 0)
  {
    stone_break(errno, "close cgroup tasks file");
  }
}
