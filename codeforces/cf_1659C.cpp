#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#define ll long long
ll abs(ll a){
    if (a>0) return a;
    return -a;
};

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t>0){
        t--;
        ll n, a, b, total=0, best, dp;
        std::cin >> n >> a >> b;
        std::vector<ll> x(n+1, 0);
        for (int i=1; i<n+1;i++){
            std::cin >> x[i];
        }
        for (int i=1; i<n+1; i++) total += x[i];
        dp = total*b;
        best = dp;
        for (int i=1; i<n; i++){
            dp = (x[i]-x[i-1])*a + dp - (n-i)*(x[i]-x[i-1])*b;
            if (dp<best) best = dp;
        }
        std::cout << best << std::endl;

    }
}