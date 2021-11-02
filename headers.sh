rm -rf sysroot/usr/include
mkdir -p sysroot/usr/include
cp /usr/lib/gcc/i686-elf/11.1.0/include/stdbool.h sysroot/usr/include
cp /usr/lib/gcc/i686-elf/11.1.0/include/stddef.h sysroot/usr/include
cp /usr/lib/gcc/i686-elf/11.1.0/include/stdint.h sysroot/usr/include/stdint.h
cp /usr/lib/gcc/i686-elf/11.1.0/include/stdint-gcc.h sysroot/usr/include/stdint-gcc.h
cp /usr/lib/gcc/i686-elf/11.1.0/include/stdarg.h sysroot/usr/include
cp -r src/include/* sysroot/usr/include
