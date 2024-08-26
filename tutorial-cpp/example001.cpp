#include <iostream>
#include <vector>
#include <map>

struct Test {
    float x;
    float y;
} tmp;

int main() {
    Test test = {2.5, 3.1};

    tmp.x = 5.2;
    tmp.y = 9.1;

    std::cout << test.x << " " << test.y << std::endl;
    std::cout << tmp.x << " " << tmp.y << std::endl;

    return 0;
}