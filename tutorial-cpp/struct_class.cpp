#include <iostream>
#include <map>
#include <vector>


// 상품 정보 클래스
class Product {
    private:
        struct ProductInfo {
            std::string name;
            int num;    
            int cost;
        };
        ProductInfo *ptrProductInfo;  // 구조체 포인터 멤버

    public:
        // 생성자
        Product(std::string name, int num, int cost);
        // 소멸자
        ~Product();

        // 기능 1: 상품 정보 출력
        void printProductInfo();
        // 기능 2: 상품 정보 변경
        void changeProductInfo(std::string name, int num, int cost);
};

Product::Product(std::string name, int num, int cost) {
    ptrProductInfo = new ProductInfo; 
    ptrProductInfo->name = name;
    ptrProductInfo->num = num;
    ptrProductInfo->cost = cost;
}

Product::~Product() {
    // 소멸자에서 동적으로 할당된 메모리 해제
    delete ptrProductInfo;
    std::cout << "소멸자 호출" << std::endl;
}

// 상품 정보 출력
void Product::printProductInfo() {
    std::cout << "상품명:   " << ptrProductInfo->name << std::endl;
    std::cout << "상품번호: " << ptrProductInfo->num << std::endl;
    std::cout << "상품가격: " << ptrProductInfo->cost << std::endl;
    std::cout << std::endl;
}

// 상품 정보 변경
void Product::changeProductInfo(std::string name, int num, int cost) {
    ptrProductInfo->name = name;
    ptrProductInfo->num = num;
    ptrProductInfo->cost = cost;
}


// 상품 데이터베이스 클래스
class ProductDataBase {
    private:
        std::map<int, Product> mapProduct;

    public:
        void addProduct(int num, Product product);
        void deleteProduct(int num);
        void printProduct(int num);    
};

// 상품 데이터베이스에 상품 추가
void ProductDataBase::addProduct(int num, Product product) {
    mapProduct.insert(std::pair<int, Product>(num, product));
}

// 상품 데이터베이스에서 상품 삭제
void ProductDataBase::deleteProduct(int num) {
    mapProduct.erase(num);
}

// 상품 데이터베이스에서 상품 출력
void ProductDataBase::printProduct(int num) {
    // 상품 데이터베이스에서 상품 찾기 -> iterator는 포인터인가?
    std::map<int, Product>::iterator iter;
    iter = mapProduct.find(num);
    
    // 상품이 있으면 상품 정보 출력
    if (iter != mapProduct.end()) {
        iter->second.printProductInfo();
    }
    else {
        std::cout << "상품이 없습니다." << std::endl;
    }
}


int main() {
    Product myProduct = Product("한라봉", 479283, 1990);
    // 상품 정보 출력
    myProduct.printProductInfo();

    // 상품 정보 변경
    myProduct.changeProductInfo("천혜향", 479285, 2500);
    myProduct.printProductInfo();

    return 0;
}