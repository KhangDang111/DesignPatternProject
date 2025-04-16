#include <iostream>
#include <vector>
using namespace std;

class Circle;
class Rectangle;

class ShapeVisitor {
public:
    virtual void visitCircle(Circle *circle) = 0;
    virtual void visitRectangle(Rectangle *rectangle) = 0;
};

class Shape {
public:
    virtual void accept(ShapeVisitor *visitor) = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    double getRadius() { return radius; }
    void accept(ShapeVisitor *visitor) {
        visitor->visitCircle(this);
    }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    double getWidth()  { return width; }
    double getHeight()  { return height; }
    void accept(ShapeVisitor *visitor)  {
        visitor->visitRectangle(this);
    }
};

class AreaCalculator : public ShapeVisitor {
private:
    double totalArea;
public:
    AreaCalculator() : totalArea(0) {}
    void visitCircle(Circle *circle) {
        cout<<"Call area circle";
    }
    void visitRectangle(Rectangle *rectangle)  {
        cout<<"Call area rectangle";
    }
};

class PerimeterCalculator : public ShapeVisitor {
private:
    double totalPerimeter;
public:
    PerimeterCalculator() : totalPerimeter(0) {}
    void visitCircle(Circle *circle) {
        cout<<"Call perimeter circle";
    }
    void visitRectangle(Rectangle *rectangle)  {
        cout<<"Call perimeter rectangle";
    }
};

int main() {
    vector<Shape*> shapes;
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(5,10));
    shapes.push_back(new Circle(5));
    
    AreaCalculator areaCalculator;
    PerimeterCalculator perimeterCalculator;

    for (Shape *shape : shapes) {
        shape->accept(&areaCalculator);
        shape->accept(&perimeterCalculator);
    }
}


