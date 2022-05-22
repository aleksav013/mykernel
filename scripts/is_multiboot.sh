#!/bin/sh

BINARY=./build/aleksa-os.bin

if [ -f ${BINARY} ]; then
    grub-file --is-x86-multiboot ${BINARY}
    echo $?
else
    echo 1
fi
