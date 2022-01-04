//
// Created by Shrimp on 1/4/2022.
//

#ifndef INC_2DSAND_LIQUID_H
#define INC_2DSAND_LIQUID_H


#include "../Element.h"

class Liquid : public Element {
public:
    Liquid(unsigned int id, Vector3D color) : Element(id, color) {}
};


#endif //INC_2DSAND_LIQUID_H
