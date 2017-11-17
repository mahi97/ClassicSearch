cmake_minimum_required(VERSION 3.6)
project(Search_Project)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

include_directories(
        core
        problems
        search
)

add_library(${PROJECT_NAME}_core
        core/Problem.cpp core/Problem.h
        core/State.cpp core/State.h
        core/Search.cpp core/Search.h)

add_library(${PROJECT_NAME}_search
        search/SearchBFS.cpp search/SearchBFS.h
        search/SearchDFS.cpp search/SearchDFS.h
        search/searches.h search/SearchUCS.cpp search/SearchUCS.h search/SearchDFSL.cpp search/SearchDFSL.h search/SearchDFSX.cpp search/SearchDFSX.h search/SearchAStar.cpp search/SearchAStar.h search/SearchBidirect.cpp search/SearchBidirect.h)

add_library(${PROJECT_NAME}_problem
        problems/problems.h problems/ProblemWater.cpp problems/ProblemWater.h problems/ProblemPuzzle.cpp problems/ProblemPuzzle.h problems/ProblemNavigation.cpp problems/ProblemNavigation.h)

add_executable(Search_Project
        main.cpp ProblemSolver.cpp ProblemSolver.h)

target_link_libraries(${PROJECT_NAME}
        ${PROJECT_NAME}_search
        ${PROJECT_NAME}_core
        ${PROJECT_NAME}_problem)