#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/* The current state of the generator. */
static uint32_t x1 = 1;
static uint32_t x2 = 1;
static uint32_t x3 = 1;
static uint32_t x4 = 1;
#define a1 32907
#define a4 17770
#define MOD 65521
#define NORM 1.5262e-5

static double inline next(void) {
  uint32_t tmp = x1*a1;
  uint32_t tmp2 = x4*a4;
  tmp = (tmp-tmp/MOD*MOD);
  tmp2 = (tmp2-tmp2/MOD*MOD);
  tmp += tmp2;
  tmp %= MOD;

  x4 = x3;
  x3 = x2;
  x2 = x1;
  x1 = tmp;

  return tmp*NORM;
}

#ifndef INIT
#define INIT init();
void init(void) {
  srand(time(NULL));
  x1 = rand()%MOD;
  x2 = rand()%MOD;
  x3 = rand()%MOD;
  x4 = rand()%MOD;
}
#endif

#define HARNESS_DOUBLE
#include "harness.c"
