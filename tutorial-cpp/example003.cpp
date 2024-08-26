#include <iostream>

struct ProductInfo {
    int num;
    int cost;
};

int main() {
    ProductInfo myProduct = {100, 200};
    ProductInfo *ptrProduct = &myProduct; // myProduct를 가리키는 포인터 ptrProduct

    std::cout << (*ptrProduct).cost << std::endl;
    std::cout << (myProduct).cost << std::endl;
    std::cout << ptrProduct->cost << std::endl;
    std::cout << (&myProduct)->cost << std::endl;
}
