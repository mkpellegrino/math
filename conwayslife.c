/*    a C version of Conway's Life   */
/* Written by: Michael K. Pellegrino */
/*           May 26, 2022            */

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 64
#define WIDTH 128

/* a public array */
int grid[4][HEIGHT][WIDTH];


void delay(unsigned int mSeconds)
{
  usleep(mSeconds);
  return;
}
/* display the grid on the screen */
/* if g==1 then display the earmarks */
/* if g==2 then display the previous frame */
/* if g==3 then display the fram before the previous frame */
void display_grid()
{
  for( int i=0; i<WIDTH; i++ ) printf( "=" );
  printf( "\n" );
  for( int i=0; i<HEIGHT; i++ )
    {
      for( int j=0; j<WIDTH; j++ )
	{
	  if( grid[0][i][j] == 1 )
	    {
	      printf( "@" );
	    }
	  else
	    {
	      printf( " " );
	    }
	}
      printf( "\n" );
    }
  for( int i=0; i<WIDTH; i++ ) printf( "=" );
  printf( "\n" );
}

void initialise_grid()
{
  for( int g=0; g<4; g++ )
    {
      for( int i=0; i<HEIGHT; i++ )
	{
	  for( int j=0; j<WIDTH; j++ )
	    {
	      grid[g][i][j] = 0;
	    }
	}
    }
}

void copy_from_frame_to_frame( int a, int b )
{
  for( int i=0; i<HEIGHT; i++ )
    {
      for( int j=0; j<WIDTH; j++ )
	{
	  grid[b][i][j] = grid[a][i][j];
	}
    }

}

int compare_current_with_frame( int a )
{
  /* frame a will be compared with the current frame */
  /* the total number of differences in the frames will be returned */
  int return_value=0;
  for( int i=0; i<HEIGHT; i++ )
    {
      for( int j=0; j<WIDTH; j++ )
	{
	  if( grid[0][i][j] != grid[a][i][j] )
	    {
	      return_value++;
	    }
	}
    }
  return return_value;
}


int number_of_living_neighbors( int x, int y )
{
  /* returns the total number of living neighbors for cell (x,y) */
  /* in the current frame */
  int return_value=0;

  /* this is to ensure nothing goes 'off the grid' */
  int x0 = x-1;
  int x1 = x+1;
  int y0 = y-1;
  int y1 = y+1;

  if( x0 == -1 ) x0 = HEIGHT-1;
  if( x1 == HEIGHT ) x1 = 0;
  if( y0 == -1 ) y0 = WIDTH-1;
  if( y1 == WIDTH ) y1 = 0;
  
  if( grid[0][x0][y] == 1 ) return_value++;
  if( grid[0][x0][y0] == 1 ) return_value++;
  if( grid[0][x][y0] == 1 ) return_value++;
  if( grid[0][x1][y0] == 1 ) return_value++;
  if( grid[0][x1][y] == 1 ) return_value++;
  if( grid[0][x1][y1] == 1 ) return_value++;
  if( grid[0][x][y1] == 1 ) return_value++;
  if( grid[0][x0][y1] == 1 ) return_value++;

  return return_value;

}

void update_grid()
{

  /* save the previous frame */
  copy_from_frame_to_frame( 2, 3 );

  /* save the current frame */
  copy_from_frame_to_frame( 0, 2 );
  
  for( int i=0; i<HEIGHT; i++ )
    {
      for( int j=0; j<WIDTH; j++ )
	{
	  switch( grid[1][i][j] )
	    {
	    case 1:
	      /* if it's a 1 then it has been earmarked for life */
	      grid[0][i][j]=1;
	      break;
	    case -1:
	      /* if it's a -1 then it has been mearmarked for death */
	      grid[0][i][j]=0;
	      break;
	    default:
		/* no change */
	      break;
	    }
	  
	}

    }
}
int earmark()
{

  /* this function will earmark cells for addition or deletion */
  /* it will return the number of cells that it has changed */
  for( int i=0; i<HEIGHT; i++ )
    {
      for( int j=0; j<WIDTH; j++ )
	{
	  if( grid[0][i][j] == 1 )
	    {
	      /* if the cell is currently alive */
	      switch( number_of_living_neighbors(i,j) )
		{
		case 2:
		case 3:
		  /* living cells with 2 or 3 neighbors stay alive */
		  grid[1][i][j] = 0;
		  break;
		default:
		  /* living cells with <2 or >3 living neighbors die */
		  grid[1][i][j] = -1;
		}
	    }

	  else
	    {
	      /* if the cell is currently dead */
	      switch( number_of_living_neighbors(i,j) )
		{
		case 3:
		  /* dead cells with 3 living neighbors come alive */
		  grid[1][i][j] = 1;
		  break;
		default:
		  grid[1][i][j] = 0;
		}
	    }
	}
    }
}

