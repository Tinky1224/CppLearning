#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define ll long long 

std::string dfs(std::string &s, ll &res, int p){
    if (2*p+1 >= s.size()) return (std::string) ""+s[p];
    std::string L = dfs(s, res, 2*p+1), R = dfs(s, res, 2*p+2);
    if (L != R) res *= 2;
    res %= 998244353;
    if (L < R) std::swap(L, R);
    return (std::string) ""+s[p] + L + R;
};

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::string s;
    std::cin >> s;
    ll res = 1;
    dfs(s, res, 0);
    std::cout << res << std::endl;
    return 0;
}