#include <iostream>
#include <vector>
#include <set>

class disjoint_set {
public:
    std::vector<int> groups;
    void init(int n);
    int find(int x);
    bool merge(int x, int y);
    int get_groups();
};
void disjoint_set::init(int n){
    groups.reserve(n);
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
