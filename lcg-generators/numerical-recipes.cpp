#include<iostream>
#include<bitset>
#include<unistd.h>

int main()
{
  unsigned int seed = 12;
  unsigned int a = 1664525;
  unsigned long long int m = (1ull << 32);
  unsigned int c = 1013904223;

  long long int size = 1024 * 1024 * 256;
  while(size > 0) {
      printf("%lld \n", size);
      unsigned int val = (a*seed+c) %m;
      fwrite(&val, sizeof(val), 1, stdout);
      size -= sizeof(val);
      seed=val;
  }


  return 0;
}
