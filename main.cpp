#include <iostream>
#include "rectangle.h"
#include <fstream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	//Read in config file 
	ifstream file("config");
	string str;
	vector<Rectangle> rekt;
	while (std::getline(file, str))
	{
		//Parse line by line by "x y name"
		int x = stoi( str.substr(0,1) );
		int y = stoi( str.substr(2,1) );
		string name = str.substr( 4,str.length()-1 );
		//Add to vector "rekt" and print out information
		rekt.push_back( Rectangle(x,y,name) );
	}

	cout << "\nAdded " << rekt.size() << " rectangles" << endl;

	rekt[0].collision(rekt[1]);
}
