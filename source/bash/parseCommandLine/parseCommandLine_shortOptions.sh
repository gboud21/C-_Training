#!/bin/bash

# Most Bash Scripts need to be able to process some set of command line options.
# Bash offers a built-in function named "getopts" that allows us to do so easily

# Syntax
# The syntax of getops is:
# getopts opstring opt [arg ....]
#   optstring
#       The supported options. The option expects an argument.
#   opt
#       Contains the parsed option. The argument is stored as a string in the
#       OPTARG variable.

# Example: 'abc:h' tells getopts that it can accept the options: 'a', 'b', 'c', or 'h'
# For options that require an argument, the ':' character follows the option to instruct
# getopts to expect an argument

# We create a while loop to process each of the options
while getopts 'abc:h' opt; do
    # Create a switch statement for executing the action associated with that option
    case "$opt" in
        a)
            echo "Processing option 'a'"
            ;;
        b)
            echo "Processing option 'b'"
            ;;
        # This option requires an argument
        c)
            echo "Processing option 'c' with '${OPTARG}' argument"
            ;;
        # In this option the '?' instructs getopts to handle any invalid options by using
        # this case
        ?|h)
            echo "Useage: $(basename $0) [-a] [-b] [-c arg]"
            ;;
            
    esac
done
shift "$((${OPTIND} -1))"