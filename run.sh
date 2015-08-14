#!/bin/bash

TESTFS=$1

ERROR_INVALID_ARGS=1

if [ -z "$TESTFS" ] ; then
  echo "Usage: $0 <testfs>"
  exit $ERROR_INVALID_ARGS
fi

cp ./bin/init "${TESTFS}/bin/"

rm squashfs
mksquashfs "${TESTFS}" squashfs
cd bin

echo "GOGOGO"
sudo ./private-mntns \
  ./mount-squashfs ../squashfs ../rootfs/ \
  ./pivot-root ../rootfs \
  init ls
