#include"rectangle.h"

using namespace std;

Rectangle::Rectangle(int a , int b, int l, int w, string n)
{
	cout << "Creating rectangle with (x,y)=(" << a << "," << b << ") and area of " << l << "x" << w << " and name " << n << "\n";
	x=a;
	y=b;
	length=l;
	width=w;
	name=n;
}

Rectangle::Rectangle(int l, int w, string n)
{
	cout << "Creating rectangle with default (x,y) and area of " << l << "x" << w << " and name " << n << "\n";
	x=0;
	y=0;
	length=l;
	width=w;
	name=n;
}

//Check for collision against all other rectangles
bool Rectangle::collision(vector<Rectangle> rekt)
{
	bool status=false;
	for(Rectangle lmao:rekt)
	{
		if(name != lmao.getName())
		{
			if(collision(lmao))
			{
				status=true;
			}
		}
	}
	return status;
}


//Check for collision against specific rectangle
bool Rectangle::collision(Rectangle other)
{
	if ( x < other.getX()+other.getLength() && y < other.getY()+other.getWidth() )
	{
		cout << "Collision between ";
		cout << toString();
		cout << " and ";
		cout << other.toString() << endl;
		return true;
	}
	else
	{
		return false;
	}
}

//getsetters
void Rectangle::setLength(int l)
{
	length=l;
}
void Rectangle::setWidth(int w)
{
	width=w;
}
void Rectangle::setX(int ex)
{
	x=ex;
}
void Rectangle::setY(int why)
{
	y=why;
}
void Rectangle::setName(string s)
{
	name=s;
}

int Rectangle::getLength()
{
	return length;
}
int Rectangle::getWidth()
{
	return width;
}
int Rectangle::getX()
{
	return x;
}
int Rectangle::getY()
{
	return y;
}
string Rectangle::getName()
{
	return name;
}

string Rectangle::toString()
{
	return name + "(" + to_string(length)  + "x" + to_string(width) + "@(" + to_string(x) + "," + to_string(y) + "))";
}
