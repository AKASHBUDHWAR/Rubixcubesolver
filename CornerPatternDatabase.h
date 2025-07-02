//
// Created by akash on 19/6/25.
//

#ifndef CORNERPATTERNDATABASE_H
#define CORNERPATTERNDATABASE_H
#include "PatternDatabase.h"
#include "RubiksCube.h"
#include "PermutationIndexer.h"



class CornerPatternDatabase :public PatternDatabase{
    typedef RubiksCube::FACE F;

    PermutationIndexer<8> permIndexer;
public:
    CornerPatternDatabase();
    CornerPatternDatabase(uint8_t init_val);
    uint32_t getDatabaseIndex(const RubiksCube& cube) const;
};



#endif //CORNERPATTERNDATABASE_H
