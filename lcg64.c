#include <stdint.h>

/* The current state of the generator. */
static uint64_t s = 1;
#define MULT 3734395367720576825
#define MOD 2305843009213693951

static uint64_t inline next(void) {
  s = s*MULT%MOD;
  return s;
}

#include "harness.c"
