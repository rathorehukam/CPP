









#include <iostream>
using namespace std;

class Point {
protected:
    int x;
    int y;

public:
    Point(int _x, int _y) : x(_x), y(_y) {}

    void setX(int _x) {
        x = _x;
    }

    void setY(int _y) {
        y = _y;
    }

    virtual void display() = 0;
};

class Line : public Point {
private:
    int x2;
    int y2;

public:
    Line(int x1, int y1, int _x2, int _y2) : Point(x1, y1), x2(_x2), y2(_y2) {}

    void setX2(int _x2) {
        x2 = _x2;
    }

    void setY2(int _y2) {
        y2 = _y2;
    }

    void display() {
        cout << "The line is:" << endl;
        cout << "Start point: (" << x << "," << y << ")" << endl;
        cout << "End point: (" << x2 << "," << y2 << ")" << endl;
    }
};

int main() {
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;

    Line line(x1, y1, x2, y2);
    line.display();

    return 0;
}
