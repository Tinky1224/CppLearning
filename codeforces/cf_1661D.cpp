//1900 Progressions Covering
#include <iostream>
#include <vector>

#define ll long long
#define pll std::pair<ll, ll>

int main(){
    int n, k;
    std::cin >> n >> k;
    //std::cout << "n, k: " << n << ", " << k << std::endl;
    ll curr=0; 
    std::vector<ll> a(n), b(n), accu(n);
    for (int i=0; i<n; i++){
        std::cin >> b[i];
    }
    /*
    std::cout << "b: ";
    for (ll num:b) std::cout << num << ", ";
    std::cout << std::endl;
    */
    accu[n-1] = b[n-1]/k + (b[n-1]%k > 0);
    a[n-1] = accu[n-1] * k;
    for (int i=n-2; i>=0; i--){
        a[i] = a[i+1] - accu[i+1];
        accu[i] = accu[i+1];
        if (i<n-k-1) a[i] += accu[i+k+1];
        if (a[i]<b[i] && i>=k){
            curr = (b[i]-a[i])/k + ((b[i]-a[i])%k>0);
            a[i] += curr*k;
            accu[i] += curr;
        }
    }
    /*
    std::cout << "a: ";
    for (ll num:a) std::cout << num << ", ";
    std::cout << std::endl;
    std::cout << "accu: ";
    for (ll num:accu) std::cout << num << ", ";
    std::cout << std::endl;
    */
    curr = 0;
    for (int i=0; i<k; i++){
        if (a[i] < b[i] && ((b[i]-a[i])/(i+1) + ((b[i]-a[i])%(i+1)>0) > curr)){
            curr = (b[i]-a[i])/(i+1) + ((b[i]-a[i])%(i+1)>0);
        }
    }
    std::cout << (accu[0]+curr) << std::endl;
    return 0;
}