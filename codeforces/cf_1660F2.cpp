//2100 Promising String
#include <iostream>
#include <string>
#include <vector>

#define ll long long

class FenwickTree{
private:
    std::vector<std::vector<ll>> mod;
public:
    int base, L;
    FenwickTree(int n){
        mod = std::vector<std::vector<ll>> (3, std::vector<ll> ((n*2+1)/3+10, 0));
        base = n;
        L = (n*2+1)/3+10;
    }
    ll update(int ind){
        int m = (ind+300000)%3, new_ind=(ind+base)/3+2, res;
        res = get(L-1,m) - get(new_ind-1, m);
        while (new_ind < L){
            mod[m][new_ind] += 1;
            new_ind += (new_ind & -new_ind);
        }
        return res;
    };
    ll get(int ind, int m){
        ll total = 0;
        while (ind > 0){
            total += mod[m][ind];
            ind -= (ind & -ind);
        }
        return total;
    }
};

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, n, pre;
    ll res=0;
    std::string s;
    std::cin >> t;
    for (int i=0; i<t; i++){
        res = 0;
        std::cin >> n;
        std::cin >> s;
        pre = 0;
        FenwickTree BIT(n);
        pre = (s[0]=='+')*2-1;
        BIT.update(pre);
        for (int j=1; j<n; j++){
            pre += (s[j]=='+')*2-1;
            if (pre <= 0 && pre%3==0) res++;
            res += BIT.update(pre);
        }
        std::cout << res << std::endl;
    }
    return 0;
}