#!/bin/bash

#REM: Global Constants
CLEAN=0
BUILD=0
BUILD_DIR="build"
SOURCE_DIR="."
CLI_APP_NAME="$(basename "$0")"

#REM: Argument Counter
ARGS=("$@")
ARG_COUNT=${#ARGS[@]}

#REM: Functions
display_help() {
    echo "::: Usage:"
    echo "    $CLI_APP_NAME --clean [<build-dir>]"
    echo "    $CLI_APP_NAME --build [<build-dir>]"
    echo "    $CLI_APP_NAME --clean --build [<build-dir>]"
    exit 0
}

error_invalid_args() {
    echo "::: Error: Invalid or unknown arguments: '${ARGS[*]}'"
    echo "::: Use '--help' for usage information."
    exit 1
}

parse_args() {
    while [[ $#REM: -gt 0 ]]; do
        case "$1" in
            --help)
                display_help
                ;;
            --clean)
                CLEAN=1
                ;;
            --build)
                BUILD=1
                ;;
            *)
                if [[ -z "$BUILD_DIR_SET" ]]; then
                    BUILD_DIR="$1"
                    BUILD_DIR_SET=1
                else
                    error_invalid_args
                fi
                ;;
        esac
        shift
    done
}

perform_clean() {
    if [[ -d "$BUILD_DIR" ]]; then
        echo "::: Cleaning build directory: '$BUILD_DIR'"
        rm -rf "$BUILD_DIR"
        if [[ $? -ne 0 ]]; then
            echo "::: Cleaning failed: Cannot delete '$BUILD_DIR'"
            exit 1
        fi
    else
        echo "::: Cleaning skipped: Build directory does not exist '$BUILD_DIR'"
    fi
}

perform_build() {
    echo "::: Configuring project in '$BUILD_DIR'"
    cmake -S "$SOURCE_DIR" -B "$BUILD_DIR"
    if [[ $? -ne 0 ]]; then
        echo "::: Configuration failed"
        exit 1
    fi

    echo "::: Building project in '$BUILD_DIR'"
    cmake --build "$BUILD_DIR"
    if [[ $? -ne 0 ]]; then
        echo "::: Build failed"
        exit 1
    fi
}

#REM: Main Script Logic
if [[ $ARG_COUNT -lt 1 || $ARG_COUNT -gt 3 ]]; then
    error_invalid_args
fi

parse_args "${ARGS[@]}"

if [[ $CLEAN -eq 0 && $BUILD -eq 0 ]]; then
    error_invalid_args
fi

[[ -z "$BUILD_DIR" ]] && BUILD_DIR="build"

if [[ $CLEAN -eq 1 ]]; then
    perform_clean
fi

if [[ $BUILD -eq 1 ]]; then
    perform_build
fi

echo "::: Operation completed successfully."
exit 0
