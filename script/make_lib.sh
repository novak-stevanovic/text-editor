#!/bin/bash

echo "[!] Processing lib: vector"
cd ../lib/vector
make clean
bear -- make
cd ../../script

echo "[!] Processing lib: termcontrol"
cd ../lib/termcontrol
make clean
bear -- make
cd ../..
