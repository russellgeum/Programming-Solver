#include <iostream>

struct ProductInfo {
    int num;
    char name[100];
    int cost;
};

int main() {
    ProductInfo myProduct = {479283, "한라봉", 1990};

    std::cout << myProduct.num << std::endl;
}