#!/bin/sh

# Usage: ./run [PROGRAM_NAME_WITHOUT_EXTENSION]
# Example: ./run example/hello_bnc

die() {
    echo $1
    exit
}

prog_name=$1
test `echo $1 | grep '\.c$'` && die 'Program name need to have no extension.'
test -f "$prog_name".c || die 'File not found'

make prog=$prog_name 
./$prog_name
rm -rf $prog_name

