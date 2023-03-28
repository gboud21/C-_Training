#!/bin/bash

CURRENT_DIR=$(dirname ${0})

DOXYGEN_EXE=doxygen

DOXYGEN_CFG=${CURRENT_DIR}/../Doxyfile

cd ${CURRENT_DIR}../
${DOXYGEN_EXE} ${DOXYGEN_CFG}
