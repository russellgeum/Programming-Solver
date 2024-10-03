#include <iostream>
using namespace std;

struct Person {
    int age;  // 나이
    virtual ~Person() {}  // 다형적 클래스로 만들어주기 위한 가상 소멸자
    void Eat() {
        cout << "먹는다..." << endl;
    }
};

struct Student : virtual Person {  // 가상 상속
    void Study() {
        cout << "공부한다..." << endl;
    }
};

struct Worker : virtual Person {   // 가상 상속
    void Work() {
        cout << "일한다..." << endl;
    }
};

struct Researcher : Student, Worker {};


// Person -> Student -> Researcher
//        -> Worker ->
int main() {
    // Researcher가 보는 입장에서 void Eat()는 중복되는 메서드임
    // 목적은 Studnet, Worker 등으로 인해서 생기는 중복 메서드의 모호성을 제거하기 위함
    Researcher r;
    r.age = 20;

    cout << r.age << endl;
    cout << r.Student::age << endl;
    cout << r.Worker::age << endl;
    cout << r.Person::age << endl;

    r.Eat();
}