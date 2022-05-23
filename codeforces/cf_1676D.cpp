#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define ll long long

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);
    int total = 2, upper = 1000000000;
    std::vector<int> vals{0,0,2};
    while (vals.back()<upper){
        vals.push_back(vals.back()+(total-total/3)*2);
        total++;
    }
    int t;
    std::cin >> t;
    while (t--){
        int l=0, r=vals.size(), m, n;
        std::cin >> n;
        while (l<r){
            m = (l+r)/2;
            if (vals[m] < n) l = m+1;
            else r = m;
        }
        std::cout << l << std::endl;
    }
    
    return 0;
}