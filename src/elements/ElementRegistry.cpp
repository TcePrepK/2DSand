//
// Created by Shrimp on 12/30/2021.
//

#include "ElementRegistry.h"
#include "solids/moveables/Sand.h"
#include "liquids/Water.h"

void ElementRegistry::RegisterElements() {
    std::cout << "Registering elements!" << std::endl;

    registerElement(std::make_shared<Sand>());
    registerElement(std::make_shared<Water>());
//        registerElement(new Stone());
}

void ElementRegistry::registerElement(const std::shared_ptr<Element> &element) {
    unsigned int id = element->getID();

    if (idToElement.find(id) != idToElement.end()) {
        std::cout << "Tried to register same element id twice!" << std::endl;
        return;
    }

    std::cout << "Successfully registered element with id: " << std::to_string(id) << std::endl;
    idToElement.insert({id, element});
}

std::shared_ptr<Element> ElementRegistry::getElement(const unsigned int id) {
    if (idToElement.find(id) == idToElement.end()) {
        std::cout << "Tried to get element that is not registered! Id: " << std::to_string(id) << std::endl;
        return nullptr;
    }

    return idToElement.at(id);
}

