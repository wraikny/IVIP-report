#!/bin/bash

target_file="ivip"

print_usage() {
    echo 'Usage:'
    echo "    $0 option"
    echo '    init: Initialize with CMake'
    echo '    build: Build target'
    echo '    run [-f]: Execute target'
}

working_dir=`dirname $0`

if [ $# = 0 ]; then
    print_usage

elif [ $1 = "init" ]; then

    echo "$0 init"

    if [ ! -d "build" ]; then
    mkdir build
    fi

    cd build
    cmake ..

elif [ $1 = "build" ]; then

    if [ ! -d "build" ] || [ ! -f "build/Makefile" ]; then
        $0 init
    fi
    
    echo "$0 build"
    cd build
    make

elif [ $1 = "run" ]; then

    if [ ! -f "build/$target_file" ] || [ $# -gt 1 -a $2 = "-f" ]; then
    $0 build
    fi

    echo "$0 run"
    ./build/ivip

elif [ $1 = "report" ]; then
    cd report
    make

else
    print_usage

fi

working_dir=`dirname $0`
