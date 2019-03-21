//
// Created by Thomas Stockham on 4/5/18.
//

#include "shapes.h"
#include "graphics.h"
#include "math.h"


/******************** point struct ********************/

point::point() : x(0), y(0) { }

point::point(int xIn, int yIn) : x(xIn), y(yIn) { }

/******************** Shape class ********************/

Shape::Shape() : area(0), perimeter(0),
                 center({0, 0}), fill({0, 0, 0}) {
    // color defaults to black
}

Shape::Shape(point c, color f) : area(0), perimeter(0),
                                 center(c), fill(f) { }

Shape::Shape(int xIn, int yIn, double r, double g, double b) :
        area(0), perimeter(0), center({xIn, yIn}), fill({r, g, b}) { }

point Shape::getCenter() const {
    return center;
}

double Shape::getArea() const {
    return area;
}

double Shape::getPerimeter() const {
    return perimeter;
}

color Shape::getFill() const {
    return fill;
}

void Shape::setPoint(point c) {
    center = c;
}

void Shape::setPoint(int xIn, int yIn) {
    center = {xIn, yIn};
}

void Shape::move(int deltaX, int deltaY) {
    center.x += deltaX;
    center.y += deltaY;
}


void Shape::setColor(color f) {
    fill = f;
}

void Shape::setColor(double r, double g, double b) {
    fill = {r, g, b};
}

/******************** Circle class ********************/

void Circle::calculateArea() {
    // A = pi*r^2
    area = PI * radius * radius;
}

void Circle::calculatePerimeter() {
    // Circumference = 2*pi*r
    perimeter = 2.0 * PI * radius;
}

Circle::Circle() : Shape(), radius(0) { }

Circle::Circle(double rad) : Shape() {
    // radius not in initializer list because
    // we want to check for value >= 0
    setRadius(rad);
}

Circle::Circle(double rad, point c) : Shape(c, {0, 0, 0}) {
    setRadius(0);
}

Circle::Circle(double rad, int xIn, int yIn) :
        Shape(xIn, yIn, 0, 0, 0) {
    setRadius(rad);
}

Circle::Circle(point c) : Shape(c, {0, 0, 0}), radius(0) { }

Circle::Circle(int xIn, int yIn) : Shape(xIn, yIn, 0, 0, 0),
                                   radius(0) { }

Circle::Circle(color f) : Shape({0, 0}, f), radius(0) { }

Circle::Circle(double r, double g, double b) :
        Shape({0, 0}, {r, g, b}), radius(0) { }

Circle::Circle(double rad, point c, color f) : Shape(c, f) {
    setRadius(rad);
}

Circle::Circle(double rad,
               int xIn, int yIn,
               double r, double g, double b) :
        Shape(xIn, yIn, r, g, b) {
    setRadius(rad);
}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double rad) {
    // radius should not be negative
    radius = (rad < 0) ? 0 : rad;
    // now recalculate area and perimeter
    calculateArea();
    calculatePerimeter();
}

void Circle::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(center.x, center.y);
    //glColor3f(0.7,0.7,0.8);
    for(double i =0;i<=2.0*PI+0.05;i+=(2.0*PI/360.0)){
        glVertex2i(center.x+(radius*cos(i)), center.y+(radius*sin(i)));
    }
    glEnd();
}

/******************** Planet class ********************/
void Planet::refuel(){

}

void Planet::calculateArea() {
    // A = pi*r^2
    area = PI * radius * radius;
}

void Planet::calculatePerimeter() {
    // Circumference = 2*pi*r
    perimeter = 2.0 * PI * radius;
}

Planet::Planet() : Shape(), radius(0){
}

Planet::Planet(double rad) : Shape() {
    // radius not in initializer list because
    // we want to check for value >= 0
    setRadius(rad);
}

Planet::Planet(double rad, point c) : Shape(c, {0, 0, 0}) {
    setRadius(0);
}

Planet::Planet(double rad, int xIn, int yIn) :
        Shape(xIn, yIn, 0, 0, 0) {
    setRadius(rad);
}

Planet::Planet(point c) : Shape(c, {0, 0, 0}), radius(0) { }

Planet::Planet(int xIn, int yIn) : Shape(xIn, yIn, 0, 0, 0),
                                       radius(0) { }

