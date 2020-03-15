#include <stdio.h>
#include <stdlib.h>
#include <memory.h>


int main() {
  const int n = 5;
  srand(100);
  
  /* define single precision numbers for demonstration */
  float * d = (float *)calloc(n, sizeof(float));
  d[0] = 0.01;
  d[1] = -0.001;
  d[2] = 0.0001;
  d[3] = -0.000001;
  d[4] = 0.00000000001;
  
  /* define double precision numbers for demonstration */
  double * p = (double *)calloc(n, sizeof(double));
  p[0] = 0.01;
  p[1] = -0.001;
  p[2] = 0.0001;
  p[3] = -0.000001;
  p[4] = 0.00000000001;
  
  /* define regular sum */
  float r = 0;
  
  for (int i = 0; i < n; i ++) {
      r += d[i];
  }
  
  printf("without Kahan (float): %20.12f\n", r);
  
  float sum = 0;
  float c = 0;
  float y = 0;
  float t = 0;

  for (int i = 0; i < n; i ++) {
    y = d[i] - c;
    t = sum + y;
    c = (t - sum) - y;
    sum = t;
  }
  
  printf("with Kahan (float): %23.12f\n", sum);

  double _sum = 0;
  for (int i = 0; i < n; i ++) {
    _sum += p[i];
  }
  printf("without Kahan (double): %19.12f\n", _sum);
  return 0;
}
