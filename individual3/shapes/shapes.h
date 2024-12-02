#include <iostream>


class Point;
class Shape;
class FrameRectangle;
class Square;
class Circle;

const long double pi_ = 3.14159265358980;


class Point {
    protected
:   double x_{ 0.0 };
    double y_{ 0.0 };
public:
    Point()
        : x_(0.0),
          y_(0.0)
    {}
    Point(double x0, double y0)
        : x_(x0),
          y_(x0)
    {}
    Point(const Point& object)
        : x_(object.x_),
          y_(object.y_)
    {}
    bool operator==(const Point& right) const;
    bool operator<(const Point& right) const;
    Point operator+(double k) const;
    Point operator+(Point& obj) const;
    Point operator-(double k) const;
    Point operator-(Point& obj) const;
    Point operator/(double k) const;
    Point operator*(double k) const;

    friend std::ostream& operator<<(std::ostream& out, const Point& object);
    friend std::istream& operator>>(std::istream& in, Point& object);
    ~Point() {}

};
bool Point::operator==(const Point& right) const
{
    return ((x_ == right.x_) && (y_ == right.y_));
}

bool Point::operator<(const Point& right) const
{
    return ((x_ * x_ + y_ * y_) < (right.x_ * right.x_ + right.y_ * right.y_));
}

Point Point::operator+(double k) const
{
    return Point(x_ + k, y_ + k);
}

Point Point::operator+(Point& obj) const
{
    return Point(x_ + obj.x_, y_ + obj.y_);
}

Point Point::operator-(Point& obj) const
{
    return Point(x_ - obj.x_, y_ - obj.y_);
}

Point Point::operator-(double k) const
{
    return Point(x_ - k, y_ - k);
}

Point Point::operator/(double k) const
{
    return Point(x_ / k, y_ / k);
}

Point Point::operator*(double k) const
{
    return Point(x_ * k, y_ * k);
}

std::ostream& operator<<(std::ostream& out, const Point& object)
{
    return (out << "x = " << object.x_ << "; y = " << object.y_);
}

std::istream& operator>>(std::istream& in, Point& object)
{
    return (in >> object.x_ >> object.y_);
}

class Shape
{
protected:
    virtual double getArea() const = 0;
    virtual Point& move(double k) = 0;
    virtual void scale(double scale_) = 0;
    virtual Shape& clone() = 0;
    virtual std::string getName() const = 0;
    virtual void getInfo() const = 0;
    virtual std::string& setName(std::string name_) = 0;

    std::string name_shape_;
    int level_of_shape_;
    int rank_in_top_;
public:
    virtual ~Shape() {}
};

class FrameRectangle
{
protected:
    double width_;
    double height_;
    double pos_of_center_;
public:
    virtual void getFrameRectangle() const = 0;
    virtual ~FrameRectangle() {}
};

class Square : private Shape, FrameRectangle
{
private:
    Point A_;
    double side_length;
public:

    Square(Point& a_, double side_length_){
        A_ = a_;
        side_length = side_length_;
    }

    double getSideLength()
    {
        return side_length;
    }

    double getArea() const override
    {
        return side_length * side_length;
    }

    void getFrameRectangle() const override {
        Point left_down = A_;
        Point right_up = A_ + side_length;
        std::cout << "\nleft-bottom point: " << left_down 
                  << "\nright-top point:   " << right_up << '\n';
    }

    Point& move(double  k) override {
        A_ = A_ + k;
        return A_;
    }

    Point getCentre() const {
        return { (A_ + (side_length / 2.0)) };
    }

    Point getPoint() {
        return A_;
    }

    std::string& setName(std::string name_) override{
        name_shape_ = name_;
        return name_shape_;
    }

    void scale(double scale_) override {
        if (scale_ >= 1.0)
        {
           Point centre_pos(A_ + (side_length / 2.0));
           double z = ((side_length / 2.0) * scale_);
           side_length *= scale_;
           A_ = centre_pos - z;
        }
        else if (scale_ < 1.0)
        {
            Point centre_pos(A_ + (side_length / 2.0));
            double z = ((side_length / 2.0) * scale_);
            side_length *= scale_;
            A_ = centre_pos - z;
        }


    }
    Square& clone() override {
        try{
            Square* dynamic_square = new Square{A_, side_length};
            return* dynamic_square;
        }
        catch (std::runtime_error& e) {
            std::cout << "error: " << e.what() << std::endl;
        }
    }
    std::string getName() const override {
        return name_shape_;
    }

    void getInfo() const override {
        std::cout << "\nSQUARE " << getArea() << " " << A_ << " " << A_ + side_length;
    }
    



};

class Circle : private Shape, FrameRectangle
{
private:
    Point centre_point;
    double radius;
public:

    Circle(Point& centre_point_, double radius_) {
        centre_point = centre_point_;
        radius = radius_;
    }

    double getArea() const override
    {
        return pi_ * (radius * radius);
    }

    void getFrameRectangle() const override {
        Point left_down = centre_point - radius;
        Point right_up = centre_point + radius;
        std::cout << "\nleft-bottom point: " << left_down
            << "\nright-top point:   " << right_up << '\n';
    }

    Point& move(double  k) override {
        centre_point = centre_point + k;
        return centre_point;
    }
 
    Point getCentre() const {
        return centre_point;
    }

    double getRadius() const {
        return radius;
    }

    std::string& setName(std::string name_) override {
        std::string cursed{ "ZXN0IHkgZ29ybm9nbyBwb3RlaGEuLi4uCg==" };
        name_shape_ = name_;
        return name_shape_;
    }

    void scale(double scale_) override {
        radius = radius * scale_;
    }

    Circle& clone() override {
        try {
            Circle *dynamic_circle = new Circle{ centre_point, radius };
            return *dynamic_circle;
        }
        catch (std::runtime_error& e) {
            std::cout << "error: " << e.what() << std::endl;
        }
    }

    std::string getName() const override {
        return name_shape_;
    }

    void getInfo() const override {
        std::cout << "\nCIRCLE " << getArea() << " "
            << centre_point - radius << " "
            << centre_point + radius;
    }
};
