#!/bin/sh
cols=`tput cols` # Get the current terminal width
i=0
# Print - till the end of line
while [ $i -lt $cols ]; do echo -n "-"; i=`expr $i + 1`; done; echo
# Clean older files and compile, exit if there is an error
mkdir -p ./bin ./out
make clean || true;
make all || exit;
# Print - till the end of line
i=0
while [ $i -lt $cols ]; do echo -n "-"; i=`expr $i + 1`; done; echo
# Print a system message
echo "\n\n\e[1mFiles has been compiled successfully. \n\e[0mMove to \e[1m\e[92m./bin\e[39m\e[0m to execute them"
