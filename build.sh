#!/usr/bin/bash

if [ "whole" = "$1" ]
then
cmake -B ./build
cd build/
make
cd ..
echo "1"
else
cd build
make
echo "2"
fi


