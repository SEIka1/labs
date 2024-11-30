#include <iostream>
#include "shapes.h"

//5+2

int main()
{
    std::cout << "\nTESTS FOR SQUARE:\n\n";
    Point a = { 0, 0 };
    double length = 6.0;

    Square new_square{a, length};

    std::cout << "\nthe square has been created!\n\n";
    std::cout << "left-bottom point: " << a << "\nlength: " << length;
    std::cout << "\narea:" << new_square.getArea() << '\n';

    std::cout << "\nframe rectangle:\n";
    new_square.getFrameRectangle();

    new_square.move(5);
    std::cout << "\nshape has been moved at 5 positions";
    std::cout << "\nnew centre: " << new_square.getCentre() << std::endl;

    std::cout << "\nframe rectangle:\n";
    new_square.getFrameRectangle();

    std::cout << "------------------------------------------------------";
    new_square.scale(2.0);
    std::cout << "\nshape has been scaled in 2 times\n";
    std::cout << "\nleft-bottom point in: " << new_square.getPoint() 
              << "\nthe centre in: " << new_square.getCentre() << "\n\nnew frame rectangle: ";
    new_square.getFrameRectangle();
    std::cout << "------------------------------------------------------";

    new_square.scale(0.5);
    std::cout << "\nshape has been scaled in 0.5 times\n";
    std::cout << "\nleft-bottom point in: " << new_square.getPoint() 
              << "\nthe centre in: " << new_square.getCentre() << "\n\nnew frame rectangle: ";
    new_square.getFrameRectangle();
    std::cout << "------------------------------------------------------";

    new_square.scale(2.5);
    std::cout << "\nshape has been scaled in 2.5 times\n";
    std::cout << "\nleft-bottom point in: " << new_square.getPoint() 
              << "\nthe centre in: " << new_square.getCentre() << "\n\nnew frame rectangle: ";
    new_square.getFrameRectangle();
    std::cout << "------------------------------------------------------";

    new_square.scale(0.25);
    std::cout << "\nshape has been scaled in 0.25 times\n";
    std::cout << "\nleft-bottom point in: " << new_square.getPoint() 
              << "\nthe centre in: " << new_square.getCentre() << "\n\nnew frame rectangle: ";
    new_square.getFrameRectangle();
    std::cout << "------------------------------------------------------";

    std::cout << "\nenter the name of shape: ";
    std::string new_name_for_shape;
    std::cin >> new_name_for_shape;
    new_square.setName(new_name_for_shape);
    std::cout << "\nnew name of your shape is: " << new_square.getName();

    Square square_clone = new_square.clone();
    std::cout << "\n\nthe clone of shape \"" << new_square.getName() << "\" has been created!\n"
              << "\nenter the name of new shape: ";
    std::string new_name_for_shape_2;
    std::cin >> new_name_for_shape_2;
    square_clone.setName(new_name_for_shape_2);
    std::cout << "\nthe name has been successfully set, new name is: " << square_clone.getName() << std::endl;

    std::cout << "\n------------------------------------------------------";
    std::cout << "\ninfo about " << new_square.getName() << ":";
    new_square.getInfo();

    std::cout << "\n------------------------------------------------------";
    std::cout << "\ninfo about " << square_clone.getName() << ":";
    square_clone.getInfo();

    std::cout << "\n------------------------------------------------------";
    square_clone.move(-4.5);
    std::cout << "\n\n" << square_clone.getName() << " has been moved to -4.5 positions!\n";

    std::cout << "\n------------------------------------------------------";
    std::cout << "\ninfo about " << new_square.getName() << ":" << new_square.getCentre();
    new_square.getInfo();

    std::cout << "\n------------------------------------------------------";
    std::cout << "\ninfo about " << square_clone.getName() << ":" << square_clone.getCentre();
    square_clone.getInfo();
    std::cout << "\n------------------------------------------------------";

    std::cout << "\n\n\n";

    std::cout << "TESTS FOR CIRCLE:\n\n";

    Point centre_point{ 5.0, 5.0 };
    double radius{ 2.5 };

    Circle new_circle{ centre_point, radius };

    std::cout << "\nthe circle has been created!\n";
    std::cout << "\ncentre point: " << centre_point << "\nradius: " << radius;
    std::cout << "\narea:" << new_circle.getArea() << std::endl;

    std::cout << "\nframe rectangle:\n";
    new_circle.getFrameRectangle();

    new_circle.move(5.0);
    std::cout << "\ncircle has been moved at 5.0 positions";
    std::cout << "\nnew centre: " << new_circle.getCentre() << std::endl;

    std::cout << "\nframe rectangle:\n";
    new_circle.getFrameRectangle();

    std::cout << "------------------------------------------------------";
    new_circle.scale(2.0);
    std::cout << "\nnew radius is: " << new_circle.getRadius();
    std::cout << "\n\nnew frame rectangle:";
    new_circle.getFrameRectangle();

    std::cout << "------------------------------------------------------";
    new_circle.scale(8.0);
    std::cout << "\nnew radius is: " << new_circle.getRadius();
    std::cout << "\n\nnew frame rectangle:";
    new_circle.getFrameRectangle();

    std::cout << "------------------------------------------------------";
    new_circle.scale(0.2);
    std::cout << "\nnew radius is: " << new_circle.getRadius();
    std::cout << "\n\nnew frame rectangle:";
    new_circle.getFrameRectangle();

    std::cout << "\nenter the name of shape: ";
    std::string new_name_for_circle;
    std::cin >> new_name_for_circle;
    new_circle.setName(new_name_for_circle);
    std::cout << "\nnew name of your shape is: " << new_circle.getName();

    Circle circle_clone = new_circle.clone();
    std::cout << "\n\nthe clone of shape \"" << new_circle.getName() << "\" has been created!\n"
        << "\nenter the name of new shape: ";
    std::string new_name_for_circle_2;
    std::cin >> new_name_for_circle_2;
    circle_clone.setName(new_name_for_circle_2);
    std::cout << "\nthe name has been successfully set, new name is: " << circle_clone.getName() << std::endl;

    std::cout << "\n------------------------------------------------------";
    std::cout << "\ninfo about " << new_circle.getName() << ":";
    new_circle.getInfo();

    std::cout << "\n------------------------------------------------------";
    std::cout << "\ninfo about " << circle_clone.getName() << ":";
    circle_clone.getInfo();

    std::cout << "\n------------------------------------------------------";

    circle_clone.move(-17.0);
    std::cout << "\n\n" << circle_clone.getName() << " has been moved to -17.0 positions!\n";

    new_circle.move(-11.0);
    std::cout << "\n\n" << new_circle.getName() << " has been moved to -11.0 positions!\n";

    std::cout << "\n------------------------------------------------------";
    std::cout << "\ninfo about " << new_circle.getName() << ":" << new_circle.getCentre();
    new_circle.getInfo();

    std::cout << "\n------------------------------------------------------";
    std::cout << "\ninfo about " << circle_clone.getName() << ":" << circle_clone.getCentre();
    circle_clone.getInfo();
    std::cout << "\n------------------------------------------------------";

    std::cout << "\n\n\n";

    std::cout << "to check the result: https://www.geogebra.org/geometry/f8mnm3cp\n\n\n\n";

    system("pause");


}
