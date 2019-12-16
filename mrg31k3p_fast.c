#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <stdint.h>
#define m1 2147483647
#define m2 2147462579
#define norm 4.6566128752457969230960088680149056017398834228515625e-10
#define mask12 511
#define mask13 16777215
#define mask21 65535

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

static double inline next (void) {
  int64_t y1, r; /* For intermediate results */
  r = x10 - x20;
  r -= m1 * ((y1-1)>>63);

  /* First component */
  y1 = ((((x11 & mask12) << 22) + (x11 >> 9))
    + (((x12 & mask13) << 7) + (x12 >> 24)) + x12) % m1;
  // if (y1 > m1) y1 -= m1;
  x12 = x11; x11 = x10; x10 = y1;

  /* Second component */
  y1 = (((x20 & mask21) << 15) + ((x22 & mask21) << 15)
    + 21069 * ((x22 >> 16) + (x20 >> 16)) + x22) % m2;
  x22 = x21; x21 = x20; x20 = y1;

  /* Combinaison */
  return y1*norm;
}

#define INIT init();
#define HARNESS_DOUBLE
#include "harness.c"
