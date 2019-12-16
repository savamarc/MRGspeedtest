#include <stdint.h>

/* The current state of the generator. */
static uint64_t s = 1;
#define MULT 6328659727172721891

static uint64_t inline next(void) {
  s = s*MULT + 12345;
  return s;
}

#include "harness.c"
