#!/bin/sh

SYSROOT="/opt/aleksa"
SYSROOT_INCLUDE=$SYSROOT/usr/include/

mkdir -p "$SYSROOT_INCLUDE"
rsync src/include/ "$SYSROOT_INCLUDE" -ru --delete
