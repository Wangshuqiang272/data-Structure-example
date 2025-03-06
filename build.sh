#!/usr/bin/bash

if [ "whole" = "$1" ]
then
cmake -B ./build
cd build/
make
cd ..
else
cd build
make
fi


