#!/usr/bin/env bash

set -e

BUILD_TYPE="Release"
BUILD_DIR="build"

rm -rf "$BUILD_DIR"
mkdir -p "$BUILD_DIR"
cd "$BUILD_DIR"

cmake .. -G Ninja \
    -DCMAKE_BUILD_TYPE="$BUILD_TYPE" \
    -DBUILD_TESTING=OFF

cmake --build . --config $BUILD_TYPE -- -j"$(nproc)"
cmake --install . --config $BUILD_TYPE --prefix=$(pwd)/../install
