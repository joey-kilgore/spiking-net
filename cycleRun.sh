#!/bin/sh

# build the project
make

# run the project which generates the data
./bin/cycle.exe

# run the analysis
Rscript ./analysis/plotVal.R ./data/cellCycle.csv 1 6
eog ./analysis/plot.png
Rscript ./analysis/plotVal.R ./data/synapsesCycle.csv 1 30
eog ./analysis/plot.png
Rscript ./analysis/plotVal.R ./data/firingCycle.csv 1 6
eog ./analysis/plot.png
