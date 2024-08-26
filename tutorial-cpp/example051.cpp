#include <iostream>
#include <memory>  // 스마트 포인터가 선언된 라이브러리
using namespace std;

class MyClass {
    private:
        int x;
    public:
        MyClass(int x) : x(x) {
            cout << "MyClass(int)" << endl;
        }
        ~MyClass() {
            cout << "~MyClass()" << endl;
        }
        int GetX() const { return x; }
};

int main() {
    // MyClass의 인스턴스를 변수 a에 할당하고, 이를 unique_ptr<MyClass>로 래핑
    unique_ptr<MyClass> a(new MyClass(5));
    // a가 가리키는 객체의 GetX() 메서드 호출
    cout << a->GetX() << endl;
    cout << "===== 1 =====" << endl;
    // a가 가리키는 객체를 해제하고, 새로운 객체를 할당
    a.reset(new MyClass(7));
    cout << a->GetX() << endl;
    cout << "===== 2 =====" << endl;
    // a가 가리키던 객체만 해제하고 아무것도 새로 가리키지는 않음
    a.reset(); 
    cout << "===== 3 =====" << endl;
    // a가 가리키는 객체를 해제하고, 새로운 객체를 할당
    a.reset(new MyClass(9));
    cout << "===== 4 =====" << endl;
}