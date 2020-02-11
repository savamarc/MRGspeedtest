#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define m1 549755781503
#define m2 549755737667
#define a12 15600308
#define a13 11962985
#define a21 11353736
#define a23 15446194
#define norm 1.818989510698839488297818698370991903623394847500094329006969928741455078125e-12

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
