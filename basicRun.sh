#!/bin/sh

# build the project
make

# run the project which generates data
./bin/main.exe

# run the analysis
cd analysis
Rscript plotOverTime.R
eog cell.png
