#include<bits/stdc++.h>
#include <conio.h>
#include <unistd.h>
using namespace std;
bool over;
const int height=20;
const int width=50;
int hx,hy,fx,fy,score;
int tailx[100],taily[100],tail;

enum DIR{STOP=0,LEFT,RIGHT,UP,DOWN};
DIR dir;

void initiate()
{
   over=false;
   score=0;
   tail=0;
   hx=width/2;
   hy=height/2;
   fx=rand()%width;
   fy=rand()%height;
   dir=STOP;
   
}

void draw() 
{
   system("clear");

    for(int i = 0; i < width+2; i++)
    cout<<"#";

    cout<<endl;

    for(int i = 0; i < height ; i++) 
    {

        for (int j = 0; j < width; j++) 
        {

        if (j == 0)
        cout << "#"; //walls

        if (i == hy && j == hx)
        cout << "O"; // snake head

        else if (i==fy && j==fx )
        cout << "*"; // change it to change the fruit

        else
        {
          bool print = false;

          for(int k = 0; k< tail ; k++) 
          {
           if(tailx [k] == j && taily [k] == i) 
           {
           cout << "o"; print = true;
           }
          }

        if (!print) cout << " ";

        }

        if (j == width -1)

        cout << "#";

        }

    cout << endl;

    }

    for (int i = 0; i< width+2; i++)
    cout << "#";

    cout<< endl;

    cout<<"Score:" <<score<<endl ;
}

void move()
{
   if(_kbhit())
   {
    switch(_getche())
    {
      case '5':
      {
      dir=UP;
      break;
      }
      case '2':
      {
      dir=DOWN;
      break;
      }
      
      case '3':
      {
      dir=RIGHT;
      break;
      }
      case '1':
      {
      dir=LEFT;
      break;
      }
      case 'x':
      {
      over=true;
      break;
      }
    }
   }
}


void logic()
{

    int prex=tailx[0];
    int prey=taily[0];
    
    int prexx,preyy;
    
    tailx[0]=hx;
    taily[0]=hy;
    
    
    for(int i=1;i<tail;i++)
    {
       prexx=tailx[i];
       preyy=taily[i];
       
       tailx[i]=prex;
       taily[i]=prey;
       
       prex=prexx;
       prey=preyy;
    }
    
	switch(dir)
	{
	  case LEFT:{
		hx--;
		break;
	  }
	  
	  case RIGHT:{
	    hx++;
	    break;
	  }
	  
	  case UP:{
	    hy--;
	    break;
	  }
	  
	  case DOWN:
	  {
	    hy++;
	    break;
	  }
	  
	  default :
	  {
	    break;
	  }
	  
	}
	
	//if(hx<0 || hx>=width || hy<0 || hy>=height)
	//over=true;
	
	if(hx<0) hx=width-1;
	else if(hx>=width)
	hx=0;
	
	if(hy<0) hy=height-1;
	else if(hy>=height)
	hy=0;	

	for(int i=0;i<tail;i++)
	{
	   if(tailx[i]==hx && taily[i]==hy)
	   over=true;
	}
	if(hx==fx && hy==fy)
	{
	 
	 score+=10;
	 fx=rand()%width;
     fy=rand()%height;
     tail++;
	}
}               

int main()
{
ios_base::sync_with_stdio(0);
cin.tie(0);
cout.tie(0);

 initiate();
 
 while(!over)
 {
    draw();
    move();
    logic();
    for(int i=0;i<100000000;i++)i++;
 }
 
  return 0;
}
