#!/bin/sh

# https://terminalroot.com.br/assets/img/gnu/gnu-autotools-1.png

# configure.ac
autoscan

# aclocal.m4
aclocal

# config.h.in
autoheader

# configure
autoconf

# Makefile.in
automake --add-missing
