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
        int n, x, Min=20000001;
        std::cin >> n >> x;
        std::vector<int> a(n);
        for (int i=0; i<n; i++) {
            std::cin >> a[i];
            Min = std::min(a[i],Min);
        }
        if (n==1) {
            std::cout << (std::max(a[0], x)-1) << std::endl;
            continue;
        }
        ll res=0;
        for (int i=0; i<n-1; i++) res += std::abs(a[i+1]-a[i]);
        int d = std::min(std::abs(a[0]-x), std::abs(a[n-1]-x));
        if (Min <= x){
            for (int i=0; i<n-1; i++){
                d = std::min(d, std::abs(a[i]-x)+std::abs(a[i+1]-x)-std::abs(a[i]-a[i+1]));    
            }
            res += d;
        }
        d = std::min(std::abs(a[0]-1), std::abs(a[n-1]-1));
        for (int i=0; i<n-1; i++){
            d = std::min(d, std::abs(a[i]-1)+std::abs(a[i+1]-1)-std::abs(a[i]-a[i+1]));
        }
        res += d;
        std::cout << res << std::endl;
    }
    return 0;
}