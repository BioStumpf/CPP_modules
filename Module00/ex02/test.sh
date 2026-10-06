#!/bin/bash

##compile binary
make

diff <(cat output_to_compare.log | awk '{print $2}') <(./account | awk '{print $2}') && echo "Equal"
