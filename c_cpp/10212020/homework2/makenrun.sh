#! /bin/bash

# Generate output file
g++ $1.cpp $2.cpp  -o $1

# Update tags file
ctags --recurse=yes --exclude=$1 --exclude=README.md

# Open file
if [ -f "./$1" ]; then
    ./$1
fi
