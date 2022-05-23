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
        int n, k, curr, res;
        char w;
        std::string s;
        std::vector<bool> c(26,false);
        std::cin >> n;
        std::cin >> s;
        std::cin >> k;
        while (k--){
            std::cin >> w;
            c[int(w)-97] = true;
        }
        curr = 0;
        res = 0;
        for (char w:s){
            if (c[int(w)-97] == true){
                res = std::max(res, curr);
                curr = 0;
            }
            curr++;
        }
        std::cout << res << std::endl;
    }
    
    return 0;
}