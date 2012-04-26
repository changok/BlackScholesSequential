/*
 * mock_gaussian.c
 *
 *  Created on: Apr 20, 2012
 *      Author: jinyoung
 */

#include "mock_gaussian.h"

double mock_gaussrand_only1 () {
    return 1.0;
}

double pre_generated_rands (const double_generator_one_input_t f,
        void* f_state,
        gaussrand_state_t* gaussrand_state) {
    return 0;
}
