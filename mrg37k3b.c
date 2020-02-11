#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define m1 137438933327
#define m2 137438924159
#define a12 64485701
#define a13 28633419
#define a21 19480496
#define a23 58151419
#define norm 7.27595868065100276763982074353101438431157266251148030278272926807403564453125e-12

uint64_t x10, x11, x12, x20, x21, x22;

void init(void) {
  srand(time(NULL));
  x10 = rand()%m1;
  x11 = rand()%m1;
  x12 = rand()%m1;
  x20 = rand()%m2;
  x21 = rand()%m2;
  x22 = rand()%m2;
}

static double inline next(void) {

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
