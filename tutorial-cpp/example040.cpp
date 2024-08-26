#include <iostream>
using namespace std;

// 구조체 Base
struct Base {
    int a = 1;
    virtual ~Base() {}
};

// 구조체 Base를 상속받는 Drv1
struct Drv1 : Base {
    float x = 3.14;
};

// 구조체 Base를 상속받는 Drv2
struct Drv2 : Drv1 {
    int y = 3;
};

int main() {
    // Base 인스턴스로 Drv1를 동적할당
    Base* b = new Drv1;
    cout << b->a << endl;

    // Drv1를 타입 캐스트하여 Drv1의 포인터로 변경함
    Drv1* d1 = static_cast<Drv1*>(b);
    cout << d1->x << endl;
    delete b;
}