#include <iostream>

int main(){
    __int64 n, k, mid;
    std::cin >> n >> k;
    mid = (n+1)/2;
    if (k<=mid) std::cout << 2*k-1 << std::endl;
    else std::cout << 2*(k-mid) << std::endl;
    return 0;
}