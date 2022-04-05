#include <iostream>
#include <cmath>

int main(){
    int money;
    std::cin >> money;
    if (money>=0){
        std::cout << money << std::endl;
    }else{
        int a = money/10;
        int b = money/100*10+money%10;
        std::cout << std::max(a,b) << std::endl;
    }
    return 0;
}