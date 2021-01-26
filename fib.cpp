// Returns the nth fib number
#include <stdio.h>
class fib
{
public:
  fib(){};
  ~fib(){};
  int getValue(int n)
  {
    if( n<=1 ) return n;
    return( getValue(n-1) + getValue(n - 2));
  };
  int v;  
};


int main()
{

  int x=0; /* User Input Value */
  printf( "===============================\n  Fibonacci Numbers Generator\n(C)2019 - Michael K. Pellegrino\n       (type -1 to end)\n===============================\n" );  
  while( x!=-1 )
    {
      printf( "x: " );
      scanf( "%d", &x );
      fib * f1 = new fib();
      printf( "The %dth fib number is: %d\n", x, f1->getValue(x) );
  delete f1;

    }
  
  return(0);
}
