#!/bin/bash

CMAKE_EXE=/opt/cmake/bin/cmake

function printSpacer
{
    echo "======================================================="
}

function printLine
{
    printf "${1}\n"
}

function printHelp
{
    printSpacer
    printLine "setup.sh <ARGUMENTS_HERE>"
    printLine ""
    printLine "Arguments:"
    printLine "\t-h | --help"
    printLine "\t\tPrints the help text."
    printLine "\t-c | --clean"
    printLine "\t\tCleans the project."
    printLine "\t-b APP_NAME_HERE | --build APP_NAME_HERE"
    printLine "\t\tBuilds the specified application."
}

function printError
{
    printSpacer
    echo "ERROR: ${1}"
    printSpacer
    exit ${2}
}

function clean
{
    echo "Cleaning"
}

function build
{
    echo "Building"
}

# Process the command line arguments
if [[ $# -eq 0 ]]; then
# Simple build with no arguments
    echo "Simple Build"
else
    VALID_ARGS=$(getopt -o hbc: --long help,build:,clean -- "$@")
    # This checks to see if the last command executed successfully
    if [[ $? -ne 0 ]]; then
        printError "Failed to create Valid Argument List." 1
    fi

    eval set -- "${VALID_ARGS}"
    while [ : ]; do
        case "${1}" in
            -h | --help)
                printHelp
                shift
                ;;
            -b | --build)
                echo "Building with ${2}"
                shift 2
                ;;
            -c | --clean)
                echo "Cleaning"
                shift
                ;;
            --)
                shift;
                break
                ;;
        esac
    done
fi