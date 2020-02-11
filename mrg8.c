#include <stdint.h>
#include <stdlib.h>
#include <time.h>

/* The current state of the generator. */
static uint8_t x1 = 1;
static uint8_t x2 = 1;
static uint8_t x3 = 1;
static uint8_t x4 = 1;
static uint8_t x5 = 1;
static uint8_t x6 = 1;
static uint8_t x7 = 1;
static uint8_t x8 = 1;
#define a1 44
#define a3 60
#define a4 63
#define a5 218
#define a6 102
#define a8 142
#define MOD 251
#define NORM 0.003984064
#define NORM2 0.003968254

static double inline next(void) {
  uint32_t tmp = x1*a1 + x3*a3 + x4*a4 + x5*a5 + x6*a6 + x8*a8;
  tmp %= MOD;

  x8 = x7;
  x7 = x6;
  x6 = x5;
  x5 = x4;
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
  x5 = rand()%MOD;
  x6 = rand()%MOD;
  x7 = rand()%MOD;
  x8 = rand()%MOD;
}
#endif

#define HARNESS_DOUBLE
#include "harness.c"
