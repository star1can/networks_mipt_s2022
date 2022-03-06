#!/usr/bin/env bash

python3 ../utility/parser.py "../inputs/input2"
mkdir build
cd build
cmake .. > /dev/null
make > /dev/null
./task2 "../../inputs/parsed_input"
cd ..
rm -r build
rm "../inputs/parsed_input"