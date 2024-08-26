#include <iostream>
using namespace std;

// 구조체
struct Animal {
    float xpos = 1;
    float ypos = 2;
};

// 구조체 상속
struct FlyingAnimal : public Animal {
    float zpos = 3;
};

// 구조체 포인터를 Animal* arr 포인터를
void printAnimals1(FlyingAnimal* arr, int n) { 
    for (int i = 0; i < n; i++) {
        cout << "(" << arr[i].xpos << ", " << arr[i].ypos << ")" << endl;
        cout << "("  << arr[i].zpos << ")" << endl; 
    }
}

// 구조체 포인터를 Animal* arr 포인터를
void printAnimals2(Animal* arr, int n) { 
    for (int i = 0; i < n; i++) {
        cout << "(" << arr[i].xpos << ", " << arr[i].ypos << ")" << endl;
        // cout << "("  << arr[i].zpos << ")" << endl; // 왜 안되지? -> 인자의 인스턴스를 Animal로 받기 때문
    }
}

int main() {
    // 구조체 사이즈 5만큼 동적 할당으로 포인터 변수 선언
    FlyingAnimal* arr = new FlyingAnimal[5];
    // 구조체 포인터 변수를 인자로 전달
    printAnimals1(arr, 5);
    printAnimals2(arr, 5);
    // 메모리 해제
    delete[] arr;
}