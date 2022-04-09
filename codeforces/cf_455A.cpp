//same as 
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

int main(){
    long long n, a, m, size=2;
    std::cin >> n;
    std::map<long long, long long> counts;
    for (int i = 0; i < n; i++){
        std::cin >> a;
        counts[a]++;
    }
    m = counts.size();
    std::vector<long long> dp{0, 0};
    for (std::map<long long, long long>::iterator it = counts.begin(); it != counts.end(); it++){
        if (counts[it->first-1]>0) dp.push_back(std::max(dp[size-2], dp[size-3])+it->second*it->first);
        else dp.push_back(std::max(dp[size-1], dp[size-2])+it->second*it->first);
        size++;
    }
    std::cout << std::max(dp[size-1],dp[size-2]) << std::endl;
    return 0;
}