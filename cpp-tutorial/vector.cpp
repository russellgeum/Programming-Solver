#include <iostream>
#include <vector>

int main() {
    std::vector<int> arrVector {1, 1, 1};
    arrVector.push_back(10);
    arrVector.push_back(5);
    std::cout << arrVector.back() << std::endl;
    arrVector.pop_back();
    std::cout << arrVector.back() << std::endl;
    
    std::cout << " " << std::endl;
    for (auto num : arrVector) {
        std::cout << num << std::endl;
    }

    return 0;
}