#!/bin/bash

# This example builds off of the parseCommandLine_shortOptions.sh
# Bash's getopts function is only able to process single character options.
# However, in some cases we want to process command line arguments that are longer than
# a single character. To do so we will use GNU's getopt command to parse the longer version

# In this example we will process the following pairs of arguments:
# a --alpha
# b --bravo
# c --charlie
# h --help

# To do so we will create a variable that contains the valid arguments
VALID_ARGS=$(getopt -o abc:h --long alpha,bravo,charlie:,help -- "$@")

# This checks to see if the number of arguments is not 0. If it is then it will exit
# the program with a status of 1
if [[ $? -ne 0 ]]; then
    exit 1
fi

eval set -- "${VALID_ARGS}"
# We create a while loop to process each of the options
while [ : ]; do
    # Create a switch statement for executing the action associated with that option
    case "${1}" in
        -a | --alpha)
            echo "Processing option 'a'"
            shift
            ;;
        -b | --bravo)
            echo "Processing option 'b'"
            shift
            ;;
        # This option requires an argument
        -c | --charlie)
            echo "Processing option 'c' with '${2}' argument"
            shift 2
            ;;
        -h | --help)
            echo "Useage: $(basename $0) [-a] [-b] [-c arg]"
            shift
            ;;
        --)
            shift;
            break
            ;;
            
    esac
done