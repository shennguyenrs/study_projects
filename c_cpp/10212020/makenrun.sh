#! /bin/bash
if [ -f "./$1" ]; then
    ./$1
else
    g++ ./$1.cpp -o $1
    ./$1
fi
