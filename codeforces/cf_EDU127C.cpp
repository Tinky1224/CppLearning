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
        ll n, x, day=0, days=0, l, r, mid, res=0;
        std::cin >> n >> x;
        std::vector<ll> a(n);
        for (int i=0; i<n; i++) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        if (x<a[0]){
            std::cout << 0 << std::endl;
            continue;
        }
        for (int i=1; i<n; i++) a[i] += a[i-1];
        l=0;
        r=n;
        while (l<r){
            mid = (l+r)/2;
            if (a[mid] <= x) l = mid+1;
            else r = mid;
        }
        l--;
        while (l>=0){
            day = (x-a[l])/(l+1);
            res += (day+1);
            l--; 
        }
        std::cout << res << std::endl;
    }
    return 0;
}