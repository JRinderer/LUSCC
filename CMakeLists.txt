cmake_minimum_required(VERSION 3.19)
project(LUSCC C)

set(CMAKE_C_STANDARD 11)

add_executable(LUSCC main.c global_defs.h scanner.c scanner.h universal_funcs.h)