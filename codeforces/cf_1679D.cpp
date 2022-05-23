#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define ll long long
#define vec(type) std::vector<type>
bool dfs(int curr, int val, ll k, vec(int) &a, vec(ll) &dist, vec(bool) &group, vec(bool) &visited, vec(vec(int)) &edges){
    visited[curr] = true;
    group[curr] = true;
    for (int next:edges[curr]){
        if (a[next] <= val){
            if (group[next]){
                dist[curr] = 1000000000000000000;
                return true;
            }
            if (!visited[next]){
                dfs(next, val, k, a, dist, group, visited, edges);
                group[next] = false;
            }
            dist[curr] = std::max(dist[curr], dist[next]+1);
        }
        if (dist[curr] >= k) return true;
    }
    return false;
};

bool check(int val, int n, ll k, vec(int) &a, vec(vec(int)) &edges){
    vec(bool) visited(n, false), group(n, false);
    vec(ll) dist(n,1);
    bool tmp;
    for (int i=0; i<n; i++){
        tmp = dfs(i, val, k, a, dist, group, visited, edges);
        group[i] = false;
        if (tmp) return true;
    }
    return false;
};

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    ll n, m, k, u, v;
    std::cin >> n >> m >> k;
    vec(int) a(n), sort_a;
    vec(vec(int)) edges(n);
    for (int i=0; i<n; i++) std::cin >> a[i];
    if (k==1) {
        int min=a[0];
        for (int i=1; i<n; i++){
            min = std::min(min, a[i]);
        }
        std::cout << min << std::endl;
        return 0;
    }
    for (int i=0; i<m; i++){
        std::cin >> u >> v;
        edges[u-1].push_back(v-1);
    }
    sort_a.assign(a.begin(), a.end());
    std::sort(sort_a.begin(), sort_a.end());
    int l=0, r=n, mid;
    while (l < r){
        mid = (l+r)/2;
        if (check(sort_a[mid], n, k, a, edges)){
            r = mid;
        }else{
            l = mid+1;
        }
    }
    if (l==n) std::cout << -1 << std::endl;
    else std::cout << sort_a[l] << std::endl;
    return 0;
}