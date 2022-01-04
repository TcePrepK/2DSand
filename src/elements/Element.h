//
// Created by Shrimp on 12/30/2021.
//

#ifndef INC_2DSAND_ELEMENT_H
#define INC_2DSAND_ELEMENT_H

#include "../utils/Maths.h"
#include "../utils/Vector3D.h"
#include "../utils/Vector2D.h"

class Element {
private:
    unsigned int id;
    Vector3D color;
public:
    Element(unsigned int id, Vector3D color) : id(id), color(color) {}

    unsigned int getID() const;

    Vector3D getColor();

    virtual Vector2D update(int x, int y) {
        return {x, y};
    }

    virtual bool isDynamic() {
        return true;
    }
};


#endif //INC_2DSAND_ELEMENT_H
