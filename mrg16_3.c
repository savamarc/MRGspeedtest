#include <stdint.h>

/* The current state of the generator. */
static uint16_t x1 = 1;
static uint16_t x2 = 1;
static uint16_t x3 = 1;
static uint16_t x4 = 1;
#define a1 21097
#define a2 15926
#define a3 24541
#define a4 7478
#define MOD 32749

static uint16_t inline next(void) {
  int32_t tmp = x1*a1 - x2*a2;
  int32_t tmp2 = x3*a3 - x4*a4;
  tmp %= MOD;
  tmp2 %= MOD;
  tmp += tmp2;
  tmp %= MOD;

  x4 = x3;
  x3 = x2;
  x2 = x1;
  x1 = tmp;

  return tmp;
}

#include "harness.c"
