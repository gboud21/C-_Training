#!/bin/bash

CURRENT_DIR=$(dirname ${0})

DOXYGEN_EXE=doxygen

DOXYGEN_CFG=${CURRENT_DIR}/../doc/doxygen/CPlusPlus_Training.cfg

${DOXYGEN_EXE} ${DOXYGEN_CFG}
