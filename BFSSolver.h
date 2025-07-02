//
// Created by akash on 14/6/25.
//

#ifndef BFSSOLVER_H
#define BFSSOLVER_H
#include "RubiksCube.h"
#include<bits/stdc++.h>

template<typename T,typename H>
class BFSSolver {

private:
    vector <RubiksCube::MOVE> moves;
    int max_search_depth;
    unordered_map<T,bool,H> visited;
    unordered_map<T,RubiksCube::MOVE,H> moved;

    T bfs() {
        queue<T> q;
        q.push(rubiksCube);
        visited[rubiksCube]=true;
        while (!q.empty()) {
            T curr = q.front();
            q.pop();
           if (curr.isSolved()) {
               return curr;
           }
            for(int i=0;i<18;i++) {
                T temp=dynamic_cast<T&>(curr.move(RubiksCube::MOVE(i)));
                if(!visited[temp]) {
                    visited[temp]=true;
                    q.push(temp);
                    moved[temp]=RubiksCube::MOVE(i);
                }
            }


        }
        return rubiksCube;
    }

public:
    T rubiksCube;
    BFSSolver(T _rubiksCube) {
        rubiksCube = _rubiksCube;

    }

    vector<RubiksCube::MOVE> solve() {
      T temp_cube= bfs();
        assert(temp_cube.isSolved());
        T solved_cube=temp_cube;
        while(temp_cube != rubiksCube) {
            RubiksCube::MOVE curr_move = moved[temp_cube];
            moves.push_back(curr_move);
            temp_cube.invert(curr_move);
        }
        rubiksCube = solved_cube;
        reverse(moves.begin(),moves.end());
        return moves;
        return moves;
    }

};
#endif //BFSSOLVER_H
