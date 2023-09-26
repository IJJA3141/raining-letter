cmake_minimum_required(VERSION 3.25.1)
project(Raining-Letters)

set(SOURCE_FILES
    ./src/main.cpp
    ./src/loader/loader.cpp
    ./src/matrix/matrix.cpp
   )

add_compile_definitions("DEBUG=$<CONFIG:Debug>")
ADD_EXECUTABLE(Raining-Letters ${SOURCE_FILES})