Planet::Planet(color f) : Shape({0, 0}, f), radius(0) { }

Planet::Planet(double r, double g, double b) :
        Shape({0, 0}, {r, g, b}), radius(0) { }

Planet::Planet(double rad, point c, color f) : Shape(c, f) {
    setRadius(rad);
}

Planet::Planet(double rad,
                   int xIn, int yIn,
                   double r, double g, double b) :
        Shape(xIn, yIn, r, g, b) {
    setRadius(rad);
}

double Planet::getRadius() const {
    return radius;
}

void Planet::setRadius(double rad) {
    // radius should not be negative
    radius = (rad < 0) ? 0 : rad;
    // now recalculate area and perimeter
    calculateArea();
    calculatePerimeter();
}

void Planet::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(center.x, center.y);
    glColor3f(0.18,0.18,0.18);
    for(double i =0;i<=2.0*PI+0.05;i+=(2.0*PI/360.0)){
        glVertex2i(center.x+(radius*cos(i)), center.y+(radius*sin(i)));
    }
    glEnd();
}


/******************** Asteroid class ********************/

void Asteroid::calculateArea() {
    // A = pi*r^2
    area = PI * radius * radius;
}

void Asteroid::calculatePerimeter() {
    // Circumference = 2*pi*r
    perimeter = 2.0 * PI * radius;
}

Asteroid::Asteroid() : Shape(), radius(0){
}

Asteroid::Asteroid(double rad) : Shape() {
        // radius not in initializer list because
        // we want to check for value >= 0
        setRadius(rad);
}

Asteroid::Asteroid(double rad, point c) : Shape(c, {0, 0, 0}) {
    setRadius(0);
}

Asteroid::Asteroid(double rad, int xIn, int yIn) :
        Shape(xIn, yIn, 0, 0, 0) {
    setRadius(rad);
}

Asteroid::Asteroid(point c) : Shape(c, {0, 0, 0}), radius(0) { }

Asteroid::Asteroid(int xIn, int yIn) : Shape(xIn, yIn, 0, 0, 0),
                                   radius(0) { }

Asteroid::Asteroid(color f) : Shape({0, 0}, f), radius(0) { }

Asteroid::Asteroid(double r, double g, double b) :
        Shape({0, 0}, {r, g, b}), radius(0) { }

Asteroid::Asteroid(double rad, point c, color f) : Shape(c, f) {
    setRadius(rad);
}

Asteroid::Asteroid(double rad,
               int xIn, int yIn,
               double r, double g, double b) :
        Shape(xIn, yIn, r, g, b) {
    setRadius(rad);
}


double Asteroid::getRadius() const {
    return radius;
}

void Asteroid::setRadius(double rad) {
    // radius should not be negative
    radius = (rad < 0) ? 0 : rad;
    // now recalculate area and perimeter
    calculateArea();
    calculatePerimeter();
}

void Asteroid::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_TRIANGLE_FAN);
    glVertex2i(center.x, center.y);
    glColor3f(0.18,0.18,0.18);
    for(double i =0;i<=2.0*PI+0.05;i+=(2.0*PI/360.0)){
        glVertex2i(center.x+(radius*cos(i)), center.y+(radius*sin(i)));
    }
    glEnd();
}

/******************** Rect class ********************/

void Rect::calculateArea() {
    area = length * height;
}

void Rect::calculatePerimeter() {
    perimeter = 2.0 * length + 2.0 * height;
}

Rect::Rect() : Shape(), length(0), height(0) { }

Rect::Rect(double l, double h) : Shape() {
    setDimensions(l, h);
}

double Rect::getWidth() const {
    return length;
}

