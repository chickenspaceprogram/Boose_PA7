cmake_minimum_required(VERSION 3.15)
project(Boose_PA7 C)

set(CMAKE_C_STANDARD 11)

# adding `ctty`
add_subdirectory(../src/ctty ./ctty)



add_executable(Boose_PA7 
            ../src/main.c
            ../src/dealer.c
            ../src/dealer.h
            ../src/deck.c
            ../src/deck.h
            ../src/hand.c
            ../src/hand.h
            ../src/player.c
            ../src/player.h
            ../src/rand.c	
            ../src/rand.h
            ../src/poker.h
            ../src/poker.c)
target_link_libraries(Boose_PA7 ctty)