void glider( int direction, int x, int y )
{
  /* directions */
  /* 1 & 2 - up and right */
  /* 3 & 4 - up and left */
  /* 5 & 6 - down and left */
  /* 7 & 8 - down and right */
  switch( direction )
    {
    case 1:
      grid[0][x-1][y-1] = 1;
      grid[0][x][y-1]=1;
      grid[0][x+1][y-1]=1;
      grid[0][x+1][y]=1;
      grid[0][x][y+1]=1;
      break;
    case 2:
      grid[0][x-1][y]=1;
      grid[0][x][y-1]=1;
      grid[0][x+1][y-1]=1;
      grid[0][x+1][y]=1;
      grid[0][x+1][y+1]=1;
      break;
    case 3:
      grid[0][x-1][y-1]=1;
      grid[0][x][y-1]=1;
      grid[0][x+1][y-1]=1;
      grid[0][x-1][y]=1;
      grid[0][x][y+1]=1;
      break;
    case 4:
      grid[0][x-1][y-1]=1;
      grid[0][x][y-1]=1;
      grid[0][x-1][y]=1;
      grid[0][x+1][y]=1;
      grid[0][x-1][y+1]=1;
      break;
    case 5:
      grid[0][x-1][y-1]=1;
      grid[0][x-1][y]=1;
      grid[0][x+1][y]=1;
      grid[0][x-1][y+1]=1;
      grid[0][x][y+1]=1;
      break;
    case 6:
      grid[0][x][y-1]=1;
      grid[0][x-1][y]=1;
      grid[0][x-1][y+1]=1;
      grid[0][x][y+1]=1;
      grid[0][x+1][y+1]=1;
      break;
    case 7:
      grid[0][x+1][y-1]=1;
      grid[0][x-1][y]=1;
      grid[0][x+1][y]=1;
      grid[0][x][y+1]=1;
      grid[0][x+1][y+1]=1;
      break;
    case 8:
      grid[0][x][y-1]=1;
      grid[0][x+1][y]=1;
      grid[0][x-1][y+1]=1;
      grid[0][x][y+1]=1;
      grid[0][x+1][y+1]=1;
      break;
    default:
      printf( "error: no such glider (use 1-8)\n" );
      break;
    }
  return;
}

void plot(int x, int y)
{
  grid[0][x][y] = 1;
}

void randomly_populate()
{

  for( int i=0; i<HEIGHT; i++ )
    {
      for( int j=0; j<WIDTH; j++ )
	{
	  double x = rand()%3;
	  if( x > 1 )
	    {
	      plot(i,j);
	    }
	}
    }
  

}
int main()
{
  srand(time(NULL));
    
  initialise_grid();

  /*
    glider( 1, 2, 60 );
    glider( 2, 10, 60 );
    glider( 3, 60, 60 );
    glider( 4, 54, 60 );
    glider( 5, 54, 4 );
    glider( 6, 60, 7 );
    glider( 7, 10, 3 );
    glider( 8, 16, 5 );
    glider( 6, 1, 30 );
  */

  randomly_populate();
  
  int x=0;
  int ticks=0;
  while( x!=-1)
    {
      /* show the current frame on the screen */
      display_grid();

      /* wait for a bit */
      delay(50000);

      /* iterate through all the cells and determine */
      /* if, after the next tick, they should be alive or dead */
      earmark();

      /* make the appropriate changes to the earmarked cells */
      update_grid();

      /* keep track of how many iterations */
      ticks++;

      /* If the current frame is equal to the previous frame, then end */
      if( compare_current_with_frame( 2 ) == 0 )
	{
	  printf( "no change - simulation stopped after %i iterations\n", ticks );
	  x=-1;
	}

      /* if the current frame is equal to the one before the one beofre it, then end */
      else if( compare_current_with_frame( 3 ) == 0 )
	{
	  printf( "looping - simulation stopped after %i iterations\n", ticks );
	  x=-1;
	}
    }
}
