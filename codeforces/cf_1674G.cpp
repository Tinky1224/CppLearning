#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

int dfs(std::vector<int> &indegree, std::vector<int> &outdegree, std::vector<int> &dp, std::vector<std::vector<int>> &edges, int u){
    if (dp[u]==0){
        dp[u] = 1;
        if (outdegree[u] > 1){
            for (int v:edges[u]){
                if (indegree[v] > 1) dp[u] = std::max(dp[u], dfs(indegree, outdegree, dp, edges, v)+1);
            }
        }
    }
    return dp[u];
};

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    int n, m, u, v, res=0;
    std::cin >> n >> m;
    std::vector<int> indegree(n,0), outdegree(n,0), dp(n,0);
    std::vector<std::vector<int>> edges(n);
    for (int i=0; i<m; i++){
        std::cin >> u >> v;
        edges[u-1].push_back(v-1);
        indegree[v-1]++;
        outdegree[u-1]++;
    }
    for (int i=0; i<n; i++){
        if (dp[i]==0) res = std::max(res, dfs(indegree, outdegree, dp, edges, i));
    }
    std::cout << res << std::endl;
    return 0;
}