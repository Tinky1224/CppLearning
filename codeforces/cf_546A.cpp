#include <iostream>

int main(){
    int k, w, n;
    std::cin >> k >> n >> w;
    for (int i = 1; i<=w; i++){
        n -= k*i;
    }
    if (n<0){
        std::cout << -n << std::endl;
    }else{
        std::cout << 0 << std::endl;
    }
    return 0;
}