#include <iostream>

int main(){
    int n, m;
    std::cin >> n >> m;
    if (n>m){
        n=m;
    }
    if (n%2==1){
        std::cout << "Akshat" << std::endl;
    }else{
        std::cout << "Malvika" << std::endl;
    }
    return 0;
}