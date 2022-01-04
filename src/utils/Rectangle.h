//
// Created by Shrimp on 1/3/2022.
//

#ifndef INC_2DSAND_RECTANGLE_H
#define INC_2DSAND_RECTANGLE_H


class Rectangle {
public:
    float left, top, right, bottom;

    Rectangle() : left(0), top(0), right(0), bottom(0) {}

    Rectangle(const float left, const float top, const float right, const float bottom) : left(left), top(top),
                                                                                          right(right),
                                                                                          bottom(bottom) {}
};


#endif //INC_2DSAND_RECTANGLE_H
