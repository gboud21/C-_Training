#!/bin/bash

CMAKE_EXE=/opt/cmake/bin/cmake
CURRENT_DIR=$(basedir)
BUILD_DIR=${CURRENT_DIR}/../build/
SOURCE_DIR=${CURRENT_DIR}/../src/

function generateCMake
{
    ${CMAKE_EXE} -S ${SOURCE_DIR} -B ${BUILD_DIR}
}

function build
{

}

function clean
{
    
}