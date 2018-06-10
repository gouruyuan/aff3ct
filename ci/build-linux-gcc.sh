#!/bin/bash
set -x

source ci/threads.sh

mkdir build
cd build
cmake .. -G"Unix Makefiles" -DCMAKE_CXX_COMPILER=g++ -DCMAKE_BUILD_TYPE=Release -DENABLE_GSL=ON -DCMAKE_CXX_FLAGS="-Wall -funroll-loops -march=native -DMULTI_PREC"
make -j $THREADS

./bin/aff3ct --version
./bin/aff3ct -C POLAR -m 1.0 -M 3.5 -s 0.25 -K 1755 -N 2048 --crc-poly 32-GZIP --dec-type ASCL -t $THREADS --ter-freq 0