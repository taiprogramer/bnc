#!/bin/sh

prog_name=$1

make prog=$prog_name

./$prog_name

rm -rf $prog_name
