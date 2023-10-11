#include <iostream>
using namespace std;

class Square
{
protected:
    double side;

public:
    Square(double length_side) : side(length_side) {}

    double get_area()
    {
        return side * side;
    }
};

class Circle
{
protected:
    double radius;

public:
    Circle(double radius_circle) : radius(radius_circle) {}

    double get_area()
    {
        double pi = 3.141;
        return pi * radius * radius;
    }
};

class circle_in_square : public Square, public Circle
{
public:
    circle_in_square(double length_side) : Square(length_side), Circle(length_side / 2) {}

    double get_radius()
    {
        return Circle::radius;
    }

    double get_area()
    {
        return Square::get_area();
    }
};

int main()
{
    circle_in_square circle(3);

    cout << "Square area: " << circle.get_area() << endl;
    cout << "Circle area: " << circle.Circle::get_area() << endl;
    cout << "Radius: " << circle.get_radius() << endl;

    return 0;
}
