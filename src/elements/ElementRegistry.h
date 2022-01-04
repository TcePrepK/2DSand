//
// Created by Shrimp on 12/30/2021.
//

#ifndef INC_2DSAND_ELEMENTREGISTRY_H
#define INC_2DSAND_ELEMENTREGISTRY_H


#include <memory>
#include <unordered_map>
#include "Element.h"
#include "../utils/Pair_Hash.h"

class ElementRegistry {
private:
    std::unordered_map<unsigned int, std::shared_ptr<Element>> idToElement;

    void registerElement(const std::shared_ptr<Element> &element);

public:
    void RegisterElements();

    std::shared_ptr<Element> getElement(unsigned int id);
};


#endif //INC_2DSAND_ELEMENTREGISTRY_H
