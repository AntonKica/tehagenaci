#include<iostream>
#include<bitset>
#include<unistd.h>

int main()
{
  unsigned int seed = 12;
  unsigned int a = 75;
  unsigned int m = (1 << 16) + 1;
  unsigned int c = 74;

  long long int size = 1024 * 1024 * 256;
  while(size > 0) {
      printf("%lld \n", size);
      unsigned short val = (a*seed+c) %m;
      fwrite(&val, sizeof(val), 1, stdout);
      size -= sizeof(val);
      seed=val;
  }


  return 0;
}
