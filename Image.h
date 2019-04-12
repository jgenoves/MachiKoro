//
// Created by Ethan Nerney on 2018-12-09.
//

#ifndef GAMEENGINE_IMAGE_H
#define GAMEENGINE_IMAGE_H


#include "Shapes.h"
#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <sys/time.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


struct Vector2D {
    double x, y, rotationAngle;

    Vector2D(double x, double y, double r) {
        this->x = x;
        this->y = y;
        rotationAngle = r;
    }

    Vector2D(double x, double y) {
        this->x = x;
        this->y = y;
        rotationAngle = 0;
    }

    // Multiplying a vector by a scalar returns a vector with each aspect of the original vector being multiplied
    // by that scalar (m stands for multiple)
    friend Vector2D operator*(Vector2D v, double m) {
        return Vector2D(v.x * m, v.y * m, v.rotationAngle * m);
    }

    // Multiplying two vectors together returns a vector with each aspect being the product of the original two
    // vectors' aspects
    friend Vector2D operator*(Vector2D v, Vector2D v2) {
        return Vector2D(v.x * v2.x, v.y * v2.y, v.rotationAngle * v2.rotationAngle);
    }

    // Dividing a vector by a scalar returns a vector with each aspect of the original vector being divided by that
    // scalar (d stands for dividend)
    friend Vector2D operator/(Vector2D v, double d) {
        return Vector2D(v.x / d, v.y / d, v.rotationAngle / d);
    }

    // Adding two vectors together returns a vector with each aspect of the vector being the sum of the original
    // two vectors' aspects
    friend Vector2D operator+(Vector2D v1, Vector2D v2) {
        return Vector2D(v1.x + v2.x, v1.y + v2.y, v1.rotationAngle + v2.rotationAngle);
    }

    // Incrementing a vector by another vector is similar to adding them togeter
    Vector2D &operator+=(Vector2D v) {
        this->x += v.x;
        this->y += v.y;
        this->rotationAngle += rotationAngle;
        return *this;
    }

    // if two vectors have all the same values for their aspects they are equal
    friend bool operator==(Vector2D lhs, Vector2D rhs) {
        return (lhs.x == rhs.x) and (lhs.y == rhs.y) and (lhs.rotationAngle == rhs.rotationAngle);
    }

    friend Vector2D operator-(Vector2D lhs, Vector2D rhs) {
        return Vector2D(lhs.x - rhs.x, lhs.y - rhs.y, lhs.rotationAngle - rhs.rotationAngle);
    }

    friend Vector2D operator-(Vector2D v) {
        return Vector2D(-v.x, -v.y, -v.rotationAngle);
    }

    // output operator displaying the x, y, and angle values
    friend std::ostream &operator<<(std::ostream &outs, const Vector2D &rhs) {
        outs << "X: " << rhs.x << " Y: " << rhs.y << " A: " << rhs.rotationAngle;
        return outs;
    }
};

struct RGBColor {
    double r;
    double g;
    double b;
    // RGB Constructor that takes doubles as the rgb values, for ease in graphics
    RGBColor(double red, double green, double blue) {
        r = red;
        g = green;
        b = blue;
    }

    // RGB Constructor that takes ints (0-255) as rgb values, and converts them to doubles
    RGBColor(int red, int green, int blue) {
        r = red / 255.;
        g = green / 255.;
        b = blue / 255.;
    }


    friend RGBColor operator !(RGBColor c) {
        return RGBColor(1 - c.r, 1 - c.g, 1 - c.b);
    }

    friend RGBColor operator +(RGBColor lhs, RGBColor rhs) {
        return RGBColor(lhs.r + rhs.r, lhs.g + rhs.g, lhs.b + rhs.b);
    }

};


struct Pixel {
    RGBColor color;
    Vector2D pos;

    Pixel(Vector2D p, RGBColor c): color(c), pos(p) {}

};


class Image: public Shape {
private:
    std::vector<std::vector<Pixel>> pixels;
protected:
    Vector2D start;
    Vector2D dimensions;

public:
    Image(std::string filename);

    void draw() const override;

    double calculateArea() const override;
    double calculatePerimeter() const override;
};

void readPNG(std::string filename, std::vector<std::vector<Pixel>> &pixels);
void readBMP(std::string filename, std::vector<std::vector<Pixel>> &pixels);

#endif //GAMEENGINE_IMAGE_H
