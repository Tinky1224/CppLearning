#include <iostream>

int main(){
    __int64 t, n, k;
    std::cin >> t;
    for (int i=0; i<t; i++){
        std::cin >> n >> k;
        if (n%2!=k%2){
            std::cout << "NO" << std::endl;
            continue;
        }else{
            if (n<(k*k)){
                std::cout << "NO" << std::endl;
                continue;
            }else{
                std::cout << "YES" << std::endl;
            }
        }
    }
    return 0;
}