#include <iostream>
#include "rectangle.h"
#include <fstream>
#include <string>
#include <vector>

int closeW;
int closeL;

using namespace std;

vector<string> sols;

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
		if(meme.getX()+meme.getLength() > closeL)
		{
			cout << "Error: Exceeded bounding box" << endl;
			sol.clear();
			sol.push_back(Rectangle(0,0,meme.getName()));
			return sol;
		}
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
			//cout << meme.getName() << " " << meme.getX() << " " << meme.getY() << endl;
			status=false;
		}
	}
	sol.push_back(meme);
	return sol;
}

vector<Rectangle> solve(vector<Rectangle> rekt)
{
	vector<Rectangle> sol;
	for(Rectangle goodone:rekt)
	{
		sol=place(goodone,sol);
	}
	for(Rectangle niceone:sol)
	{
		cout << niceone.toString() << endl;
	}
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
		rekt.push_back(Rectangle(x,y,name));
	}

	//Sort from greatest width to smallest width
	cout << "\nSorting from biggest to smallest by width..." << endl;
	rekt=insertionSort(rekt);

	//Initial enclosing rectangle
	closeW=rekt[0].getWidth();
	closeL=0;
	for(Rectangle lmao:rekt)
	{
		cout << lmao.toString() << endl;
		closeL+=lmao.getLength();
	}

	cout << "Enclosing length x width: " << closeL << "x" << closeW << "\n" << endl;

	//Solve
	vector<Rectangle> sol;
	int ogL = closeL;
	int ogW = closeW;
	for(int i = 0; i <= ogL-ogW; i++)
	{
		closeL--;
		closeW++;
		string entry = "\nEnclosing box of " + to_string(closeL) + "x" + to_string(closeW) + ":\n";
		cout << entry << endl;
		sol=solve(rekt);
		for(Rectangle meme:sol)
		{
			entry += meme.toString() + "\n";
		}
		sols.push_back(entry);
	}

	return 0;
}
