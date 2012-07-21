#! /usr/bin/env bash

# this is the qibuild toolchain you want to use
TOOLCHAIN=local_123

# enter modules here, in order of dependanciy
MODULES=(Kinematics)

PROJECT_ROOT=$(pwd)

for module in ${MODULES[@]}
do
    # enter the module directory
    cd $module

    # build and install
    qibuild configure -c $TOOLCHAIN --release
    qibuild make -c $TOOLCHAIN --release
    qibuild install -c $TOOLCHAIN --release .

    # go back to the project's root
    cd $PROJECT_ROOT
done
