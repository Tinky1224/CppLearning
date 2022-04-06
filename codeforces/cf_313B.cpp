#include <iostream>
#include <vector>
#include <string>

int main(){
    std::string s;
    std::cin >> s;
    int n=s.size(), m, l, r;
    std::vector<int> dp(n, 0);
    for (int i=1; i<n; i++){
        dp[i] = dp[i-1] + int(s[i-1]==s[i]);
    }
    std::cout << std::endl;
    std::cin >> m;
    for (int i=0; i<m; i++){
        std::cin >> l >> r;
        std::cout << dp[r-1]-dp[l-1] << std::endl;
    }
    return 0;

}