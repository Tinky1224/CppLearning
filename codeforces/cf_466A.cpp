#include <iostream>

int main(){
    int n, m, a, b;
    std::cin >> n >> m >> a >> b;
    if (a*m <= b){
        std::cout << a*n << std::endl;
    }else{
        if ((n%m)*a <= b){
            std::cout << (n/m)*b+(n%m)*a << std::endl;
        }else{
            std::cout << (n/m+1)*b << std::endl;
        }
    }
    return 0;
}