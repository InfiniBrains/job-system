cmake_minimum_required(VERSION 3.16.3)

project(INIFINI_JOBSYSTEM VERSION 0.0.1 LANGUAGES CXX)

option(INIFINI_JOBSYSTEM_NUM_THREADS_FIXED "IF SET, WILL FIX THE NUMBER OF ALLOCATED THREADS" OFF)
option(INIFINI_JOBSYSTEM_NUM_THREADS "IF NUM_THREADS_FIXED, IT WILL ALLOCATE THIS NUMBER OF THREADS" 0)
option(ENABLE_TESTS "ENABLE AND RUN TESTS" 0)

find_package (Threads)

set(SOURCES
    ${SOURCES}
    src/LoopManager.cpp
    src/Work.cpp
    src/ThreadWorker.cpp
    )

set(HEADERS
    ${HEADERS}
    src/LoopManager.hpp
    src/Work.hpp
    src/ThreadWorker.hpp
    )

add_library(infini_jobsystem ${SOURCES} ${HEADERS} )

target_link_libraries (infini_jobsystem Threads::Threads)

target_compile_features(infini_jobsystem PUBLIC cxx_std_20)

IF(ENABLE_TESTS)
  SET(SOURCES
      ${SOURCES}
      tests/main.cpp
      )
  add_executable(infini_jobsystem_test ${SOURCES} ${HEADERS} )
  target_link_libraries (infini_jobsystem_test Threads::Threads)
ENDIF()


