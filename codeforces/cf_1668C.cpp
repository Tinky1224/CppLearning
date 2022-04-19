#include <iostream>
#include <vector>
#define ll long long

ll min(ll a, ll b){
    if (a>b) return b;
    return a;
};

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    ll pre=0, res=-1, curr;
    std::cin >> n;
    std::vector<ll> a(n);
    for (int i=0; i<n; i++) std::cin >> a[i];
    for (int i=0; i<n; i++){
        curr = 0;
        pre = 0;
        for (int j=i-1; j>=0; j--){
            curr += pre/a[j]+1;
            pre = a[j]*(pre/a[j]+1);
        }
        if (res > 0 && curr>res) break;
        pre = 0;
        for (int j=i+1; j<n; j++){
            curr += pre/a[j]+1;
            pre = a[j]*(pre/a[j]+1);
        }
        if (res<0) res = curr;
        else res = min(res, curr);
    }
    std::cout << res << std::endl;
    return 0;
}