#include <iostream>
using namespace std;


// 구체적인 구현을 포함하지 않고, 가상 함수를 선언
// 어떤 클래스가 이 부모 클래스를 상속받는 다면, 순수 가상 함수를 모두 구현해야 함
class IPerson {
    public:
        virtual ~IPerson() {}
        virtual void Eat() = 0;
        virtual void SetAge(int age) = 0;
        virtual int GetAge() = 0;
};

// 가상 상속 이유: 부모 클래스 IPerson의 단일 인스턴스를 유지하기 위함
class IStudent : public virtual IPerson {
    public:
        virtual void Study() = 0;
};

class IWorker : public virtual IPerson {
    public:
        virtual void Work() = 0;
};

// IStudent, IWorker를 상속받으며, 모든 순수 가상 함수를 구체적으로 구현
class Researcher : public IStudent, public IWorker {
    private:
        int age;
    public:
        void Eat() {
            cout << "¸Ô´Â´Ù..." << endl;
        }
        void Study() {
            cout << "°øºÎÇÑ´Ù..." << endl;
        }
        void Work() {
            cout << "ÀÏÇÑ´Ù..." << endl;
        }
        void SetAge(int age) { this->age = age; }
        int GetAge() { return age; }
};


int main() {
    // r은 Researcher의 객체이고, 컴파일 시점에 r은 Researcher의 SetAge()를 호출하는 것
    // 정적 바인딩: 컴파일 시점에 결정
    Researcher r;
    r.SetAge(20);
    cout << r.GetAge() << endl;

    // C++ 다형성 예시
    // IPerson의 인터페이스를 통해 제공되는 메서드, SetAge, GetAge 등을 활용 가능
    // p는 IPerson의 포인터이고 SetAge는 IPerson을 통해 호출
    // 동적 바인딩: 런타임 시점에 결정
    IPerson* p = new Researcher;
    p->SetAge(20);
    cout << p->GetAge() << endl;
    delete p;
}