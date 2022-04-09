#include <iostream>

int main(){
    int t, n, k;
    std::cin >> t;
    for (int i=0; i<t; i++){
        std::cin >> n >> k;
        std::cout << (k/(n-1))*n-(k%(n-1)==0)+(k%(n-1)) << std::endl;
    }
    return 0;
}