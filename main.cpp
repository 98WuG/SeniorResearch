#include <iostream>
#include "rectangle.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool checkCollision( vector<Rectangle> rekt )
{
	bool status=false;
	for(int i=0; i < rekt.size(); i++)
		for(int j=i+1; j < rekt.size(); j++)
			if(rekt[i].collision(rekt[j]))
				status=true;
	return status;
}

int main()
{
	//Read in config file 
	ifstream file("config");
	string str;
	vector<Rectangle> rekt;
	cout << "Reading config file..." << endl;
	while (std::getline(file, str))
	{
		//Parse line by line by "x y name"
		int x = stoi( str.substr(0,1) );
		int y = stoi( str.substr(2,1) );
		string name = str.substr( 4,str.length()-1 );
		//Add to vector "rekt" and print out information
		rekt.push_back( Rectangle(x,y,name) );
	}

	cout << "Added " << rekt.size() << " rectangles\n" << endl;

	checkCollision(rekt);
}
