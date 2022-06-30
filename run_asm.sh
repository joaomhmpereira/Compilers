#!/bin/bash
# 
# File: run_asm.sh
# Authors: Joao Pereira and Manuel Brito


# colours
RED='\033[1;31m'
GREEN='\033[1;32m'
BLUE='\033[1;34m'
NC='\033[0m'

# arguments received
inputdir=$1

# counter
counter=0

path_to_l22_exec="../l22/l22"

# check if inputdir exists
if [ ! -d $inputdir ]; then 
	echo -e "${RED}Input directory (${inputdir}) directory choosen does not exist.${NC}"
	exit -1

# all conditions are verified. run the tests
else
	rm ${inputdir}/*.asm
	echo -e "${GREEN}Running inputs...${NC}"
	for input in `ls -tr ${inputdir}/*.l22`; do
		echo -e "${BLUE}Input File: ${input}${NC}"
        ${path_to_l22_exec} -g --target asm ${input}
		filename=$(basename -- "$input")
		extension="${filename##*.}"
		filename="${filename%.*}"
		# echo basename(${input}).asm
		yasm -felf32 -g dwarf2 ${inputdir}/${filename}.asm
		ld -melf_i386 -o main ${filename}.o ../demo/librts5-202103031636/file.o   ../demo/librts5-202103031636/integer.o  ../demo/librts5-202103031636/lib32.o ../demo/librts5-202103031636/float.o  ../demo/librts5-202103031636/kernel.o   ../demo/librts5-202103031636/string.o

		./main > ${filename}.output
		DIFF=$(diff <( tr -d ' \n' <${filename}.output ) <( tr -d ' \n' <${inputdir}/expected/${filename}.out))
		
		if [ "$DIFF" ]; then
			echo -e "${RED}Test failed. Output differs from expected.${NC}"
			diff <( tr -d ' \n' <${filename}.output ) <( tr -d ' \n' <${inputdir}/expected/${filename}.out)
			((counter++))
		else
			echo -e "${GREEN}Test passed!${NC}"
		fi
		rm *.o *.output
	done
	echo -e "${RED}${counter} tests failed out of 131 tests. ${NC}"
fi