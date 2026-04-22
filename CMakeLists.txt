cmake_minimum_required(VERSION 4.2)
project(HashTable C)

set(CMAKE_C_STANDARD 23)

add_executable(HashTable main.c
        hash_table.h
        hash_table.c)
