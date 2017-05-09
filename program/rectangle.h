#include <iostream>
#include <string>
#include <vector>

class Rectangle {
	private:
		int length;
		int width;
		int x;
		int y;
		std::string name;
	public:
		Rectangle(int a, int b, int l, int w, std::string n);
		Rectangle(int l, int w, std::string n);
		void setLength(int);
		void setWidth(int);
		void setX(int);
		void setY(int);
		void setName(std::string);
		int getLength();
		int getWidth();
		int getX();
		int getY();
		std::string getName();
		bool collision(Rectangle);
		bool collision(std::vector<Rectangle>);
		std::string toString();
};
