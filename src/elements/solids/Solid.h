//
// Created by Shrimp on 1/3/2022.
//

#ifndef INC_2DSAND_SOLID_H
#define INC_2DSAND_SOLID_H


#include "../Element.h"

class Solid : public Element {
public:
    Solid(unsigned int id, Vector3D color) : Element(id, color) {}
};


#endif //INC_2DSAND_SOLID_H
