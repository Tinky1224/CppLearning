#include <iostream>

int main(){
    int n, curr, a=0, b=0;
    std::cin >> n;
    for (int i=0; i<n; i++){
        std::cin >> curr;
        a += curr;
    }
    for (int i=0; i<n-1; i++){
        std::cin >> curr;
        b += curr;
    }
    std::cout << a-b << std::endl;
    a = 0;
    for (int i=0; i<n-2; i++){
        std::cin >> curr;
        b -= curr;
    }
    std::cout << b << std::endl;
    return 0;
}