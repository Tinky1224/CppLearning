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
        std::string s2;
        std::cin >> s2;
        int A=0, B=0, n=s2.size();
        bool check=true;
        for (int i=0; i<n; i++){
            if (s2[i]=='B') {
                B++;
                if (A<B){
                    check = false;
                    break;
                }
            }
            else A++;
        }
        if (A >= B && s2[n-1]=='B' && s2[0]!='B') std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
}