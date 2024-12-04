#!/bin/sh

build() {
    mkdir build
    cd build
    cmake ../
    make all
    cd -
}

while getopts "br" arg; do
    case "$arg" in
    b)
        build
        ;;
    r)
        ./build/src/noreng
        ;;
    *)
        echo "default"
        ;;
    esac
done
