#ifndef _mock_gaussian_h
#define _mock_gaussian_h

#include "util.h"

double
mock_gaussrand_only1 ();

double
pre_generated_rands (const double_generator_one_input_t f,
        void* f_state,
        gaussrand_state_t* gaussrand_state);

#endif /* _mock_gaussian_h */
