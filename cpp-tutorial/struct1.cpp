#include <iostream>
#include <map>
#include <vector>

// 구조체 선언과 활용법

// 일반적인 구조체 선언
struct ProductInfo {
    std::string name;
    int num;    
    int cost;
}; // 구조체 선언

void warpProductInfo(ProductInfo *ptrProduct1, ProductInfo *ptrProduct2) {
    ProductInfo temp = *ptrProduct1;
    *ptrProduct1 = *ptrProduct2;
    *ptrProduct2 = temp;
}

void printProductInfo(ProductInfo *ptr) {
    std::cout << "상품명:   " << ptr->name << std::endl;
    std::cout << "상품번호: " << ptr->num << std::endl;
    std::cout << "상품가격: " << ptr->cost << std::endl;
    std::cout << std::endl;
}


int main() {
    ProductInfo myProduct1 = {"한라봉", 479283, 1990};
    ProductInfo myProduct2 = {"레드향", 479283, 1990};
    ProductInfo *ptrProduct1 = &myProduct1;
    ProductInfo *ptrProduct2 = &myProduct2;

    std::cout << ptrProduct1->name << std::endl;
    std::cout << ptrProduct2->name << std::endl;

    // 메모리를 가리키는 포인터 변수를 넣거나, 변수의 메모리 주소를 넣거나
    // 둘 중 하나만 넣어도 된다.
    warpProductInfo(ptrProduct1, ptrProduct2);
    warpProductInfo(&myProduct1, &myProduct2);
    std::cout << ptrProduct1->name << std::endl;
    std::cout << ptrProduct2->name << std::endl;

    printProductInfo(ptrProduct1);
    printProductInfo(ptrProduct2);

    return 0;
}