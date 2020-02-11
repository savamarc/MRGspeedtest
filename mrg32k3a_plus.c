/*
   32-bits Random number generator U(0,1): MRG32k3a
   Author: Pierre L'Ecuyer
   Source: Good Parameter Sets for Combined Multiple Recursive Random
           Number Generators,
           Shorter version in Operations Research,
           47, 1 (1999), 159--164.
   ---------------------------------------------------------

  The implementation was heavily modifed by Marc-Antoine Savard
*/
#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define norm 2.32830654983782900066442465584408243184366682498875888995826244354248046875e-10
#define m1   4294967087
#define m2   4294944443
#define a12     1403580
#define a13     4294156359
#define a21      527612
#define a23    4293573854

int64_t x10, x11, x12, x20, x21, x22;

void init(void) {
  srand(time(NULL));
  x10 = rand()%m1;
  x11 = rand()%m1;
  x12 = rand()%m1;
  x20 = rand()%m2;
  x21 = rand()%m2;
  x22 = rand()%m2;
}

double next (void)
{
   uint64_t p, r;
  /* Combination */
  r = (x12 + x22)%m1;
  r %= m1;

  /* Component 1 */
  p = (a12 * x11 + a13 * x10) % m1;
  x10 = x11;
  x11 = x12;
  x12 = p;

  /* Component 2 */
  p = (a21 * x22 + a23 * x20) % m2;
  x20 = x21;
  x21 = x22;
  x22 = p;

  return r * norm;
}

#define INIT init();
#define HARNESS_DOUBLE
#include "harness.c"
