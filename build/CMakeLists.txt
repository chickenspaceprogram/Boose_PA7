cmake_minimum_required(VERSION 3.15)
project(Boose_PA7 C)

set(CMAKE_C_STANDARD 11)

# adding `ctty`
add_subdirectory(../src/ctty ./ctty)

# adding `poker` library
set(POKER_SRCS ../src/poker.h ../src/pokerc)
add_library(poker ${POKER_SRCS});


add_executable(Boose_PA7 ../src/main.c)
target_link_libraries(Boose_PA7 ctty poker)
