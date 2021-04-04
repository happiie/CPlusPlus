#include <iostream>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include "Mouse.h"
#include "Snake.h"

using namespace std;

int xSize=20,ySize=20;

void printMap(char gameMap[20][20])
{
	for(int x=0;x<xSize;x++)
	{
		cout<<"+---"; // Top line
	}
	cout<<"+"<<endl; // Final plus

	for(int y=0;y<ySize;y++)
	{
		for(int x=0;x<xSize;x++)
		{
			cout<<"| "<<gameMap[y][x]<<" "; // Places array inside grid
		}
		cout<<"|"<<endl;

		for(int x=0;x<xSize;x++)
		{
			cout<<"+---"; // Draws last lines
		}
		cout<<"+"<<endl; // Final plus
	}
}

int main()
{
    //random the program on every runtime
    srand(time(0));

    //initiate all map to -
    char gameMap[20][20];
    for(int i=0;i<20;i++)
    {
        for(int j=0;j<20;j++)
        {
            gameMap[i][j]='-';
        }
    }
    //declare array of class of snake and mouse
    Snake snake[1000];
    Mouse mouse[2000];

    //array to store place of snake and mouse
    int syPlace[1000];
    int sxPlace[1000];
    int myPlace[2000];
    int mxPlace[2000];

    //initiate original number of snake and mouse
    int s=10;
    int m=50;
    int ssurvive=10;
    int msurvive=50;

    //to check whether snake or mouse has success to breed
    int soriginal=0;
    int sbreed=0;
    int moriginal=0;
    int mbreed=0;

    //initiate snake and mouse place
    for(int i=0;i<s;i++)
    {
        syPlace[i]=rand()%20;
        sxPlace[i]=rand()%20;

        while(gameMap[syPlace[i]][sxPlace[i]]!='-')
        {
            syPlace[i]=rand()%20;
            sxPlace[i]=rand()%20;
        }
        gameMap[syPlace[i]][sxPlace[i]]='X';
    }

    for(int j=0;j<m;j++)
    {
        myPlace[j]=rand()%20;
        mxPlace[j]=rand()%20;

        while(gameMap[myPlace[j]][mxPlace[j]]!='-')
        {
            myPlace[j]=rand()%20;
            mxPlace[j]=rand()%20;
        }
        gameMap[myPlace[j]][mxPlace[j]]='O';
    }

    printMap(gameMap);
    cout<<"Initial MAP"<<endl;
    cout<<"Time Step: 0"<<endl;
    cout<<"Snake survive: "<<ssurvive<<endl;
    cout<<"Mouse survive: "<<msurvive<<endl;
    cout<<endl;
    cout<<"Press ENTER to move"<<endl;
    system("PAUSE");
    system("CLS");

    //start of the game, time step = 20
    for(int z=0;z<20;z++)
    {
        //check number of breed of both snake and mouse
        if(sbreed!=soriginal)
        {
            s=s+sbreed;
            sbreed=soriginal;
        }

        if(mbreed!=moriginal)
        {
            m=m+mbreed;
            mbreed=moriginal;
        }

        //part of snake
        for(int i=0;i<s;i++)
        {
            if(snake[i].getSurvive()==true)
            {
                int newy,newx;
                int moves;

                int test;
                int randomCall=rand()%8+1;
                if(randomCall==1)
                    test=snake[i].checkMouse1(gameMap,syPlace[i],sxPlace[i]);
                else if(randomCall==2)
                    test=snake[i].checkMouse2(gameMap,syPlace[i],sxPlace[i]);
                else if(randomCall==3)
                    test=snake[i].checkMouse3(gameMap,syPlace[i],sxPlace[i]);
                else if(randomCall==4)
                    test=snake[i].checkMouse4(gameMap,syPlace[i],sxPlace[i]);
                else if(randomCall==5)
                    test=snake[i].checkMouse5(gameMap,syPlace[i],sxPlace[i]);
                else if(randomCall==6)
                    test=snake[i].checkMouse6(gameMap,syPlace[i],sxPlace[i]);
                else if(randomCall==7)
                    test=snake[i].checkMouse7(gameMap,syPlace[i],sxPlace[i]);
                else
                    test=snake[i].checkMouse8(gameMap,syPlace[i],sxPlace[i]);

                if(test==0)
                {
                    snake[i].send(rand()%4+1);
                    moves=snake[i].get();
                }
                else
                    moves=test;

                if(moves==1)
                {
                    newy=syPlace[i];
                    newx=sxPlace[i]-1;
                }
                else if(moves==2)
                {
                    newy=syPlace[i]-1;
                    newx=sxPlace[i];
                }
                else if(moves==3)
                {
                    newy=syPlace[i];
                    newx=sxPlace[i]+1;
                }
                else
                {
                    newy=syPlace[i]+1;
                    newx=sxPlace[i];
                }
                while(gameMap[newy][newx]=='X'||newy<0||newx<0||newy>=20||newx>=20)
                {
                    snake[i].send(rand()%4+1);
                    moves=snake[i].get();
                    if(moves==1)
                    {
                        newy=syPlace[i];
                        newx=sxPlace[i]-1;
                    }
                    else if(moves==2)
                    {
                        newy=syPlace[i]-1;
                        newx=sxPlace[i];
                    }
                    else if(moves==3)
                    {
                        newy=syPlace[i];
                        newx=sxPlace[i]+1;
                    }
                    else
                    {
                        newy=syPlace[i]+1;
                        newx=sxPlace[i];
                    }
                    if(snake[i].checkAll()==true)
                        break;
                }
                if(snake[i].checkAll()!=true)
                {
                    gameMap[syPlace[i]][sxPlace[i]]='-';
                    syPlace[i]=newy;
                    sxPlace[i]=newx;
                    if(gameMap[syPlace[i]][sxPlace[i]]=='O')
                        snake[i].setZeroStarve();
                    else
                        snake[i].setStarve();
                    gameMap[syPlace[i]][sxPlace[i]]='X';
                }
                else
                    gameMap[syPlace[i]][sxPlace[i]]='X';
                snake[i].reset();

                if(snake[i].getStarve()==3)
                {
                    snake[i].die();
                    gameMap[syPlace[i]][sxPlace[i]]='-';
                }

                snake[i].setBreed();
                if(snake[i].getBreed()==5)
                {
                    int newplace;
                    snake[i].send(rand()%4+1);
                    newplace=snake[i].get();
                    if(newplace==1)
                    {
                        syPlace[s+sbreed]=syPlace[i];
                        sxPlace[s+sbreed]=sxPlace[i]-1;
                    }
                    else if(newplace==2)
                    {
                        syPlace[s+sbreed]=syPlace[i]-1;
                        sxPlace[s+sbreed]=sxPlace[i];
                    }
                    else if(newplace==3)
                    {
                        syPlace[s+sbreed]=syPlace[i];
                        sxPlace[s+sbreed]=sxPlace[i]+1;
                    }
                    else
                    {
                        syPlace[s+sbreed]=syPlace[i]+1;
                        sxPlace[s+sbreed]=sxPlace[i];
                    }
                    while(gameMap[syPlace[s+sbreed]][sxPlace[s+sbreed]]!='-')
                    {
                        snake[i].send(rand()%4+1);
                        newplace=snake[i].get();
                        if(newplace==1)
                        {
                            syPlace[s+sbreed]=syPlace[i];
                            sxPlace[s+sbreed]=sxPlace[i]-1;
                        }
                        else if(newplace==2)
                        {
                            syPlace[s+sbreed]=syPlace[i]-1;
                            sxPlace[s+sbreed]=sxPlace[i];
                        }
                        else if(newplace==3)
                        {
                            syPlace[s+sbreed]=syPlace[i];
                            sxPlace[s+sbreed]=sxPlace[i]+1;
                        }
                        else
                        {
                            syPlace[s+sbreed]=syPlace[i]+1;
                            sxPlace[s+sbreed]=sxPlace[i];
                        }
                        if(snake[i].checkAll()==true)
                            break;
                    }
                    if(snake[i].checkAll()!=true)
                    {
                        sbreed++;
                        gameMap[syPlace[s+sbreed]][sxPlace[s+sbreed]]='X';
                    }
                    snake[i].reset();

                    if(syPlace[s+sbreed]>=20||sxPlace[s+sbreed]>=20)
                        snake[s+sbreed].die();
                }
            }
        }

        //part of mouse
        for(int j=0;j<m;j++)
        {
            if(gameMap[myPlace[j]][mxPlace[j]]=='X')
                mouse[j].die();

            if(mouse[j].getSurvive()==true)
            {
                int newy,newx;
                int moves;
                mouse[j].send(rand()%4+1);
                moves=mouse[j].get();
                if(moves==1)
                {
                    newy=myPlace[j];
                    newx=mxPlace[j]-1;
                }
                else if(moves==2)
                {
                    newy=myPlace[j]-1;
                    newx=mxPlace[j];
                }
                else if(moves==3)
                {
                    newy=myPlace[j];
                    newx=mxPlace[j]+1;
                }
                else
                {
                    newy=myPlace[j]+1;
                    newx=mxPlace[j];
                }
                while(gameMap[newy][newx]!='-'||newy<0||newx<0||newy>=20||newx>=20)
                {
                    mouse[j].send(rand()%4+1);
                    moves=mouse[j].get();
                    if(moves==1)
                    {
                        newy=myPlace[j];
                        newx=mxPlace[j]-1;
                    }
                    else if(moves==2)
                    {
                        newy=myPlace[j]-1;
                        newx=mxPlace[j];
                    }
                    else if(moves==3)
                    {
                        newy=myPlace[j];
                        newx=mxPlace[j]+1;
                    }
                    else
                    {
                        newy=myPlace[j]+1;
                        newx=mxPlace[j];
                    }
                    if(mouse[j].checkAll()==true)
                        break;
                }
                if(mouse[j].checkAll()!=true)
                {
                    gameMap[myPlace[j]][mxPlace[j]]='-';
                    myPlace[j]=newy;
                    mxPlace[j]=newx;
                    gameMap[myPlace[j]][mxPlace[j]]='O';
                }
                else
                    gameMap[myPlace[j]][mxPlace[j]]='O';
                mouse[j].reset();

                mouse[j].setBreed();
                if(mouse[j].getBreed()==2)
                {
                    int newplace;
                    mouse[j].send(rand()%4+1);
                    newplace=mouse[j].get();
                    if(newplace==1)
                    {
                        myPlace[m+mbreed]=myPlace[j];
                        mxPlace[m+mbreed]=mxPlace[j]-1;
                    }
                    else if(newplace==2)
                    {
                        myPlace[m+mbreed]=myPlace[j]-1;
                        mxPlace[m+mbreed]=mxPlace[j];
                    }
                    else if(newplace==3)
                    {
                        myPlace[m+mbreed]=myPlace[j];
                        mxPlace[m+mbreed]=mxPlace[j]+1;
                    }
                    else
                    {
                        myPlace[m+mbreed]=myPlace[j]+1;
                        mxPlace[m+mbreed]=mxPlace[j];
                    }
                    while(gameMap[myPlace[m+mbreed]][mxPlace[m+mbreed]]!='-')
                    {
                        mouse[j].send(rand()%4+1);
                        newplace=mouse[j].get();
                        if(newplace==1)
                        {
                            myPlace[m+mbreed]=myPlace[j];
                            mxPlace[m+mbreed]=mxPlace[j]-1;
                        }
                        else if(newplace==2)
                        {
                            myPlace[m+mbreed]=myPlace[j]-1;
                            mxPlace[m+mbreed]=mxPlace[j];
                        }
                        else if(newplace==3)
                        {
                            myPlace[m+mbreed]=myPlace[j];
                            mxPlace[m+mbreed]=mxPlace[j]+1;
                        }
                        else
                        {
                            myPlace[m+mbreed]=myPlace[j]+1;
                            mxPlace[m+mbreed]=mxPlace[j];
                        }
                        if(mouse[j].checkAll()==true)
                            break;
                    }
                    if(mouse[j].checkAll()!=true)
                    {
                        mbreed++;
                        gameMap[myPlace[m+mbreed]][mxPlace[m+mbreed]]='O';
                    }
                    mouse[j].reset();

                    if(myPlace[m+mbreed]>=20||mxPlace[m+mbreed]>=20)
                        mouse[m+mbreed].die();
                }
            }
        }

        //1 time step end
        printMap(gameMap);

        ssurvive=0;
        msurvive=0;
        for(int y=0;y<ySize;y++)
        {
            for(int x=0;x<xSize;x++)
            {
                if(gameMap[y][x]=='X')
                    ssurvive++;
                if(gameMap[y][x]=='O')
                    msurvive++;
            }
        }

        cout<<"Time Step: "<<z+1<<endl;
        cout<<"Snake survive: "<<ssurvive<<endl;
        cout<<"Mouse survive: "<<msurvive<<endl;
        cout<<endl;
        cout<<"Press ENTER to move"<<endl;
        system("PAUSE");
        system("CLS");
    }

    //20 time steps end
    cout<<"Game End"<<endl;
    string winner;
    if(ssurvive>msurvive)
        winner="Snake";
    else
        winner="Mouse";
    cout<<winner<<" WIN"<<endl;

    return 0;
}
