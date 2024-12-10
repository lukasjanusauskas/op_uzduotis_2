#!/usr/bin/env bash
cd build
cmake ..
make
cd ..

test() {
  ./build/main
}

run() {
  ./build/main --no-run
}

while getopts 'rt' OPTION; do
 case "$OPTION" in 
  r) run
    ;;
  t) test
    ;;
  esac
done