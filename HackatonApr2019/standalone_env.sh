#!/bin/bash

GCC_HOME_700=/cvmfs/cms.cern.ch/slc7_amd64_gcc700/external/gcc/7.0.0/

export PATH=$GCC_HOME_700/bin:$PATH
export LD_LIBRARY_PATH=$GCC_HOME_700/lib:$LD_LIBRARY_PATH
