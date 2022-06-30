#!/bin/bash
# 
# File: run_xml.sh
# Author: Joao Pereira


# colours
RED='\033[1;31m'
GREEN='\033[1;32m'
BLUE='\033[1;34m'
NC='\033[0m'

# arguments received
inputdir=$1

path_to_l22_exec="../l22/l22"

# check if inputdir exists
if [ ! -d $inputdir ]; then 
	echo -e "${RED}Input directory (${inputdir}) directory choosen does not exist.${NC}"
	exit -1

# all conditions are verified. run the tests
else 
	echo -e "${GREEN}Running inputs...${NC}"
	for input in `ls -tr ${inputdir}/*.l22`; do
		echo -e "${BLUE}Input File: ${input}${NC}"
		#generate xml for each input file
        ${path_to_l22_exec} --target xml ${input}
	done

    echo -e "${RED}Tests with syntax errors: ${NC}"
    find -size 0
    echo -e "${RED}Number of tests with syntax errors: ${NC}"
    find -size 0 | wc -l
fi