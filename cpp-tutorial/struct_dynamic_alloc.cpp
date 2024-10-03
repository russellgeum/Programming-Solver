#include <iostream>
using namespace std;

// 구조체
struct Animal {
    float xpos = 1;
    float ypos = 2;
    virtual ~Animal() {}
};

// Animal을 상속받는 구조체
struct FlyingAnimal : public Animal {
    float zpos = 3;
};

// Animal 포인터의 포인터 a를 인자로 받음
void printAnimals(Animal** a, int n) {
    for (int i = 0; i < n; i++) {
        cout << "(" << a[i]->xpos << ", " << a[i]->ypos << ")" << endl;
    }
}

int main() {
    // 동적할당 Animal을 5개 저장할 수 있는 포인터의 포인터 변수 a를 선언
    Animal** a = new Animal * [5];
    // 포인터의 포인터 원소마다 new FlyingAnimal을 저장
    for (int i = 0; i < 5; i++) {
        a[i] = new FlyingAnimal;
    }
    printAnimals(a, 5);

    Animal** b = new Animal * [5];
    for (int i = 0; i < 5; i++) {
        b[i] = new Animal;
    }
    printAnimals(b, 5);

    for (int i = 0; i < 5; i++) {
        delete a[i];  // 각 칸마다 할당된 객체가 있으므로 각 칸마다 해제한다.
    }
    delete[] a;       // 포인터 배열을 삭제한다.
}