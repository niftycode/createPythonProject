cmake_minimum_required(VERSION 3.28.6)
project(createPythonProject C)

set(CMAKE_C_STANDARD 23)

set(OPENSSL_ROOT_DIR "/opt/homebrew/opt/openssl@3")
set(OPENSSL_INCLUDE_DIR "${OPENSSL_ROOT_DIR}/include")
set(OPENSSL_LIB_DIR "${OPENSSL_ROOT_DIR}/lib")

include_directories(${OPENSSL_INCLUDE_DIR})
link_directories(${OPENSSL_LIB_DIR})

add_executable(createPythonProject main.c
        createFiles.h
        createFiles.c
        createFolders.c
        createFolders.h
)
