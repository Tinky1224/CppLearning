#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    std::vector<int> C(31,0);
    while (t>0){
        t--;
        for (int i=0; i<31; i++) C[i]=0;
        int n, k, a, ind=0, res=0;
        std::cin >> n >> k;
        for (int i=0; i<n; i++){
            std::cin >> a;
            ind = 0;
            while (a>0){
                if (a&1) C[ind]++;
                a >>= 1;
                ind++;
            }
        }
        for (int i=30; i>=0; i--){
            if (n-C[i] <= k){
                k -= n-C[i];
                res += std::pow(2, i);
            }
        }
        std::cout << res << std::endl;
    }
    return 0;
}