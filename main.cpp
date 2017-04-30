#include <iostream>
#include "rectangle.h"

using namespace std;

int main()
{
	Rectangle first(0,0,4,3,"first");

	cout << "Length: " << first.getLength() << "\n";

	Rectangle second(3,3,5,2,"second");

	second.collision(first);
}
