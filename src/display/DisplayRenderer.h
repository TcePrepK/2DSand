//
// Created by Shrimp on 1/2/2022.
//

#ifndef INC_2DSAND_DISPLAYRENDERER_H
#define INC_2DSAND_DISPLAYRENDERER_H


#include <memory>
#include "DisplayShader.h"

class DisplayRenderer {
private:
    std::shared_ptr<DisplayShader> displayShader;
public:
    DisplayRenderer();

    void render(unsigned int image);
};


#endif //INC_2DSAND_DISPLAYRENDERER_H