double Rect::getHeight() const {
    return height;
}
void Rect::rotate(double degrees){
    topRight = point(Rect().getCenter().x + length/2, Rect().getCenter().y - height/2);
    topLeft = point(Rect().getCenter().x - length/2, Rect().getCenter().y - height/2);
    bottomRight = point(Rect().getCenter().x + length/2, Rect().getCenter().y + height/2);
    bottomLeft = point(Rect().getCenter().x - length/2, Rect().getCenter().y + height/2);

    topRight.x += cos((degrees*PI)/180) - sin((degrees*PI)/180);
    topRight.y += sin((degrees*PI)/180) + cos((degrees*PI)/180);
    topLeft.x += cos((degrees*PI)/180) - sin((degrees*PI)/180);
    topLeft.y += sin((degrees*PI)/180) + cos((degrees*PI)/180);
    bottomRight.x += cos((degrees*PI)/180) - sin((degrees*PI)/180);
    bottomRight.y += sin((degrees*PI)/180) + cos((degrees*PI)/180);
    bottomLeft.x += cos((degrees*PI)/180) - sin((degrees*PI)/180);
    bottomLeft.y += sin((degrees*PI)/180) + cos((degrees*PI)/180);
}

void Rect::setDimensions(double l, double h) {
    // we do not want to accept negative values
    // for length and width
    length = (l < 0) ? 0 : l;
    height = (h < 0) ? 0 : h;
    // now update area and perimeter
    calculateArea();
    calculatePerimeter();
}

void Rect::draw() const {
    glColor3f(fill.red, fill.green, fill.blue);
    glBegin(GL_QUADS);
    //top left
    glVertex2i(center.x-(length/2.0),center.y-(height/2.0));
    //top right
    glVertex2i(center.x+(length/2), center.y-(height/2.0));

    //bottom right
    glVertex2i(center.x+(length/2),center.y+(height/2.0));

    //bottom left
    glVertex2i(center.x-(length/2.0),center.y+(height/2.0));

    glEnd();
}

/*********** ROCKET CLASS **************/
Rocket::Rocket() {
    sethullStat(notDamaged);
    setFuelTank(fuelTank1);
    setDimensions(20,40);
}


void Rocket::calculateArea() {
    area = length * height;
}
void Rocket::calculatePerimeter() {
    perimeter = 2.0 * length + 2.0 * height;
}

void Rocket::setFuelTank(fuelTank f) {
    fuelTank1 = f;
}

void Rocket::sethullStat(hullStatus h) {
    hullStat = h;
}
hullStatus Rocket ::getHullStat() const {
    return hullStat;
}

fuelTank Rocket::getFuelTank() const {
    return fuelTank1;
}

void Rocket::rockUseFuel(){
    if(getFuelTank().getFuel() > 0){
        getFuelTank().setFuel(getFuelTank().getFuel() - 1);
    }
}

double Rocket::getWidth() const {
    return length;
}

double Rocket::getHeight() const {
    return height;
}
void Rocket::setDimensions(double l, double h) {
    // we do not want to accept negative values
    // for length and width
    length = (l < 0) ? 0 : l;
    height = (h < 0) ? 0 : h;
    // now update area and perimeter
    calculateArea();
    calculatePerimeter();
}

void Rocket::draw() const{

    if(hullStat == notDamaged) {
        glColor3f(fill.red, fill.green, fill.blue);
        glBegin(GL_QUADS);
        //top left
        glVertex2i(center.x-(length/2.0),center.y-(height/2.0));
        //top right
        glVertex2i(center.x+(length/2), center.y-(height/2.0));

        //bottom right
        glVertex2i(center.x+(length/2),center.y+(height/2.0));

        //bottom left
        glVertex2i(center.x-(length/2.0),center.y+(height/2.0));

        glEnd();

        glColor3f(1.0,0,0);
        glBegin(GL_TRIANGLES);
        glVertex2i(center.x-(length/2.0), center.y-(height/2));
        glVertex2i(center.x, center.y-((height/2)+20));
        glVertex2i(center.x+(length/2), center.y-(height/2));
        glEnd();

        glColor3f(1.0,0,0);
        glBegin(GL_TRIANGLES);
        glVertex2i(center.x-(length/2.0), center.y+(height/2));
        glVertex2i(center.x-(length/2), center.y);
        glVertex2i(center.x-(length/2) - 10, center.y+(height/2));

        glEnd();

        glColor3f(1.0,0,0);
        glBegin(GL_TRIANGLES);
        glVertex2i(center.x+(length/2.0), center.y+(height/2));
        glVertex2i(center.x+(length/2), center.y);
        glVertex2i(center.x+(length/2) + 10, center.y+(height/2));

        glEnd();

        //TODO: Draw rest of rocket relative to coordinates of the baseRect
    }
}

