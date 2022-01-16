#!/bin/sh

SYSROOT="/opt/aleksa"
SYSROOT_INCLUDE=$SYSROOT/usr/include/

rsync src/include/ "$SYSROOT_INCLUDE" -ru --delete
