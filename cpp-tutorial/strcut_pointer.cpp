#include <iostream>
using namespace std;

struct Base {
    int a = 1;
    virtual ~Base() {}
};

struct Drv1 : Base {
    void f() {
        cout << "Drv1::f()" << endl;
        cout << x << endl;
    }
    float x = 3.14;
};

struct Drv2 : Base {
    void f() {
        cout << "Drv2::f() " << endl;
        cout << y << endl;
    }
    int y = 3;
};

int main() {
    // Drv1 타입의 동적 객체를 Base 타입의 포인터변수 b에 할당한다.
    // Drv1가 Base를 상속받는 다는 함의가 있어야 가능하다.
    // 다형성, 정적 캐스팅, 동적 캐스팅을 잘 이해하기
    Base* b = new Drv1;

    Drv1* d1 = static_cast<Drv1*>(b);  // 올바른 다운캐스팅
    Drv2* d2 = static_cast<Drv2*>(b);  // 잘못된 다운캐스팅

    d1->f();
    d2->f();

    delete b;
}