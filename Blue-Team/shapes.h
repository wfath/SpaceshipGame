//
// Created by Thomas Stockham on 4/5/18.
//

#ifndef CS120A_SHAPES_SHAPES_H
#define CS120A_SHAPES_SHAPES_H

#include "fueltank.h"

const double PI = 3.14159265358979;

// colors in OpenGL are stored in three (r, g, b) values
// with each on a [0,1] scale
// e.g. salmon is (250, 128, 114), which we would store as
// (250/255.0, 128/255.0, 114/255.0)
struct color {
    double red;
    double green;
    double blue;
};

struct point {

    // these fields are public by default
    int x;
    int y;

    point();
    point(int xIn, int yIn);
};
enum hullStatus {notDamaged, Damaged, veryDamaged, Destroyed};

//Enum used to determine which direction the Rocket should move in
enum direction {up, down, left, right};


// Note: a line is not considered a shape because it
//       does not have an area
// Note: this is an abstract class
class Shape {
public:
    // Constructors
    Shape();
    Shape(point c, color f);
    Shape(int xIn, int yIn, double r, double g, double b);

    // Getters
    point getCenter() const;
    double getArea() const;
    double getPerimeter() const;
    color getFill() const;

    // Setters
    void setPoint(point c);
    void setPoint(int xIn, int yIn);
    void move(int deltaX, int deltaY);

    void setColor(color f);
    void setColor(double r, double g, double b);
    // Note: no setters for area or perimeter
    // because those will be calculated in child classes
    // based on fields (radius, length and width, etc.)

    // pure virtual method is explicitly undefined
    virtual void draw() const = 0;
protected:
    double area;
    double perimeter;

    point center;
    color fill;

    // helper methods to calculate and set area and perimeter
    // pure virtual, defined in each subclass
    virtual void calculateArea() = 0;
    virtual void calculatePerimeter() = 0;
};

class Circle : public Shape {
protected:
    double radius;

    void calculateArea() override;
    void calculatePerimeter() override;

public:
    // Constructors
    Circle();
    explicit Circle(double rad);
    Circle(double rad, point c);
    Circle(double rad, int xIn, int yIn);
    explicit Circle(point c);
    Circle(int xIn, int yIn);
    explicit Circle(color f);
    Circle(double r, double g, double b);
    Circle(double rad, point c, color f);
    Circle(double rad, int xIn, int yIn, double r, double g, double b);
    // Note: area and perimeter are not input
    // but should be calculated when radius is input

    // Getter
    double getRadius() const;

    // Setter
    void setRadius(double rad);

    void draw() const override;
};

class Asteroid : public Shape {
protected:
    double radius;
    void calculateArea() override;
    void calculatePerimeter() override;
public:
    Asteroid();
    explicit Asteroid(double rad);
    Asteroid(double rad, point c);
    Asteroid(double rad, int xIn, int yIn);
    explicit Asteroid(point c);
    Asteroid(int xIn, int yIn);
    explicit Asteroid(color f);
    Asteroid(double r, double g, double b);
    Asteroid(double rad, point c, color f);
    Asteroid(double rad, int xIn, int yIn, double r, double g, double b);

    // Getter
    double getRadius() const;

    // Setter
    void setRadius(double rad);

    void draw() const override;
};

class Planet : public Shape {
protected:
    double radius;

    void refuel();
    void calculateArea() override;
    void calculatePerimeter() override;
public:
    Planet();
    explicit Planet(double rad);
    Planet(double rad, point c);
    Planet(double rad, int xIn, int yIn);
    explicit Planet(point c);
    Planet(int xIn, int yIn);
    explicit Planet(color f);
    Planet(double r, double g, double b);
    Planet(double rad, point c, color f);
    Planet(double rad, int xIn, int yIn, double r, double g, double b);

    // Getter
    double getRadius() const;

    // Setter
    void setRadius(double rad);

    void draw() const override;
};

class Rect : public Shape {
private:
    double length;
    double height;
    point topRight;
    point topLeft;
    point bottomRight;
    point bottomLeft;


    void calculateArea() override;
    void calculatePerimeter() override;

public:
    // Constructors
    Rect();
    Rect(double l, double h);
    void rotate(double degrees);
    Rect(double l, double h, point c);
    Rect(double l, double h, int xIn, int yIn);
    explicit Rect(point c);
    Rect(int xIn, int yIn);
    explicit Rect(color f);
    Rect(double r, double g, double b);
    Rect(double l, double h, point c, color f);
    Rect(double l, double h, int xIn, int yIn, double r, double g, double b);
    // Note: area and perimeter are not input
    // but should be calculated when length and width are input

    // Getters
    double getHeight() const;
    double getWidth() const;

    // Setter
    // Note: this method will also recalculate area and perimeter
    void setDimensions(double l, double h);

    void draw() const override;
};
/******** ROCKET **********/

class Rocket : public Shape {
private:

    double length;
    double height;
    void calculateArea() override;
    void calculatePerimeter() override;
    //Center coordinates for the rocket
public:

    //Default Constructor for the rocket. Note, this
    //is the only constructor, and will assemble and draw all the
    //shapes to the correct dimensions for the parts.
    //This also initializes the rocket fuel supply to full.
    Rocket();


    //getters

    double getHeight() const;
    double getWidth() const;

    // Setter
    // Note: this method will also recalculate area and perimeter
    void setDimensions(double l, double h);


    void draw() const override;
};






#endif //CS120A_SHAPES_SHAPES_H