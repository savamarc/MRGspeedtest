#include <stdint.h>

/* The current state of the generator. */
static uint64_t s[3] = {1,1,1};
#define MULT1 8488
#define MULT2 43065
#define MULT3 13927
#define MOD 9223372036854775773

static uint64_t inline next(void) {
  uint64_t tmp = s[2];
  s[2] = s[1];
  s[1] = s[0];
  
  s[0] = MULT1*s[1] + MULT2*s[2];
  if (s[0] > MOD) s[0] -= MOD;
  s[0] += MULT3*tmp;
  s[0]%=MOD;
  return s[0];
}

#include "harness.c"

