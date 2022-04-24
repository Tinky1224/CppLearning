#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t>0){
        t--;
        int n, m, curr_r;
        std::cin >> n >> m;
        std::vector<std::string> ori(n);
        for (int i=0; i<n; i++) std::cin >> ori[i];
        for (int c=0; c<m; c++){
            for (int r=n-2; r>=0; r--){
                if (ori[r][c]=='*' && ori[r+1][c]=='.'){
                    curr_r = r;
                    while (curr_r < n-1 && ori[curr_r][c]=='*' && ori[curr_r+1][c]=='.'){
                        std::swap(ori[curr_r][c], ori[curr_r+1][c]);
                        curr_r++;
                    }
                }
            }
        }
        for (std::string s:ori) std::cout << s << std::endl;
    }
    return 0;
}