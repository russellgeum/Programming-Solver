#include <iostream>

struct ProductInfo {
    int num;
    int cost;
};

// 변수의 주소를 포인터 변수로 받음
void prodcutSwap(ProductInfo *a, ProductInfo *b) {
    ProductInfo tmp = *a; // 포인터 변수를 할당하였으므로 tmp는 포인터
    *a = *b;
    *b = tmp;
}

int main() {
    ProductInfo product1 = {100, 200};
    ProductInfo product2 = {300, 500};

    // ProductInfo Test = product1;
    ProductInfo *Test = &product1;

    std::cout << product1.cost << product1.num << std::endl;
    std::cout << product2.cost << product2.num << std::endl;
    
    prodcutSwap(&product1, &product2);
    std::cout << product1.cost << product1.num << std::endl;
    std::cout << product2.cost << product2.num << std::endl;
}