#!/usr/bin/env bash

python3 ../utility/parser.py "../inputs/input1" > /dev/null
mkdir build
cd build
cmake .. > /dev/null
make > /dev/null
./task1 "../../inputs/parsed_input"
cd ..
rm -r build
rm "../inputs/parsed_input"