#include <iostream>
#include <cstring>

struct Point {
    int x, y;

    Point () : x(), y() {}
    Point (int _x, int _y) : x(_x), y(_y) {}
};

class Shape {
    private:

    int vertices;
    Point** points;

    public: 

    Shape (int _vertices) {
        vertices = _vertices;
        points = new Point*[vertices+1];
    }

    ~Shape () {
    }

    void addPoints (Point* pts) {
        for (int i = 0; i <= vertices; i++) {
            memcpy(points[i], &pts[i%vertices], sizeof(Point));
        }
    }

    double* area () {
        int temp = 0;
        for (int i = 0; i <= vertices; i++) {
            // 2 ways to access member:
            // - Use -> on pointers
            // - Use . on dereferenced pointers

            int lhs = points[i]->x * points[i+1]->y;
            int rhs = (*points)[i+1].x * (*points)[i].y;
            temp += (lhs - rhs);
        }
        double* area = new double(abs(temp)/2.0);
        return area;
    }
};

int main () {
    // 3 ways to define struct:
    // - Default Constructor
    // - Constructor with Parameters
    // - Copy Constructor

    Point tri1 = Point();
    tri1.x = 0;
    tri1.y = 0;
    Point tri2 = Point(1,2);
    Point tri3 = tri1;
    tri3.x = 2;

    // adding points to tri
    Point triPts[3] = {tri1, tri2, tri3};
    Shape* tri = new Shape(3);
    tri->addPoints(triPts);

    // FIXME: create the following points using your preferred struct
    //        definition:
    //          quad1 = (0, 0)
    //          quad2 = (0, 2)
    //          quad3 = (2, 2)
    //          quad4 = (2, 0)
    Point quad1 = Point(0, 0);
    Point quad2 = Point(0, 2);
    Point quad3 = Point(2, 2);
    Point quad4 = Point(2, 0);

    // adding points to quad
    Point quadPts[4] = {quad1, quad2, quad3, quad4};
    Shape* quad = new Shape(4);
    quad->addPoints(quadPts);

    // FIXME: print out area of tri and area of quad
}