#include <iostream>
using namespace std;

int square(int n) {
    return n * n;
}

int myFunc(int n) {
    return n * (n -15) / 2;
}

int arrFnMin(const int arr[], int n, int (*f)(int)) {
    int min = f(arr[0]);
    for (int i = 1; i < n; i++) {
        if (min > f(arr[i])) {
            min = f(arr[i]);
        }
    }
    return min;
}

int main() {
    int arr[7] = {1, 2, 3, 4, 5, 6, 7};
    cout << arrFnMin(arr, 7, square) << endl;
    cout << arrFnMin(arr, 7, myFunc) << endl;
}