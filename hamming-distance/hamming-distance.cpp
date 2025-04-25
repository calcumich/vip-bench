#include <iostream>
#include <cstdio>
#include "../config.h"


VIP_ENCINT
hamming_distance(VIP_ENCINT *a,
                 VIP_ENCINT *b,
                 unsigned      n)
{
  VIP_ENCINT sum = VIP_ENCINT(0);
  for (unsigned i = 0; i < n; i++)
  {
    VIP_ENCINT prod = a[i] * b[i];
    VIP_ENCINT ab2  = prod * VIP_ENCINT(2);
    VIP_ENCINT sum_ab = a[i] + b[i];
    VIP_ENCINT x = sum_ab - ab2; // a XOR b = a + b - 2ab
    sum = sum + x;
  }
  return sum;
}

int
main()
{
  mysrand(42);
  Stopwatch::tableFormat = false;
  Stopwatch::precision   = true;

  const unsigned n = 16384;
  VIP_ENCINT *a = new VIP_ENCINT[n];
  VIP_ENCINT *b = new VIP_ENCINT[n];

  for (unsigned i = 0; i < n; i++) {
    a[i] = VIP_ENCINT(myrand() % 2);
    b[i] = VIP_ENCINT(myrand() % 2);
  }

  std::fprintf(stdout, "INFO: a = { ");
  for (unsigned i = 0; i < n; i++)
    std::fprintf(stdout, "%d ", int(VIP_DEC(a[i])));
  std::fprintf(stdout, "}\n");

  std::fprintf(stdout, "INFO: b = { ");
  for (unsigned i = 0; i < n; i++)
    std::fprintf(stdout, "%d ", int(VIP_DEC(b[i])));
  std::fprintf(stdout, "}\n");

  VIP_ENCINT dist;
  {
    Stopwatch sw("VIP-Bench hamming-distance:");
    dist = hamming_distance(a, b, n);
  }

  std::cout << "Hamming distance = "
            << int(VIP_DEC(dist))
            << std::endl;

  delete[] a;
  delete[] b;
  return 0;
}
