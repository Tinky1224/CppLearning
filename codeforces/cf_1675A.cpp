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
        int a, b, c, x, y;
        std::cin >> a >> b >> c >> x >> y;
        x = std::max(0, x-a);
        y = std::max(0, y-b);
        if (x+y <= c) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
}