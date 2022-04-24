#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define ll long long

void dfs(int x, std::vector<bool> &passed, std::vector<bool> &curr, std::vector<std::vector<int>> &Next, bool &check){
    passed[x] = true;
    curr[x] = true;
    for (int num:Next[x]){
        if (curr[num]) check = true;
        if (check) return ;
        if (!passed[num]) dfs(num, passed, curr, Next, check); 
    }
    curr[x] = false;
}

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--){
        int n, Max=0;
        bool check = false;
        std::cin >> n;
        std::vector<int> a(n), b(n);
        std::vector<bool> passed(n+1, false), curr(n+1, false);
        std::vector<std::vector<int>> Next(n+1);
        for (int i=0; i<n; i++) std::cin >> a[i];
        for (int i=0; i<n; i++) std::cin >> b[i];
        for (int i=0; i<n; i++) Next[a[i]].push_back(b[i]);
        for (int i=1; i<n+1; i++) if (Next[i].size()>Next[Max].size()) Max = i;
        passed[Max] = true;
        for (int i=0; i<n+1; i++){
            if (!passed[i]) dfs(i, passed, curr, Next, check);
            if (check) break;
        }
        if (check) std::cout << "WA" << std::endl;
        else std::cout << "AC" << std::endl;
    }
    return 0;
}