#include"rectangle.h"

using namespace std;

Rectangle::Rectangle(int a , int b, int l, int w, string n)
{
	std::cout << "Creating rectangle with (x,y)=(" << a << "," << b << ") and area of " << l << "x" << w << " and name " << n << "\n";
	x=a;
	y=b;
	length=l;
	width=w;
	name=n;
}

bool Rectangle::collision(Rectangle other)
{
	if ( x < other.getX()+other.getLength() || y < other.getY()+other.getLength() )
	{
		cout << "Collision between " << name << " and " << other.getName() << "!";
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
