#!/bin/bash

echo "CURR DIR:"
pwd
echo "Processing lib: vector"
cd ../lib/vector
make clean
bear -- make
cd ../../script

echo "CURR DIR:"
pwd
pwd
pwd
echo "Processing lib: termutil"
cd ../lib/termutil
make clean
bear -- make
cd ../..

echo "CURR DIR:"
pwd
