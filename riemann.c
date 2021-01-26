#include <stdio.h>
#include <math.h>

float myFunction(float x)
{
  /* Change the function to your liking here! */
  /*return 0.9*cos(x)+sin(x);*/
  return 2*x*x*x+x*x-5*x+1;
  /*return x*x + 2;*/
}

/* ------------------------------------------------- */


float convertX(float X)
{
  return 15*X+180;
}

float convertY(float Y)
{
  return -15*Y+180;
}


int main()
{
  printf( "<html>\n\n" );
  /* Create the SVG Header */
  printf( "<!-- SVG IMAGE -->\n<svg width='361px' height='361px' version='1.1'><defs></defs>\n\n" );
  /* Create the Grid */
  printf( "<!-- COORDINATE PLANE -->\n<line x1='0' y1='0' x2='360' y2='0' stroke='#000000' stroke-width='2px'/><line x1='0' y1='15' x2='360' y2='15' stroke='#BBBBBB'/><line x1='0' y1='30' x2='360' y2='30' stroke='#BBBBBB'/><line x1='0' y1='45' x2='360' y2='45' stroke='#BBBBBB'/><line x1='0' y1='60' x2='360' y2='60' stroke='#BBBBBB'/><line x1='0' y1='75' x2='360' y2='75' stroke='#BBBBBB'/><line x1='0' y1='90' x2='360' y2='90' stroke='#BBBBBB'/><line x1='0' y1='105' x2='360' y2='105' stroke='#BBBBBB'/><line x1='0' y1='120' x2='360' y2='120' stroke='#BBBBBB'/><line x1='0' y1='135' x2='360' y2='135' stroke='#BBBBBB'/><line x1='0' y1='150' x2='360' y2='150' stroke='#BBBBBB'/><line x1='0' y1='165' x2='360' y2='165' stroke='#BBBBBB'/><line x1='0' y1='195' x2='360' y2='195' stroke='#BBBBBB'/><line x1='0' y1='210' x2='360' y2='210' stroke='#BBBBBB'/><line x1='0' y1='225' x2='360' y2='225' stroke='#BBBBBB'/><line x1='0' y1='240' x2='360' y2='240' stroke='#BBBBBB'/><line x1='0' y1='255' x2='360' y2='255' stroke='#BBBBBB'/><line x1='0' y1='270' x2='360' y2='270' stroke='#BBBBBB'/><line x1='0' y1='285' x2='360' y2='285' stroke='#BBBBBB'/><line x1='0' y1='300' x2='360' y2='300' stroke='#BBBBBB'/><line x1='0' y1='315' x2='360' y2='315' stroke='#BBBBBB'/><line x1='0' y1='330' x2='360' y2='330' stroke='#BBBBBB'/><line x1='0' y1='345' x2='360' y2='345' stroke='#BBBBBB'/><line x1='0' y1='360' x2='360' y2='360' stroke='#000000'/><line x1='0.75' y1='0' x2='0.75' y2='360' stroke='#000000'/><line x1='15' y1='0' x2='15' y2='360' stroke='#BBBBBB'/><line x1='30' y1='0' x2='30' y2='360' stroke='#BBBBBB'/><line x1='45' y1='0' x2='45' y2='360' stroke='#BBBBBB'/><line x1='60' y1='0' x2='60' y2='360' stroke='#BBBBBB'/><line x1='75' y1='0' x2='75' y2='360' stroke='#BBBBBB'/><line x1='90' y1='0' x2='90' y2='360' stroke='#BBBBBB'/><line x1='105' y1='0' x2='105' y2='360' stroke='#BBBBBB'/><line x1='120' y1='0' x2='120' y2='360' stroke='#BBBBBB'/><line x1='135' y1='0' x2='135' y2='360' stroke='#BBBBBB'/><line x1='150' y1='0' x2='150' y2='360' stroke='#BBBBBB'/><line x1='165' y1='0' x2='165' y2='360' stroke='#BBBBBB'/><line x1='195' y1='0' x2='195' y2='360' stroke='#BBBBBB'/><line x1='210' y1='0' x2='210' y2='360' stroke='#BBBBBB'/><line x1='225' y1='0' x2='225' y2='360' stroke='#BBBBBB'/><line x1='240' y1='0' x2='240' y2='360' stroke='#BBBBBB'/><line x1='255' y1='0' x2='255' y2='360' stroke='#BBBBBB'/><line x1='270' y1='0' x2='270' y2='360' stroke='#BBBBBB'/><line x1='285' y1='0' x2='285' y2='360' stroke='#BBBBBB'/><line x1='300' y1='0' x2='300' y2='360' stroke='#BBBBBB'/><line x1='315' y1='0' x2='315' y2='360' stroke='#BBBBBB'/><line x1='330' y1='0' x2='330' y2='360' stroke='#BBBBBB'/><line x1='345' y1='0' x2='345' y2='360' stroke='#BBBBBB'/><line x1='360' y1='0' x2='360' y2='360' stroke='#000000'/><line x1='180' y1='0' x2='180' y2='360' stroke-width='3' stroke='#000000'/><line x1='0' y1='180' x2='360' y2='180' stroke-width='3' stroke='#000000'/><text x='168' y='10' fill='black'>y</text><text x='349' y='176' fill='black'>x</text><text x='10' y='355' fill='#AAAAAA' font-size='10'>Programmed by Mike Pellegrino</text><text x='240' y='355' fill='#AAAAAA' font-size='10'>http://mkpelleg.freeshell.org</text>\n\n" );
  /* ---------------------------------------------- */
  /* Put code in here to make the rectangles        */
  /* First Graph the Function                       */
  printf( "\n<!-- GRAPH -->\n" );

  for( float i=-12; i<12; i+=0.08 )
    {
      float x1,y1,x2,y2;
      x1=i;
      y1=myFunction( x1 );
      x2=i+0.08;
      y2=myFunction( x2 );
      /* if it's within the grid - graph it         */
      if( ((y1<=15) && (y1>=-15)) && ((y2<=15) && (y2>=-15)) )
	{
	  printf( "<line x1='%f' y1='%f' x2='%f' y2='%f' stroke='#FF0000' stroke-width='2px'/>\n", convertX(x1), convertY(y1), convertX(x2), convertY(y2) );	  
	}
    }
  
  /* Enter Start and Stop x values                  */
  fprintf( stderr, "Enter Boundaries: " );
  float b1, b2, tmp;
  scanf( "%f", &b1 );
  scanf( "%f", &b2 );
  
  /* Make sure that b1 is the left boundary */
  if( b2<b1 )
    {
      tmp=b2;
      b2=b1;
      b1=tmp;
    }

  /* Enter the number of rectangles                 */
  int n;
  fprintf( stderr, "Enter the number of rectangles: ");
  scanf( "%d", &n );
  
  /* Right or Left Riemann Sum                      */
  int lr;
  fprintf( stderr, "Enter 0 for Left Riemann Sum or 1 for Right Riemann Sum: ");
  scanf( "%d", &lr );
  

  /* calculate the width of each rectangle */
  float w;
  w=(b2-b1)/n;
  
  /* Draw each rectangle and add area to total area */
  /* left corner of rectangle is b1+(i-1)*w   */
  /* height of rectangle is f( (b1+lr*w)+(i-1)*w) */
  /* right corner of rectangle is b1+i*w      */
  printf( "\n<!-- RECTANGLES -->\n" );

  float TotalArea=0;
  for( int i=1; i<=n; i++ )
    {
      float h=convertY(myFunction( (b1+lr*w)+(i-1)*w));
      float x1=convertX(b1+(i-1)*w);
      float x2=convertX(b1+i*w);
      float y1=convertY(0);
      TotalArea+=myFunction( (b1+lr*w)+(i-1)*w)*w;
      
      printf( "<line x1='%f' y1='%f' x2='%f' y2='%f' stroke='#0000CC' stroke-width='2px'/>\n", x1, y1, x2, y1 );
      printf( "<line x1='%f' y1='%f' x2='%f' y2='%f' stroke='#0000CC' stroke-width='2px'/>\n", x1, y1, x1, h );
      printf( "<line x1='%f' y1='%f' x2='%f' y2='%f' stroke='#0000CC' stroke-width='2px'/>\n", x2, y1, x2, h );
      printf( "<line x1='%f' y1='%f' x2='%f' y2='%f' stroke='#0000CC' stroke-width='2px'/>\n", x1, h, x2, h );
    }
  printf( "\n<!-- BOUNDARIES -->\n");
  /* Draw the Left and Right Bounds */
  printf( "<line x1='%f' y1='%f' x2='%f' y2='%f' stroke='#00DD00' stroke-width='1px' stroke-dasharray='4,3'/>\n", convertX(b1), convertY(0), convertX(b1), convertY( myFunction(b1)) );
  printf( "<line x1='%f' y1='%f' x2='%f' y2='%f' stroke='#00DD00' stroke-width='1px' stroke-dasharray='4,3'/>\n", convertX(b2), convertY(0), convertX(b2), convertY( myFunction(b2)) );
      
  
  /* ---------------------------------------------- */

  /* End the SVG output */
  printf( "</svg>\n" );
  printf( "<p>Number of Divisions=%i&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;Total Area=%f square units</p>\n",n,TotalArea );
  /* printf( "<p><a href='./riemann%i.html'>[ NEXT --&gt; ]</a>\n",n+1 ); */
  printf( "<p><table border=2><tr><th>#</th><th>Area</th></tr>\n" );
  
  for( int i=1; i<=n; i++ )
    {
      printf( "<tr><td align=center>%i</td><td align=center>%f</td></tr>\n", i, w*myFunction( (b1+lr*w)+(i-1)*w) );
    }
  printf( "</table>\n" );
  printf( "</html>" );

  
  return 0;
}


