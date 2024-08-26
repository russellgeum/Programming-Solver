#include <iostream>
using namespace std;

// 클래스의 private에서 변수 선언을 할 수 없음
// public에서 클래스 선언을 할때 인자를 초기화함
class MyClass {
    private:
        int testVal;
    
    public:
        MyClass() {
            testVal = 5;
        }
        MyClass(int inputVal) {
            testVal = inputVal;
        }

        int x;

        void PrintThis() {
            cout << "나의 주소는 " << this << endl;
            cout << "변수 testVal의 값은 " << this->testVal << endl;
        }
};

int main() {
    MyClass a(500);
    MyClass b(100);
    MyClass c;
    
    cout << "객체 a의 주소는 " << &a << endl;
    cout << "객체 b의 주소는 " << &b << endl;
    cout << "객체 a의 주소는 " << &c << endl;

    a.PrintThis();
    b.PrintThis();
    c.PrintThis();
}