cmake_minimum_required(VERSION 3.31)
project(Rubixcubesolver)

set(CMAKE_CXX_STANDARD 20)

add_executable(Rubixcubesolver main.cpp
        RubiksCube.cpp
        RubiksCube.h
        RubiksCube3dArray.cpp
        Rubikscube1dArray.cpp
        RubiksCubeBitboard.cpp
        DFSSolver.h
        BFSSolver.h
        IDDFSSolver.h
        math.cpp
        math.h
        NibbleArray.cpp
        NibbleArray.h
        PatternDatabase.cpp
        PatternDatabase.h
        CornerPatternDatabase.cpp
        CornerPatternDatabase.h
        CornerDBMaker.cpp
        CornerDBMaker.h
        PermutationIndexer.h
        IDAstarSolver.h
)
