//1700 Promising String
#include <iostream>
#include <string>
#include <vector>

int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, n, res;
    std::string s;
    std::cin >> t;
    for (int i=0; i<t; i++){
        res = 0;
        std::cin >> n;
        std::cin >> s;
        std::vector<int> prefix_sum(n);
        std::vector<std::vector<int>> mod(3);
        prefix_sum[0] = (s[0]=='+')*2-1;
        mod[(prefix_sum[0]+300000)%3].push_back(0);
        for (int j=1; j<n; j++){
            prefix_sum[j] = prefix_sum[j-1] + (s[j]=='+')*2-1;
            if (prefix_sum[j] <=0 && prefix_sum[j]%3==0) res++;
            for (int ind:mod[(prefix_sum[j]+300000)%3]){
                if (prefix_sum[ind] >= prefix_sum[j]) res++;
            }
            mod[(prefix_sum[j]+300000)%3].push_back(j);
        }
        std::cout << res << std::endl;
    }
    return 0;
}