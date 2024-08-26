#include <iostream>
using namespace std;

const double PI = 3.1415926535;


class Shape {
    public:
        virtual ~Shape() {};
        virtual double GetArea() const = 0;
        virtual void Resize(double factor) = 0;
};


// Shape을 상속받음
class Circle : public Shape {
    private:
        double r;
    
    public:
        Circle(double r) : r(r) {}

        double GetArea() const {
            return r * r * PI;
        }

        void Resize(double factor) {
            r *= factor;
        }
};


// Shape을 상속받음
class Rectangle : public Shape {
    private:
        double a, b;
    
    public:
        Rectangle(double a, double b) : a(a), b(b) {}

        double GetArea() const {
            return a * b;
        }

        void Resize(double factor) {
            a *= factor;
            b *= factor;
        }
};


int main() {
    // Shape을 가리키는 포인터 배열을 통해, 두 종류의 도형을 한 번에 배열에 담을 수 있다.
    Shape* shapes[] = { new Circle(1), new Rectangle(1, 2) };
    
    for (Shape* s : shapes) {
        s->Resize(2);
    }

    for (Shape* s : shapes) {
        cout << s->GetArea() << endl;
    }

    for (Shape* s : shapes) {
        delete s;
    }
}