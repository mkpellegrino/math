#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define TRUE 1
#define FALSE 0

int isPrime( double  n )
{
  double  x=n;
  printf( "%3.0f is a factor", n );
  for( int i=2;i<n-1;i++ )
    {
      if( x/i == floor(x/i) )
	{
	  /* Then it's not prime */
	  printf( " but it's not prime because it is divisible by %d\n", i);
	  return(FALSE);
	}
    }
  printf( "\n" );
  return(TRUE);
}

int main( int argc, char *argv[])
{
  if( argc < 2 )
    {
      printf( "usage: %s N\nwhere N is an integer.\nExample: %s 34\n\n", argv[0], argv[0] );
      exit(-1);
    }

  /* double x=600851475143; */
  double x=atoi(argv[1]);

  for( int i=x-1; i>=2; i-- )
    {
      if( x/i == floor(x/i) )
	{
	  /* then i is a factor */
	  if( isPrime(i) )
	    {
	      printf( "%d is the largest prime factor of %3.0f.\n", i, x );
	      exit(1);
	    }
	}
    }
  
  printf("%3.0f is prime.\n", x );
  exit(-1);
  
  
}
