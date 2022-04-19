#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t>0){
        t--;
        ll  n, m;
        std::cin >> n >> m;
        std::vector<ll> a(n);
        for (int i=0; i<n; i++) std::cin >> a[i];
        std::sort(a.begin(), a.end());
        m -= a.back()*2+1;
        a.pop_back();
        while (a.size() > 1){
            m -= a.back()+1;
            a.pop_back();
        }
        if (m<=0) std::cout << "NO" << std::endl;
        else std::cout << "YES" << std::endl;
    }
    return 0;
}
