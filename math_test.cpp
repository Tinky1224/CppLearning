#include <iostream>
#include <cmath>
//using namespace std; //若不使用這ㄍ，在使用函數時需要在函數前加上std::以呼叫函數
int main(){
    int x, y, z, res;
    float f;
    x = 10;
    y = 20;
    z = -5;
    f = 2.6;
    res = std::max(x,y);
    std::cout << "max of x and y : " << res << std::endl;
    res = std::min(x,y);
    std::cout << "min of x and y : " << res << std::endl;
    res = std::abs(z);
    std::cout << "abs of z : " << res << std::endl;
    res = std::sqrt(x);
    std::cout << "sqrt of x : " << res << std::endl;
    res = std::round(f);
    std::cout << "round of f : " << res << std::endl;
    res = std::log(y);
    std::cout << "log of y : " << res << std::endl;
    return 0;
}