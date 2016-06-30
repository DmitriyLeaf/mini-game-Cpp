# include <iostream>
# include <windows.h>
# include <time.h>
# include <conio.h>
# include <fstream>

using namespace std;

const int INTERVAL = 1;
char a[1000][1000];
int n, m;
int coordinat_x, coordinat_y;

int coordinat_2_x, coordinat_2_y;

int s=0, s_2=0; // ('^' s==1; 'v' s==2; '<' s==3; '>' s==4;) <=> (s_2;)
int f=3, gc=0;

//void standart_srttings();

class table
{
       public:
              void show_table()
			  {
			      system("cls");
				  for (int i = 0; i <= n+1; ++i)
				  	for (int j = 0; j <= m+1; ++j)
				  		cout << (i == 0 || j == 0 || i == n + 1 || j == m + 1 ? '#' : a[i][j]) << (j <= m ? "" : "\n");
				  cout << "\n" << "(c) Kruglow 2015 \n \n";
			  }
};

//------------------------------------------------------------

class human
{
       public:
              //int hp;
              //int coordinat_x;
              //int coordinat_y;
              char symbol;
              
              void clear_human();
              void show_human();
              void check_coord();
              
              void step();
              void fire();
              void show_object();
              void clear_object();
              void game_over();
       };
       void human::clear_human()
       {
            a[coordinat_x][coordinat_y] = ' ';
            a[coordinat_2_x][coordinat_2_y] = ' ';
            }
       void human::show_human()
       {
            a[coordinat_x][coordinat_y] = 2;
            a[coordinat_2_x][coordinat_2_y] = 1;
            }
       void human::check_coord()
       {
            if (coordinat_x > n) coordinat_x -= 1;
            if (coordinat_x < 1) coordinat_x += 1;
            if (coordinat_y > m) coordinat_y -= 1;
            if (coordinat_y < 1) coordinat_y += 1;
            
            if (coordinat_2_x > n) coordinat_2_x -= 1;
            if (coordinat_2_x < 1) coordinat_2_x += 1;
            if (coordinat_2_y > m) coordinat_2_y -= 1;
            if (coordinat_2_y < 1) coordinat_2_y += 1;
            }
       void human::step()
       {
            clear_human();
            int x, y;
			if (kbhit() == true)
            {
               symbol = getch();
               switch (symbol)
               {
                      case 'w':
                           if (a[coordinat_x-1][coordinat_y]=='#') s=1;
                           else s=1, coordinat_x--;
                           break;
                      case 'a':
                           if (a[coordinat_x][coordinat_y-1]=='#') s=3;
                           else s=3, coordinat_y--;
						   break;
                      case 's':
                           if (a[coordinat_x+1][coordinat_y]=='#') s=2;
                           else s=2, coordinat_x++;
						   break;
                      case 'd':
                           if (a[coordinat_x][coordinat_y+1]=='#') s=4;
                           else s=4, coordinat_y++;
                           break;
                              
                      //-------------------------------------------
                      
                      case 'i':
                           if (a[coordinat_2_x-1][coordinat_2_y]=='#') s_2=1;
                           else s_2=1, coordinat_2_x--;
                           break;
                      case 'j':
                           if (a[coordinat_2_x][coordinat_2_y-1]=='#') s_2=3;
                           else s_2=3, coordinat_2_y--;
                           break;
                      case 'k':
                           if (a[coordinat_2_x+1][coordinat_2_y]=='#') s_2=2;
                           else s_2=2, coordinat_2_x++;
                           break;
                      case 'l':
                           if (a[coordinat_2_x][coordinat_2_y+1]=='#') s_2=4;
                           else s_2=4, coordinat_2_y++;
                           break;
                      //-------------------------------------------
                      
                      case '1': f=1, show_object() ; break;
                      case '2': f=1, clear_object(); break;
                      
                      case 'c': f=0, show_object(); break;
                      case 'v': f=0, clear_object(); break;
                      
                      case '5': 
						   f=1;
						   if (gc == 0) fire();
                           else break;
						   break;
                      
                      case 'g': 
					  	   f=0; 
					  	   if (gc == 0) fire();
                           else break;
						   break;
                      
                      default : break;
                      }
               check_coord();
               show_human();
               table f;
               f.show_table();
               }
            }
       void human::show_object()
       {
            if (f==0)
			{
				switch (s)
            	{
                	case 4: a[coordinat_x][coordinat_y+1] = '#'; break;
                	case 3: a[coordinat_x][coordinat_y-1] = '#'; break;
                	case 1: a[coordinat_x-1][coordinat_y] = '#'; break;
                	case 2: a[coordinat_x+1][coordinat_y] = '#'; break;
                }
            }
            if (f==1)
			{
				switch (s_2)
            	{
                	case 4: a[coordinat_2_x][coordinat_2_y+1] = '#'; break;
                	case 3: a[coordinat_2_x][coordinat_2_y-1] = '#'; break;
                	case 1: a[coordinat_2_x-1][coordinat_2_y] = '#'; break;
                	case 2: a[coordinat_2_x+1][coordinat_2_y] = '#'; break;
                }
            }
       }
       void human::clear_object()
       {
            if (f==0)
			{
				switch (s)
            	{
                	case 4: a[coordinat_x][coordinat_y+1] = ' '; break;
                	case 3: a[coordinat_x][coordinat_y-1] = ' '; break;
                	case 1: a[coordinat_x-1][coordinat_y] = ' '; break;
                	case 2: a[coordinat_x+1][coordinat_y] = ' '; break;
                }
            }
            if (f==1)
			{
				switch (s_2)
            	{
                	case 4: a[coordinat_2_x][coordinat_2_y+1] = ' '; break;
                	case 3: a[coordinat_2_x][coordinat_2_y-1] = ' '; break;
                	case 1: a[coordinat_2_x-1][coordinat_2_y] = ' '; break;
                	case 2: a[coordinat_2_x+1][coordinat_2_y] = ' '; break;
                }
            }
       }
       void human::fire()
       {
       		int x, y;
       		table t;
       		if (f==0)
       		{
       		    switch(s)
       			{
       				case 4:
					   	gc = 1;
                     	x=coordinat_x;
                     	y=coordinat_y+1;
                     	for (int i=0; i!=1; y++)
                     	{
                         	if (kbhit() == true) step();
                         	a[x][y] = 4;
                         	a[x][y-1] = ' ';
                         	if (a[x][y+1]=='#') a[x][y+1] = ' ', a[x][y] = ' ', i=1;
                         	show_human();
                         	t.show_table();
                         	if (a[x][y+1]==1) 
							{game_over();
							 i=1;}
							if (y==m) a[x][y] = ' ', i=1;
                         	Sleep(1);
                         }
                     	gc = 0;
					 	break;
                	case 3:
						gc = 1;
                     	x=coordinat_x;
                     	y=coordinat_y-1;
                     	for (int i=0; i!=1; y--)
                     	{
                         	if (kbhit() == true) step();
                         	a[x][y] = 4;
                         	a[x][y+1] = ' ';
                         	if (a[x][y-1]=='#') a[x][y-1] = ' ', a[x][y] = ' ', i=1;
                         	show_human();
                         	t.show_table();
                         	if (a[x][y-1]==1) 
							{game_over();
							 i=1;}
							if (y==0) a[x][y] = ' ', i=1;
                         	Sleep(1);
                         }
                     	gc = 0;
					 	break;
                	case 1:
						gc = 1;
                     	x=coordinat_x-1;
                     	y=coordinat_y;
                     	for (int i=0; i!=1; x--)
                     	{
                         	if (kbhit() == true) step();
                         	a[x][y] = 4;
                         	a[x+1][y] = ' ';
                         	if (a[x-1][y]=='#') a[x-1][y] = ' ', a[x][y] = ' ', i=1;
                         	show_human();
                         	t.show_table();
                         	if (a[x-1][y]==1) 
							{game_over();
							 i=1;}
							if (x==0) a[x][y] = ' ', i=1;
							Sleep(1);
                         }
                     	gc = 0;
					 	break;
                	case 2:
						gc = 1;
                     	x=coordinat_x+1;
                     	y=coordinat_y;
                     	for (int i=0; i!=1; x++)
                     	{
                         	if (kbhit() == true) step();
                         	a[x][y] = 4;
                         	a[x-1][y] = ' ';
                         	if (a[x+1][y]=='#') a[x+1][y] = ' ', a[x][y] = ' ', i=1;
                         	show_human();
                         	t.show_table();
                         	if (a[x+1][y]==1) 
							{game_over();
							 i=1;}
							if (x==n) a[x][y] = ' ', i=1;
							Sleep(1);
                         }
                     	gc = 0;
					 	break;
				}
			}
			
			if (f==1)
       		{
       			switch(s_2)
       			{
       					case 4:
					   	gc = 1;
                     	x=coordinat_2_x;
                     	y=coordinat_2_y+1;
                     	for (int i=0; i!=1; y++)
                     	{
                         	if (kbhit() == true) step();
                         	a[x][y] = 4;
                         	a[x][y-1] = ' ';
                         	if (a[x][y+1]=='#') a[x][y+1] = ' ', a[x][y] = ' ', i=1;
                         	show_human();
                         	t.show_table();
                         	if (a[x][y+1]==2) 
							{game_over();
							 i=1;}
							if (y==m) a[x][y] = ' ', i=1;
                         	Sleep(1);
                         }
                     	gc = 0;
					 	break;
                	case 3:
						gc = 1;
                     	x=coordinat_2_x;
                     	y=coordinat_2_y-1;
                     	for (int i=0; i!=1; y--)
                     	{
                         	if (kbhit() == true) step();
                         	a[x][y] = 4;
                         	a[x][y+1] = ' ';
                         	if (a[x][y-1]=='#') a[x][y-1] = ' ', a[x][y] = ' ', i=1;
							show_human();
                         	t.show_table();
                         	if (a[x][y-1]==2) 
							{game_over();
							 i=1;}
							if (y==0) a[x][y] = ' ', i=1;
                         	Sleep(1);
                         }
                     	gc = 0;
					 	break;
                	case 1:
						gc = 1;
                     	x=coordinat_2_x-1;
                     	y=coordinat_2_y;
                     	for (int i=0; i!=1; x--)
                     	{
                         	if (kbhit() == true) step();
                         	a[x][y] = 4;
                         	a[x+1][y] = ' ';
                         	if (a[x-1][y]=='#') a[x-1][y] = ' ', a[x][y] = ' ', i=1;
							show_human();
                         	t.show_table();
                         	if (a[x-1][y]==2) 
							{game_over();
							 i=1;}
							if (x==0) a[x][y] = ' ', i=1;
                         	Sleep(1);
                         }
                     	gc = 0;
					 	break;
                	case 2:
						gc = 1;
                     	x=coordinat_2_x+1;
                     	y=coordinat_2_y;
                     	for (int i=0; i!=1; x++)
                     	{
                         	if (kbhit() == true) step();
                         	a[x][y] = 4;
                         	a[x-1][y] = ' ';
                         	if (a[x+1][y]=='#') a[x+1][y] = ' ', a[x][y] = ' ', i=1;
							show_human();
                         	t.show_table();
                         	if (a[x+1][y]==2) 
							{game_over();
							 i=1;}
							if (x==n) a[x][y] = ' ', i=1;
                         	Sleep(1);
                         }
                     	gc = 0;
					 	break;
				}
			}
	   }
	   void human::game_over()
	   {
	   		char first=2, second=1;
			if (f==0) cout << endl << first << " <--WINNER" << endl << endl << "GAME OVER " << endl << endl;
			if (f==1) cout << endl << second << " <--WINNER" << endl << endl << "GAME OVER " << endl << endl;
			system ("PAUSE");
			system ("PAUSE");
			system ("PAUSE");
			system ("PAUSE");
			system ("PAUSE");
			system ("PAUSE");
			system ("PAUSE");
			for (int i=0; i<n+1; i++)
				for (int j=0; j<m+1; j++) a[i][j]=' ';
			
			coordinat_x=1;
			coordinat_y=1;
	 
	 		coordinat_2_x=n;
	 		coordinat_2_y=m;
	 		
	 		table t;
			show_human();
            t.show_table();
	   }
            
//------------------------------------------------------------

void standart_settings()
{
	 n = 15;
     m = 45;
     coordinat_x=1;
	 coordinat_y=1;
	 
	 coordinat_2_x=n;
	 coordinat_2_y=m;
	 
	 human hu;
	 hu.show_human();
     table ta;
     ta.show_table();
}

int main()
{
    human hu;
	standart_settings();
    
	while (1)
    {
    	hu.step();	
		Sleep(INTERVAL);
    }
}

