#ifndef _black_scholes_h
#define _black_scholes_h

#include <math.h>

typedef struct __time_arg_t {
  double t1;
  double t2;
  double t3;
} time_arg_t;

typedef struct __bs_return_t{
  double mean;
  double stddev;
} bs_return_t;

/**
 * In (read-only) and out (write-only) arguments to the function(s)
 * that do(es) Black-Scholes iterations.  This is used for both the
 * sequential and parallel (threaded with Pthreads) implementation.
 *
 * Fields marked [IN] are read-only inputs; don't modify them once
 * they are set.
 *
 * Fields marked [OUT] are outputs to be computed by your code.
 *
 * You might add additional field(s) to this struct.
 *
 * @note The typedef lets you refer to this type without saying
 * "struct" in front of it, but it means that you have to include this
 * header file if you ever use this datatype.  Example:
 *
 * #include "black_scholes.h"
 * #include <stdio.h>
 *
 * void 
 * foo (black_scholes_args_t* args) 
 * {
 *   printf ("M = %d\n", args->M);
 *   ...
 * }
 */
typedef struct __black_scholes_args_t {
  /**
   * [IN] Various parameters of the Black-Scholes MC method.  
   */
  double S, E, r, sigma, T;
  /**
   * [IN] Number of Black-Scholes MC iterations.  
   */
  long M;
  /**
   * [OUT] Array (of M elements) containing the results of each of the
   * M trials.
   */
  double* trials;
  /**
   * [OUT] Arithmetic mean of trials[0 .. M-1].
   */
  double mean;

  /**
   * [OUT] variance of trials[0 .. M-1].
   */
  double variance;

  /**
   * [OUT] time (in seconds) that it takes to call spawn_prng_stream().
   */

  int nthreads;  // number of threads

  void** prng_stream;
  int debug_mode;
} black_scholes_args_t;

// structure for GPU sequential version project
typedef struct __wrapper_black_scholes_args_t {
  black_scholes_args_t * black_sh;
  int pid;
  int nthreads;
  int mod;
  double* thread_means;
  double* fixed_rands;
  //int debug_mode;
} wrapper_black_scholes_args_t;

/**
 * Frees any malloc'd objects in the args struct, without freeing the
 * args pointer itself.
 */
void
deinit_black_scholes_args (black_scholes_args_t* args);

/**
 * Confidence interval [min,max].
 *
 * The typedef lets you refer to this type without saying "struct" 
 * in front of it, but it means that you have to include this header
 * file if you ever use this datatype.
 */
typedef struct __confidence_interval_t {
  double min, max;
} confidence_interval_t;

/**
 * Run the Black-Scholes MC simulation using the parameters S, E, r,
 * sigma, and T, with M total trials.  
 *
 * @param [OUT] Time to call spawn_prng_stream().  In parallel, you
 * may want to take the max over all such times (one per thread), or
 * just pick a representative sample.
 *
 * @note You might need to modify the signature of this function.
 */

bs_return_t
black_scholes (confidence_interval_t* interval,
	       const double S,
	       const double E,
	       const double r,
	       const double sigma,
	       const double T,
	       const long M,
               const int nthreads,
	       double* fixedRands,
          void** prng_stream,
		  const int debug_mode);


#endif /* _black_scholes_h */
