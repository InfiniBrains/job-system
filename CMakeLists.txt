cmake_minimum_required(VERSION 3.16.3)

project(INIFINI_JOBSYSTEM VERSION 0.0.1 LANGUAGES CXX)

option(INIFINI_JOBSYSTEM_NUM_THREADS_FIXED "IF SET, WILL FIX THE NUMBER OF ALLOCATED THREADS" OFF)
option(INIFINI_JOBSYSTEM_NUM_THREADS "IF NUM_THREADS_FIXED, IT WILL ALLOCATE THIS NUMBER OF THREADS" 0)

set(SOURCES
    ${SOURCES}
    src/LoopManager.cpp
    src/Work.cpp
    src/Thread.cpp
    )

set(HEADERS
    ${HEADERS}
    src/LoopManager.hpp
    src/Work.hpp
    src/Thread.hpp
    )

add_library(infini_jobsystem ${SOURCES} ${HEADERS} )

target_compile_features(infini_jobsystem PUBLIC cxx_std_20)

