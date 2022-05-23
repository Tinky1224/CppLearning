#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define ll long long

void dfs(std::vector<int> &p, std::vector<std::vector<int>> &c, std::vector<int> &res, int curr){
    res.push_back(curr);
    if (c[curr-1].empty()){
        std::cout << res.size() << std::endl;
        for (int node:res) std::cout << node << " ";
        std::cout << std::endl;
        res.clear();
        return ;
    }
    for (int node:c[curr-1]){
        if (node==curr) continue;
        dfs(p, c, res, node);
    }
    return ;
};

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    for (int Case=0; Case<t; Case++){
        int n, root, leaf=0;
        std::cin >> n;
        std::vector<int> p(n), res(0);
        std::vector<std::vector<int>> c(n);
        for (int i=0; i<n; i++) {
            std::cin >> p[i];
            if (p[i] == i+1) root = i+1;
            c[p[i]-1].push_back(i+1);
        }
        if (n==1){
            std::cout << 1 << std::endl;
            std::cout << 1 << std::endl;
            std::cout << 1 << std::endl;
            std::cout << std::endl;
            continue;
        }
        for (int i=0; i<n; i++){
            if (c[i].empty()) leaf++;
        }
        std::cout << leaf << std::endl;
        dfs(p, c, res, root);
        std::cout << std::endl;
    }
    return 0;
}