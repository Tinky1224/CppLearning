#include <iostream>

int main(){
    int a, b, res=0;
    std::cin >> a >> b;
    while (a<=b){
        a *= 3;
        b*= 2;
        res++;
    }
    std::cout << res << std::endl;
    return 0;
};