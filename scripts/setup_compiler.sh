#!/bin/sh

GCC_INCLUDE=$(i686-aleksa-gcc --print-file-name= || exit)

i686-aleksa-as "src/crt/crt0.s" -o "${GCC_INCLUDE}crt0.o"
i686-aleksa-as "src/crt/crti.s" -o "${GCC_INCLUDE}crti.o"
i686-aleksa-as "src/crt/crtn.s" -o "${GCC_INCLUDE}crtn.o"

touch "${GCC_INCLUDE}libc.a"
