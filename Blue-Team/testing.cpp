////
//// Created by Thomas Stockham on 4/18/18.
////
//
//#include <iostream>
//#include "shapes.h"
//#include "graphics.h"
//#include "fueltank.h"
//
//using namespace std;
//
//int main() {
//    /********** TESTING FOR RECT CLASS ***********/
//
//    //default constructor testing
//    Rect r;
//    if (r.getCenter().x != 0 && r.getCenter().y != 0) {
//        cout << "FAILED rectangle default constructor point test" << endl;
//    }
//    if (r.getArea() != 0) {
//        cout << "FAILED Rectangle default constructor area test" << endl;
//    }
//    if (r.getFill().red != 0 && r.getFill().blue != 0 && r.getFill().green != 0) {
//        cout << "FAILED Rectanble default constructor fill test" << endl;
//    }
//    if (r.getPerimeter() != 0) {
//        cout << "FAILED Rectangle default constructor perimeter test" << endl;
//    }
//    //non-default testing 1
//    Rect r1(0.0, 0.0);
//    r1.setDimensions(2, 2);
//    if (r1.getWidth() != 2 && r1.getHeight() != 2) {
//        cout << "FAILED rect non-default constructor getwidth/setdim test" << endl;
//    }
//
//    if (r1.getPerimeter() != 0) {
//        cout << "FAILED shape non-default constructor perimeter test" << endl;
//    }
//
//    // Getters and setters testing
//    r.setPoint({1, 1});
//    if (r.getCenter().x != 1 && r.getCenter().y != 1) {
//        cout << "FAILED shape getter and setter point 1-val test" << endl;
//    }
//    r.setPoint(2, 2);
//    if (r.getCenter().x != 2 && r.getCenter().y != 2) {
//        cout << "FAILED shape getter and setter point 2-val test" << endl;
//    }
//    r.move(2, 2);
//    if (r.getCenter().x != 4 && r.getCenter().y != 4) {
//        cout << "FAILED shape getter and setter move test" << endl;
//    }
//    if (r.getPerimeter() != 8) {
//        cout << "FAILED rect perimiter test" << endl;
//    }
//    if (r.getArea() != 4) {
//        cout << "FAILED shape area test" << endl;
//    }
//
//    /*************** TESTING FOR CIRCLE CLASS *************/
//
//    Circle c;
//    if (c.getCenter().x != 0 && c.getCenter().y != 0) {
//        cout << "FAILED circle default constructor point test" << endl;
//    }
//    if (c.getArea() != 0) {
//        cout << "FAILED circle default constructor area test" << endl;
//    }
//    if (c.getFill().red != 0 && c.getFill().blue != 0 && c.getFill().green != 0) {
//        cout << "FAILED Circle default constructor fill test" << endl;
//    }
//    if (c.getPerimeter() != 0) {
//        cout << "FAILED Circle default constructor perimeter test" << endl;
//    }
//    //non-default
//    Circle c1(10);
//    if (c1.getCenter().x != 0 && c1.getCenter().y != 0) {
//        cout << "FAILED circle non-default constructor point test" << endl;
//    }
//    if (c1.getArea() != PI * 10 * 10) {
//        cout << "FAILED circle non-default constructor area test" << endl;
//    }
//    if (c1.getFill().red != 0 && c1.getFill().blue != 0 && c1.getFill().green != 0) {
//        cout << "FAILED Circle non-default constructor fill test" << endl;
//    }
//    if (c1.getPerimeter() != 2 * PI * 10) {
//        cout << "FAILED Circle non-default constructor perimeter test" << endl;
//    }
//
//    Circle c2(10, {1, 1});
//    if (c2.getCenter().x != 1 && c2.getCenter().y != 1) {
//        cout << "FAILED circle non-default constructor point test" << endl;
//    }
//    Circle c3(10, 2, 2);
//    if (c3.getCenter().x != 2 && c3.getCenter().y != 2) {
//        cout << "FAILED circle non-default constructor two-val point test" << endl;
//    }
//    Circle c4(3, 3);
//    if (c4.getCenter().x != 3 && c4.getCenter().y != 3) {
//        cout << "FAILED circle non-default constructor two-val point test" << endl;
//    }
//
//    /************* TESTING FOR ROCKET CLASS ************/
//
//    Rocket rock;
//    if (rock.getHullStat() != notDamaged) {
//        cout << "FAILED rocket default constructor hullstatus" << endl;
//    }
//    if (rock.getFuelTank() != 100) {
//        cout << "FAILED rocket default constructor FuelTank" << endl;
//    }
//    rock.setFuelTank(20);
//    if (rock.getFuelTank() != 20) {
//        cout << "FAILED rocket default constructor getter/setter FuelTank" << endl;
//    }
//    rock.setFuelTankToFull();
//    if (rock.getFuelTank() != 100) {
//        cout << "FAILED rocket default constructor getter/setter FuelTank" << endl;
//    }
//    rock.sethullStat(Damaged);
//    if (rock.getHullStat() != Damaged) {
//        cout << "FAILED rocket default constructor getter/setter HullStat" << endl;
//    }
//    rock.move(0,0);
//    if (rock.getCenter().x != 0 && rock.getCenter().y!= 0){
//        cout << "FAILED rocket default constructor getter/setter point test" << endl;
//    }
//    /********** ASTEROID TESTING *************/
//
//    Asteroid a1(10);
//    if (a1.getCenter().x != 0 && a1.getCenter().y != 0) {
//        cout << "FAILED asteroid non-default constructor point test" << endl;
//    }
//    if (a1.getArea() != PI * 10 * 10) {
//        cout << "FAILED asteroid non-default constructor area test" << endl;
//    }
//    if (a1.getFill().red != 0 && a1.getFill().blue != 0 && a1.getFill().green != 0) {
//        cout << "FAILED asteroid non-default constructor fill test" << endl;
//    }
//    if (a1.getPerimeter() != 2 * PI * 10) {
//        cout << "FAILED asteroid non-default constructor perimeter test" << endl;
//    }
//
//    Asteroid a2(10, {1, 1});
//    if (a2.getCenter().x != 1 && a2.getCenter().y != 1) {
//        cout << "FAILED asteroid non-default constructor point test" << endl;
//    }
//    Asteroid a3(10, 2, 2);
//    if (a3.getCenter().x != 2 && a3.getCenter().y != 2) {
//        cout << "FAILED asteroid non-default constructor two-val point test" << endl;
//    }
//    Circle a4(3, 3);
//    if (a4.getCenter().x != 3 && a4.getCenter().y != 3) {
//        cout << "FAILED asteroid non-default constructor two-val point test" << endl;
//    }
//    /*********** PLANET TESTING **************/
//    Planet p1(10);
//    if (p1.getCenter().x != 0 && p1.getCenter().y != 0) {
//        cout << "FAILED planet non-default constructor point test" << endl;
//    }
//    if (p1.getArea() != PI * 10 * 10) {
//        cout << "FAILED planet non-default constructor area test" << endl;
//    }
//    if (p1.getFill().red != 0 && p1.getFill().blue != 0 && p1.getFill().green != 0) {
//        cout << "FAILED planet non-default constructor fill test" << endl;
//    }
//    if (p1.getPerimeter() != 2 * PI * 10) {
//        cout << "FAILED planet non-default constructor perimeter test" << endl;
//    }
//
//    Planet p2(10, {1, 1});
//    if (p2.getCenter().x != 1 && p2.getCenter().y != 1) {
//        cout << "FAILED planet non-default constructor point test" << endl;
//    }
//    Planet p3(10, 2, 2);
//    if (p3.getCenter().x != 2 && p3.getCenter().y != 2) {
//        cout << "FAILED planet non-default constructor two-val point test" << endl;
//    }
//    Circle p4(3, 3);
//    if (p4.getCenter().x != 3 && p4.getCenter().y != 3) {
//        cout << "FAILED planet non-default constructor two-val point test" << endl;
//    }
//    /*********FUEL TANK TESTING **************/
//
//    fuelTank f;
//
//    if (f.getFuel()!= 5){
//        cout << "FAILED fuelTank default constructor init/getFuel test" << endl;
//    }
//    f.setFuel(400);
//    if (f.getFuel()!= 400){
//        cout << "FAILED fuelTank default constructor init/setFuel test" << endl;
//    }
//    f.useFuel();
//    if(f.getFuel()!= 399){
//        cout << "FAILED fuelTank usefuel" << endl;
//    }
//}
