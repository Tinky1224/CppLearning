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
        int n, equa=0, res = 0, ind[2]={0, 0};
        std::cin >> n;
        std::vector<int> a(n);
        for (int i=0; i<n; i++) std::cin >> a[i];
        for (int i=1; i<n; i++){
            if (a[i-1]==a[i]){
                equa++;
                if (equa > 1) ind[1] = i;
                else ind[0] = i;
            }
        }
        if (equa<2) std::cout << 0 << std::endl;
        else std::cout << std::max(1, (ind[1]-ind[0]-1)) << std::endl;
    }
    return 0;
}