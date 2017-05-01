#include <iostream>
#include "rectangle.h"
#include <fstream>
#include <string>
#include <vector>

int closeW;
int closeL;

using namespace std;

//Check for any collisions in vector rekt
bool checkCollision( vector<Rectangle> rekt )
{
	bool status=false;
	for(int i=0; i < rekt.size(); i++)
	{
		for(int j=i+1; j < rekt.size(); j++)
		{
			if(rekt[i].collision(rekt[j]))
			{
				status=true;
			}
		}
	}
	return status;
}

vector<Rectangle> insertionSort(vector<Rectangle> rekt)
{
	for(int i=1; i < rekt.size(); i++)
	{
		Rectangle og=rekt[i];
		int iwidth=rekt[i].getWidth();
		int j=i;
		while(j>0 && rekt[j-1].getWidth() < iwidth)
		{
			rekt[j]=rekt[j-1];
			j--;
		}
		rekt[j]=og;
	}
	return rekt;
}

vector<Rectangle> place(Rectangle meme, vector<Rectangle> sol)
{
	bool status=true;
	while(status)
	{
		if(meme.getY()+meme.getWidth() > closeW)
		{
			meme.setY(0);
			meme.setX(meme.getX()+1);
		}			
		else if(meme.collision(sol))
		{
			meme.setY(meme.getY()+1);
		}
		else
		{
			cout << meme.getName() << " " << meme.getY() << " " << meme.getX() << endl;
			status=false;
		}
	}
	sol.push_back(meme);
	return sol;
}


int main()
{
	//Read in config file
	ifstream file("config");
	string str;
	vector<Rectangle> rekt;
	cout << "\nReading config file..." << endl;
	while (std::getline(file, str))
	{
		//Parse line by line by "x y name"
		int x = stoi( str.substr(0,1) );
		int y = stoi( str.substr(2,1) );
		string name = str.substr(4,str.length()-1);
		//Add to vector "rekt" and print out information
		rekt.push_back( Rectangle(x,y,name) );
	}

	//Sort from greatest width to smallest width
	cout << "\nSorting from biggest to smallest by width..." << endl;
	rekt=insertionSort(rekt);

	//Initial enclosing rectangle
	closeW=rekt[0].getWidth();
	closeL=0;
	for(Rectangle lmao:rekt)
	{
		closeL+=lmao.getLength();
	}

	cout << "Enclosing length x width: " << closeL << "x" << closeW << "\n" << endl;

	//Trivial solution
	vector<Rectangle> sol;
	sol=place(rekt[0],sol);
	cout << sol[0].toString() << endl;
	rekt[0].collision(rekt);

	return 0;
}
