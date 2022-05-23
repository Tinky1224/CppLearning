#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#include <set>
#define ll long long

class disjoint_set {
public:
    std::vector<int> groups;
    void init(int n);
    int find(int x);
    bool merge(int x, int y);
    int get_groups();
};
void disjoint_set::init(int n){
    groups.clear();
    groups.reserve(n+5);
    for (int i=0;i<n;i++){
        groups.push_back(i);
    }
};
int disjoint_set::find(int x){
    if (groups[x]!=x) groups[x]=find(groups[x]);
    return groups[x];
};
bool disjoint_set::merge(int x, int y){
    int x1=find(x), y1=find(y);
    if (x1!=y1) groups[y1] = x1;
    return x1!=y1;
};
int disjoint_set::get_groups(){
    std::set<int> seen;
    for (int group:groups) seen.insert(find(group));
    return seen.size();
};

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--){
        int n, res=1;
        std::cin >> n;
//        std::cout << "n:" << n << std::endl;
        std::vector<int> a(n), b(n), c(n), g(n,0);
        for (int i=0; i<n; i++) std::cin >> a[i];
        for (int i=0; i<n; i++) std::cin >> b[i];
        for (int i=0; i<n; i++) std::cin >> c[i];
//        std::cout << "vector end" << std::endl;
        disjoint_set UF;
//        std::cout << "create djs" << std::endl;
        UF.init(n);
        for (int i=0; i<n; i++){
            UF.merge(a[i]-1, b[i]-1);
        }
//        std::cout << "merge end" << std::endl;
        for (int i=0; i<n; i++){
            g[UF.find(i)]++;
        }
//        std::cout << "find end" << std::endl;
        for (int i=0; i<n; i++){
            if (c[i]>0) g[UF.find(c[i]-1)]=0;
        }
//        std::cout << "miner end" << std::endl;
        for (int num:g){
            if (num>1) res*=2;
            res %= 1000000007;
        }
//        std::cout << "pow end" << std::endl;
        std::cout << res << std::endl;
    }
    return 0;
}