//
// Created by akash on 11/6/25.
#include "RubiksCube.h"
class  RubikCube3dArray :public RubiksCube {
private:
    void rotateface(int id) {
        char tmp[3][3]={};
        for(int i=0;i<3;i++) {
            for(int j=0;j<3;j++) {
                tmp[i][j]=this->cube[id][i][j];
            }
        }
        for(int i=0;i<3;i++) cube[id][i][0]=tmp[2][i];
        for(int i=0;i<3;i++) cube[id][i][1]=tmp[1][i];
        for(int i=0;i<3;i++) cube[id][i][2]=tmp[0][i];
    }
    //IF U FIND ANY DIFFICULTY FOR THIS VERSION THEN TRY CHANGING ROTATE FACE

public:
    char cube[6][3][3]{};
    RubikCube3dArray() {
        for (int i=0;i<6;i++) {
            for (int j=0;j<3;j++) {
                for (int k=0;k<3;k++) {
                    cube[i][j][k]=getColorLetter(static_cast<COLOR>(i));
                }
            }
        }
    }
    COLOR getColor(FACE face, unsigned row, unsigned col) const override {
        char c= cube[(int)face][row][col];
        switch (c) {
            case 'G':return COLOR::GREEN;
            case 'R':return COLOR::RED;
            case 'B':return COLOR::BLUE;
            case 'Y':return COLOR::YELLOW;
            case 'W':return COLOR::WHITE;
            case 'O':return COLOR::ORANGE;
        }
    }
    bool isSolved() const override {
        for (int i=0;i<6;i++) {
            for (int j=0;j<3;j++) {
                for (int k=0;k<3;k++) {
                    if (this->cube[i][j][k]!=getColorLetter(static_cast<COLOR>(i))) return false;;
                }
            }
        }
        return true;
    }
    RubiksCube &u() override {
        this->rotateface(0);
        char tmp[3]={};
        for(int i=0;i<3;i++) tmp[i]=cube[1][0][i];
        for(int i=0;i<3;i++) cube[1][0][i]=cube[2][0][i];
        for(int i=0;i<3;i++) cube[2][0][i]=cube[3][0][i];
        for(int i=0;i<3;i++) cube[3][0][i]=cube[4][0][i];
        for(int i=0;i<3;i++) cube[4][0][i]=tmp[i];
        return *this;

    }
    RubiksCube &uPrime() override{
        this->u();
        this->u();
        this->u();
        return *this;
    }
    RubiksCube &u2() override{
        this->u();
        this->u();
        return *this;
    }

    RubiksCube &l() override {
        this->rotateface(1);
        char tmp[3]={};
        for(int i=0;i<3;i++) tmp[i]=cube[4][2-i][2];
        for(int i=0;i<3;i++) cube[4][2-i][0]=cube[5][i][0];
        for(int i=0;i<3;i++) cube[5][i][0]=cube[2][i][0];
        for(int i=0;i<3;i++) cube[2][i][0]=cube[0][i][0];
        for(int i=0;i<3;i++) cube[0][i][0]=tmp[i];
        return *this;
    }
    RubiksCube &lPrime() override{
        this->l();
        this->l();
        this->l();
        return *this;
    }
    RubiksCube &l2() override{
        this->l();
        this->l();
        return *this;
    }
    RubiksCube &r() override {
        this->rotateface(3);
        char tmp[3]={};
        for(int i=0;i<3;i++) tmp[i]=cube[4][i][0];
        for(int i=0;i<3;i++) cube[4][i][0]=cube[0][2-i][2];
        for(int i=0;i<3;i++) cube[0][2-i][2]=cube[2][2-i][2];
        for(int i=0;i<3;i++) cube[2][2-i][2]=cube[5][2-i][2];
        for(int i=0;i<3;i++) cube[5][2-i][2]=tmp[i];
        return *this;
    }
    RubiksCube &rPrime() override{
        this->r();
        this->r();
        this->r();
        return *this;
    }
    RubiksCube &r2() override{
        this->r();
        this->r();
        return *this;
    }
    RubiksCube &f() override {
        this->rotateface(2);
        char tmp[3]={};
        for(int i=0;i<3;i++) tmp[i]=cube[0][2][i];
        for(int i=0;i<3;i++) cube[0][2][i]=cube[1][2-i][2];
        for(int i=0;i<3;i++) cube[1][i][2]=cube[5][0][i];
        for(int i=0;i<3;i++) cube[5][0][i]=cube[3][2-i][0];
        for(int i=0;i<3;i++) cube[3][i][0]=tmp[i];
        return *this;
    }
    RubiksCube &fPrime() override{
        this->f();
        this->f();
        this->f();
        return *this;
    }
    RubiksCube &f2() override{
        this->f();
        this->f();
        return *this;
    }
    RubiksCube &b() override {
        this->rotateface(4);
        char tmp[3]={};
        for(int i=0;i<3;i++) tmp[i]=cube[0][0][2-i];
        for(int i=0;i<3;i++) cube[0][0][2-i]=cube[3][2-i][2];
        for(int i=0;i<3;i++) cube[3][2-i][2]=cube[5][2][i];
        for(int i=0;i<3;i++) cube[5][2][i]=cube[1][i][0];
        for(int i=0;i<3;i++) cube[1][i][0]=tmp[i];
        return *this;
    }
    RubiksCube &bPrime() override{
        this->b();
        this->b();
        this->b();
        return *this;
    }
    RubiksCube &b2() override{
        this->b();
        this->b();
        return *this;
    }
    RubiksCube &d() override {
        this->rotateface(5);
        char tmp[3]={};
        for(int i=0;i<3;i++) tmp[i]=cube[4][2][i];
        for(int i=0;i<3;i++) cube[4][2][i]=cube[3][2][i];
        for(int i=0;i<3;i++) cube[3][2][i]=cube[2][2][i];
        for(int i=0;i<3;i++) cube[2][2][i]=cube[1][2][i];
        for(int i=0;i<3;i++) cube[1][2][i]=tmp[i];
        return *this;
    }
    RubiksCube &dPrime() override{
        this->d();
        this->d();
        this->d();
        return *this;
    }
    RubiksCube &d2() override{
        this->d();
        this->d();
        return *this;
    }

    bool operator==(const RubikCube3dArray &r1) const {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    if (r1.cube[i][j][k] != cube[i][j][k]) return false;
                }
            }
        }
        return true;
    }

    RubikCube3dArray &operator=(const RubikCube3dArray &r1) {
        for (int i = 0; i < 6; i++) {
            for (int j = 0; j < 3; j++) {
                for (int k = 0; k < 3; k++) {
                    cube[i][j][k] = r1.cube[i][j][k];
                }
            }
        }
        return *this;
    }
};

    struct Hash3d {
        size_t operator()(const RubikCube3dArray &r1) const {
            string str = "";
            for (int i = 0; i < 6; i++) {
                for (int j = 0; j < 3; j++) {
                    for (int k = 0; k < 3; k++) {
                        str += r1.cube[i][j][k];
                    }
                }
            }
            return hash<string>()(str);
        }

};


