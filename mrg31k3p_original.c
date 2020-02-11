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

uint32_t x10, x11, x12, x20, x21, x22;

void init(void) {
  srand(time(NULL));
  x10 = rand()%m1;
  x11 = rand()%m1;
  x12 = rand()%m1;
  x20 = rand()%m2;
  x21 = rand()%m2;
  x22 = rand()%m2;
}

double next (void) {
  uint32_t y1, y2; /* For intermediate results */
  /* First component */
  y1 = (((x11 & mask12) << 22) + (x11 >> 9))
    + (((x12 & mask13) << 7) + (x12 >> 24));
  if (y1 > m1) y1 -= m1;
  y1 += x12;
  if (y1 > m1) y1 -= m1;
  x12 = x11; x11 = x10; x10 = y1;
  /* Second component */
  y1 = ((x20 & mask21) << 15) + 21069 * (x20 >> 16);
  if (y1 > m2) y1 -= m2;
  y2 = ((x22 & mask21) << 15) + 21069 * (x22 >> 16);
  if (y2 > m2) y2 -= m2;
  y2 += x22;
  if (y2 > m2) y2 -= m2;
  y2 += y1;
  if (y2 > m2) y2 -= m2;
  x22 = x21; x21 = x20; x20 = y2;
  /* Combinaison */
  if (x10 <= x20) return ((x10 - x20 + m1) * norm);
  else return ((x10 - x20) * norm);
}

#define INIT init();
#define HARNESS_DOUBLE
#include "harness.c"
