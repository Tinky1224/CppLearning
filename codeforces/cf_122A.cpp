#include <iostream>

int main(){
    int n, lucky[14]={4,7,44,47,74,77,444,447,474,477,744,747,774,777};
    std::cin >> n;
    for (int i=0; i<14; i++){
        if (lucky[i] > n) break;
        if (n%lucky[i]==0) n=0;
    }
    if (n==0) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
    return 0;
}