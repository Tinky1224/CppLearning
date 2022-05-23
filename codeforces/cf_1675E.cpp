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
        int n, k, lower = 97, upper = 0, remain = 0;
        std::cin >> n >> k;
        std::string s;
        std::cin >> s;
        for (int i=0; i<n; i++){
            if (int(s[i])-97 <= k) {
                lower = std::max(lower, int(s[i]));
                s[i] = 'a';
            }else if (upper == 0){
                upper = int(s[i]);
                remain = k-lower+97;
                break;
            }
        }
        if (upper>0){
            for (int i=0; i<n; i++){
                if (int(s[i]) <= upper && int(s[i])>upper-remain){
                    s[i] = char(upper-remain);
                }else if (int(s[i]) <= lower) s[i] = 'a';
            }
        }
        std::cout << s << std::endl;
    }
    return 0;
}