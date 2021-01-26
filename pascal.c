#include <stdio.h>

float f(int x)
{
  float ret=1;
  for( int i=2; i<=x; i++ ) ret*=i;
  return ret;
}

int main()
{
  int r=0; /* User Input Value */
  printf( "===============================\n  Pascal's Triangle Generator\n(C)2019 - Michael K. Pellegrino\n       (type -1 to end)\n===============================\n" );
  while( r != -1 )
    {
      printf( "r: " );
      scanf( "%d", &r );
      for( int j=0; j<r; j++ ) printf( "%2.0f\t", f(r-1)/( (f(r-j-1)*f(j) )) );
      printf( "\n" );
    }
  return 0;
}


