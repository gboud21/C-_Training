#!/bin/bash

CURRENT_DIR=$(dirname "${0}")
APP_NAME="FileIO"
APP=${CURRENT_DIR}/../build/app/${APP_NAME}

# --- Script Returns
RETURN_SUCCESS=0
RETURN_UNKNOWN_RETURN=1
RETURN_APP_NOT_FOUND=2

# --- Prints a spacer for terminal output
function printSpacer {
    echo "================================================================"
}

# --- Prints the formated data for a parameter
function printParameter {
    echo "    ${1}"
    echo "        ${2}"
}

# --- Prints the help text for the script
function printHelp {
    printSpacer
    echo "Script: compile.sh"
    echo "Parameters:"
    printParameter "-h --help:" "Prints the help Script"
    printParameter "-c --clean" "Deletes the binaries from the previous build"
    printParameter "-d --debug" "Prints Debug Statements"
    printSpacer
}

# --- Prints the debug message to the terminal
function printDebug {
    if [ ${SHOULD_DEBUG} -eq 1 ]; then
        echo "${1}"
    fi
}
# --- Prints the output message to the terminal and exits the script
function exitScript {
    printSpacer
    printDebug "exitScript ${1}"
    case "${1}" in
    ${RETURN_SUCCESS})
        echo "Script Completed Successfully"
        ;;
    ${RETURN_UNKNOWN_RETURN})
        echo "Error: INVALID Return Type"
        ;;
    ${RETURN_APP_NOT_FOUND})
        echo "Failed to initialize script parameters"
        ;;
    *)
        printReturn ${RETURN_UNKNOWN_RETURN}
        ;;
    esac

    printSpacer
    exit ${1}
}

function run {
    if [ ! -f "${APP}" ]; then
        exitScript ${RETURN_APP_NOT_FOUND}
    fi

    ${APP}
}

function main {
    run
}

main
