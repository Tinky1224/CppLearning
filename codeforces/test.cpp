#include <iostream>
#include <cmath>

int main(){
    long long x=999966000289;
    double r = std::sqrt(x);
    std::cout << "x = " << x << ", r = " << r << std::endl;
    std::cout << (r*r==x) << std::endl;
    return 0;
}