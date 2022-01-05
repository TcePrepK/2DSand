//
// Created by Shrimp on 1/5/2022.
//

#ifndef INC_2DSAND_RANDOMNUMBERGENERATOR_H
#define INC_2DSAND_RANDOMNUMBERGENERATOR_H


#include <ctime>
#include <cstdlib>
#include <memory>
#include <random>

struct RandomNumberGenerator {
private:
    static inline std::default_random_engine rng{(unsigned int) time(nullptr)};
public:
    static int randomInt(int lower, int upper);

    static float randomFloat(int lower, int upper);
};


#endif //INC_2DSAND_RANDOMNUMBERGENERATOR_H
