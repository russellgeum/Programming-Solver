#include <iostream>

// C++은 같은 함수 이름을 사용할 수 있다.
int add(int a) {
    return a;
}

int add(int a, int b) {
    return a + b;
}

int main() {
   int b = add(2);
   int c = add(3, 6);

   std::cout << b << " " << c << std::endl; 
}