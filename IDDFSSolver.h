//
// Created by akash on 15/6/25.
//

#ifndef IDDFSSOLVER_H
#define IDDFSSOLVER_H
#include <bits/stdc++.h>
#include"RubiksCube.h"
#include"DFSSolver.h"
template <typename T,typename H>
class IDDFSSolver {
private:
    int max_search_depth;
    vector<RubiksCube::MOVE> moves;

public:
    T rubikscube;
    IDDFSSolver(T _rubikscube,int _max_depth_search) {
        rubikscube=_rubikscube;
        max_search_depth=_max_depth_search;
    }


    vector<RubiksCube::MOVE> solve() {
    for (int i=1;i<=max_search_depth;i++) {
        DFSSolver<T,H> dfsSolver(rubikscube,max_search_depth);
        moves=  dfsSolver.solve();
        if (dfsSolver.rubiksCube.isSolved()) {
            rubikscube= dfsSolver.rubiksCube;
            break;
        }
    }
        return moves;

    }




};

#endif //IDDFSSOLVER_H
