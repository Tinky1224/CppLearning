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
    std::string s;
    for (int Case=0; Case<t; Case++){
        std::cin >> s;
        int one = 0, n=s.size(), zero=-1;
        if (n==1){
            std::cout << 1 << std::endl;
            continue;
        }
        for (int i=0; i<n; i++){
            if (s[i] == '1') one = i;
            else if (s[i] == '0') {
                zero = i;
                break;
            }
        }
        if (zero<0 && one<0)std::cout << n << std::endl;
        else if (one<0) std::cout << zero+1 << std::endl;
        else if (zero<0) std::cout << n-one << std::endl;
        else std::cout << (zero - one +1) << std::endl;
    }
    return 0;
}