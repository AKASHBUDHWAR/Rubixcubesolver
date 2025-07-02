#include<bits/stdc++.h>
using namespace std;
#include "RubiksCube.h"
#include "DFSSolver.h"
#include "BFSSolver.h"
#include "IDDFSSolver.h"
#include "Rubikscube1dArray.cpp"
#include "RubiksCube3dArray.cpp"
#include "RubiksCubeBitboard.cpp"
int main() {
RubiksCube* cube=new RubikCube3dArray();
    RubikCube3dArray& cube1=dynamic_cast<RubikCube3dArray&>(*cube);
    cube->print();

vector<RubiksCube::MOVE> move=cube->randomShuffleCube(8);

    for (auto u:move) {
        cout<<cube->getMove(u)<<" ";

    };
    cube->print();
    DFSSolver<RubikCube3dArray,Hash3d> solver(cube1,20) ;
    vector<RubiksCube::MOVE> solution=solver.solve();
    for (auto u:solution) {
        cout<<cube->getMove(u)<<" ";
        cube->move(u);
    }
    cube->print();
    cout<<endl;

}