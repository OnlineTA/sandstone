#include "private-mntns.h"

int
main(int argc, char *const argv[])
{
  private_mntns_exec(argc - 1, argv + 1);
  return 0;
}
