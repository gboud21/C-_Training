#!/usr/bin/python

# External Imports
import os
import sys
import pathlib

# Internal Imports
import constants

#######################################################################################################################
### This function prints an error to the user with an example of how to execute the script
def printHelp():
    print("Invalid Input Parameter count.")
    print("Example: python leetGen.py PATH_TO_JSON PATH_TO_OUTPUT")
    print("Example: python leetGen.py ../json/objects/leet338.json ../src/")

#######################################################################################################################
### Main Function
def main(jsonPath : str, outputPath : str):
    # 
    pass

if __name__ == "__main__":
    # Need to read in input parameters
    # 1) Path to Leet Code JSON to generate
    # 2) Path to output location
    if sys.argv.__len__() != 3:
        printHelp()
    else:
        main()