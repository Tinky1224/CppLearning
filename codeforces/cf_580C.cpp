//1500
#include <iostream>
#include <vector>
#include <algorithm>

int dfs(std::vector<std::vector<int>> &edges, std::vector<int> &cats, int pre, int curr, int accu, int m){
    if (cats[curr]>0) accu ++;
    else accu=0;
    if (accu>m) return 0;
    if (edges[curr].size()==1 && edges[curr][0]==pre) return 1;
    int res = 0;
    for (int child:edges[curr]){
        if (child==pre) continue;
        res += dfs(edges, cats, curr, child, accu, m);
    }
    return res;
};

int main(){
    int n, m, parent, child, res;
    std::cin >> n >> m;
    std::vector<int> cats(n);
    for (int i = 0; i <n; i++){
        std::cin >> cats[i];
    }
    std::vector<std::vector<int>> edges(n);
    for (int i=0; i<n-1; i++){
        std::cin >> parent >> child;
        edges[parent-1].push_back(child-1);
        edges[child-1].push_back(parent-1);
    }
    res = dfs(edges, cats, -1, 0, 0, m);
    std::cout << res << std::endl;
    return 0;
}