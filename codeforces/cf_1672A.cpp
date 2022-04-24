#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define ll long long

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);
    int t;
    std::cin >> t;
    while (t--){
        int n, total=0, curr;
        std::cin >> n;
        for (int i=0; i<n; i++){
            std::cin >> curr;
            total += curr-1;
        }
        if (total%2) std::cout << "errorgorn" << std::endl;
        else std::cout << "maomao90" << std::endl;
    }
    return 0;
}