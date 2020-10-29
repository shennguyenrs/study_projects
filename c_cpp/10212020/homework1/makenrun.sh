#! /bin/bash

g++ $1.cpp $2.cpp  -o $1

if [ -f "./$1" ]; then
    ./$1
fi
