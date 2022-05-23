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
        ll n, x, y;
        std::cin >> n;
        if (n == 0){
            std::cout << 0 << " " << 0 << std::endl;
            continue;
        }
        if (n < 4 || n%2==1){
            std::cout << -1 << std::endl;
            continue;
        }
        x = n/4;
        y = n/6 + (n%6 > 0);
        std::cout << y << " " << x << std::endl;
    }
    return 0;
}