/*
   32-bits Random number generator U(0,1): MRG32k3a
   Author: Pierre L'Ecuyer,
   Source: Good Parameter Sets for Combined Multiple Recursive Random
           Number Generators,
           Shorter version in Operations Research,
           47, 1 (1999), 159--164.
   ---------------------------------------------------------
*/
#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define norm 2.32830654983782900066442465584408243184366682498875888995826244354248046875e-10
#define m1   4294967087
#define m2   4294944443
#define a12     1403580
#define a13n     810728
#define a21      527612
#define a23n    1370589

int64_t s10, s11, s12, s20, s21, s22;

void init(void) {
  srand(time(NULL));
  s10 = rand()%m1;
  s11 = rand()%m1;
  s12 = rand()%m1;
  s20 = rand()%m2;
  s21 = rand()%m2;
  s22 = rand()%m2;
}

double next (void)
{
   int64_t k;
   int64_t p1, p2;
   /* Component 1 */
   p1 = a12 * s11 - a13n * s10;
   k = p1 / m1;
   p1 -= k * m1;
   if (p1 < 0.0)
      p1 += m1;
   s10 = s11;
   s11 = s12;
   s12 = p1;

   /* Component 2 */
   p2 = a21 * s22 - a23n * s20;
   k = p2 / m2;
   p2 -= k * m2;
   if (p2 < 0.0)
      p2 += m2;
   s20 = s21;
   s21 = s22;
   s22 = p2;

   /* Combination */
   if (p1 <= p2)
      return ((p1 - p2 + m1) * norm);
   else
      return ((p1 - p2) * norm);
}

#define INIT init();
#define HARNESS_DOUBLE
#include "harness.c"
