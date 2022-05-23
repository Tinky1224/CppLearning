#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#define ll long long

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q, all=-1, type, ind, val;
    ll res=0;
    std::cin >> n >> q;
    std::vector<int> a(n);
    std::set<int> not_all;
    not_all.clear();
    for (int i=0; i<n; i++){
        std::cin >> a[i];
        res += a[i];
    }
    while (q--){
        std::cin >> type;
        if (type == 1){
            std::cin >> ind >> val;
            ind--;
            if (all<0 || not_all.count(ind)){
                res += val - a[ind];
            }else{
                res += val - all;
                not_all.insert(ind);
            }
            a[ind] = val;
        }else{
            std::cin >> val;
            not_all.clear();
            all = val;
            res = val*n;
        }
        std::cout << res << std::endl;
    }
    return 0;
}