// 정적할당과 동적할당
#include <iostream>
using namespace std;

class Vector {
    private:
        float x, y;

    public:
        Vector() : x(0), y(0) {
            cout << this << " : Vector()" << endl;
        }
        Vector(float x, float y) : x(x), y(y) {
            cout << this << " : Vector(float, float)" << endl;
        }
        ~Vector() {
            cout << this << " : ~Vector()" << endl;
        }
        float GetX() const { return x; }
        float GetY() const { return y; }
};


int main() {
    cout << "main 시작" << endl;

    // 정적 할당
    Vector s1;
    Vector s2(2, 3);
    
    // 동적 할당
    Vector* d1 = new Vector;
    Vector* d2 = new Vector(4, 5);

    cout << "(" << d1->GetX() << ", " << d1->GetY() << ")" << endl;
    cout << "(" << d2->GetX() << ", " << d2->GetY() << ")" << endl;

    delete d1;
    delete d2;

    cout << "main 끝" << endl;
}