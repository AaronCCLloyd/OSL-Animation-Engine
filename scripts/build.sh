#!/bin/sh

build() {
    mkdir build
    cd build
    cmake ../
    make all
    cd -
}

usage() {
    echo "usage: ./scripts/build.sh [-hbr]"
    echo "  -h      outputs this help message"
    echo "  -b      builds the OSL Animation Engine"
    echo "  -r      runs the OSL Animation Engine executable"
    exit 1
}

while getopts "brh" arg; do
    case "$arg" in
    h)
        usage
        ;;
    b)
        build
        ;;
    r)
        ./build/src/osl
        ;;
    *)
        echo "default"
        ;;
    esac
done
