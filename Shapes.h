//
// THIS CODE IS BEING REUSED FROM JOSHUA NEWTON'S "CircleMania" PROJECT
// MINOR MODIFICATIONS MAY BE MADE FOR THE PURPOSES OF THE CS205 FINAL PROJECT
//

#ifndef CS205FINAL_SHAPES_H
#define CS205FINAL_SHAPES_H


#include <cmath>
#include <iostream>
#include <memory>
#include <vector>
#include <math.h>

/*
 Inheritance:

                                Shape(Abstract)
                                / | |       \
                               /  | |        \
                              /   | |         \
               RectangleShape    | Circle     HollowCircle
                                  |
                               Triangle(Abstract)
                                 /  |    |   \
                                /   |    |    \
                               /    |    |     \
                            Left  Right  Down   Up
*/

using namespace std;

struct color {
    double red;
    double green;
    double blue;
};

struct point {
    int x;
    int y;
};

enum triangleDirection {Up, Right, Down, Left};

class Shape {
public:
    // Constructors
    Shape();
    Shape(color f);
    Shape(point p);
    Shape(int xIn, int yIn);
    Shape(color f, point p);
    Shape(color f, int xIn, int yIn);
    Shape(const Shape &s); // copy constructor

    // Destructor
    ~Shape();

    // getters
    double getArea() const;
    double getPerimeter() const;
    color getFill() const;
    point getPosition() const;
    double getX() const;
    double getY() const;

    // setters
    void setFill(color f);
    void setFill(double r, double g, double b);
    void setPosition(point p);
    void setPosition(int xIn, int yIn);

    void move(int delta_x, int delta_y);

    // will add canvas parameter when we learn graphics
    // pure virtual (class is abstract)
    virtual void draw() const = 0;

protected:
    color fill;
    point position;
    // helper methods
    // pure virtual
    virtual double calculateArea() const = 0;
    virtual double calculatePerimeter() const = 0;
};

class Circle : public Shape {
public:
    // Constructors
    // will call calculateArea and calculatePerimeter
    Circle();
    Circle(double r);
    Circle(double r, color f);
    Circle(color f);
    Circle(const Circle &c); // Copy Constructor
    Circle(double r, color f, point p);
    // getter
    double getRadius() const;

    // setter
    // will call calculateArea and calculatePerimeter
    void setRadius(double r);

    void draw() const override;

    // detect if the circle is overlapping with a coordinate point
    bool isOverlapping(const point &p) const;
    bool isOverlapping(int x, int y) const;
    // detect if a circle is ovelapping with this circle
    bool isOverlapping (const Circle &c) const;
    // detect if a circle is overlapping with a rectangle

private:
    double calculateArea() const override;
    double calculatePerimeter() const override;
    double radius;
    // Note: the inherited point will represent the
    // center of the circle
};

class RectangleShape : public Shape {
public:
    // Constructors
    RectangleShape();
    RectangleShape(double b, double h);
    RectangleShape(double b, double h, color f);
    RectangleShape(color f);
    RectangleShape(int xIn, int yIn);
    RectangleShape(point p);
    RectangleShape(double b, double h, color f, int xIn, int yIn);


    // getters
    double getBase() const;
    double getHeight() const;
    // setters
    // want point to have x, y coordinates >= 0
    void setTopLeft(int xIn, int yIn);
    // want base to be >= 0
    void setBase(double b);
    // want height to be >= 0
    void setHeight(double h);
    void setDimensions(double b, double h);

    void draw() const override;

    // detect if the rectangle is overlapping with a coordinate point
    bool isOverlapping(const point &p) const;
    bool isOverlapping(int x, int y) const;
    bool isOverlapping(const Circle &c) const;

private:
    double calculateArea() const override;
    double calculatePerimeter() const override;
    double base;
    double height;
    // Note: the inherited point will represent
    // the top left corner of the rectangle
};

class HollowCircle : public Shape {
public:
    //Constructors
    HollowCircle();
    HollowCircle(double radiusIn, double radiusOut, color f, int x, int y);
    // Copy Constructor
    HollowCircle(const HollowCircle &copy);
    //Getters
    double getRadiusInner() const;
    double getRadiusOuter() const;
    //Setters
    void setRadiusInner(int newRadius);
    void setRadiusOuter(int newRadius);

    //Other methods
    bool isOverlapping(int x, int y) const;
    bool isOverlapping(Circle circle) const;
    bool isOverlapping(RectangleShape rectangle) const;
    bool isOverlapping(HollowCircle hollowCircle) const;
    void draw() const override;
private:
    double radiusInner;
    double radiusOuter;
    double calculateArea() const override;
    double calculatePerimeter() const override;
};

// Note these will be equilateral triangles only
class Triangle : public Shape {
public:
    // Constructors
    Triangle();
    Triangle(double sideLength);
    Triangle(double sideLength, color f);
    Triangle(double sideLength, color f, int x, int y);
    Triangle(double sideLength, color f, RectangleShape rectangle);
    // Copy Conctructor
    Triangle(const Triangle &copy);
    // Getters
    double getSideLength() const;
    triangleDirection getTriangleDirection() const;
    // Setters
    void setSideLength(double newSideLength);

    // Functions
    virtual bool isOverlapping(int x, int y) const = 0;
    //  virtual void draw()const override;
    virtual string getDirection() const = 0;

private:
    double sideLength;
    triangleDirection direction;
    double calculateArea() const override;
    double calculatePerimeter() const override;
};

class TriangleUp : public Triangle{
public:
    // Constructors
    TriangleUp();
    TriangleUp(double sideLength);
    TriangleUp(double sideLength, color f);
    TriangleUp(double sideLength, color f, int x, int y);
    TriangleUp(double sideLength, color f, RectangleShape rectangle);
    // Copy Conctructor
    TriangleUp(const Triangle &copy);
    bool isOverlapping(int x, int y) const;
    void draw() const;
    string getDirection() const;
};

class TriangleLeft : public Triangle{
public:
    // Constructors
    TriangleLeft();
    TriangleLeft(double sideLength);
    TriangleLeft(double sideLength, color f);
    TriangleLeft(double sideLength, color f, int x, int y);
    TriangleLeft(double sideLength, color f, RectangleShape rectangle);
    // Copy Conctructor
    TriangleLeft(const Triangle &copy);

    bool isOverlapping(int x, int y) const;
    void draw() const;
    string getDirection() const;
};

class TriangleDown : public Triangle{
public:
    TriangleDown();
    TriangleDown(double sideLength);
    TriangleDown(double sideLength, color f);
    TriangleDown(double sideLength, color f, int x, int y);
    TriangleDown(double sideLength, color f, RectangleShape rectangle);
    // Copy Conctructor
    TriangleDown(const Triangle &copy);
    bool isOverlapping(int x, int y) const;
    void draw() const;
    string getDirection() const;
};

class TriangleRight : public Triangle{
public:
    TriangleRight();
    TriangleRight(double sideLength);
    TriangleRight(double sideLength, color f);
    TriangleRight(double sideLength, color f, int x, int y);
    TriangleRight(double sideLength, color f, RectangleShape rectangle);
    // Copy Conctructor
    TriangleRight(const Triangle &copy);

    bool isOverlapping(int x, int y) const;
    void draw() const;
    string getDirection() const;
};

#endif //CS205FINAL_SHAPES_H
