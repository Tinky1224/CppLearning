#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, m;
    std::cin >> n;
    std::vector<int> bs(n);
    for (int i=0; i<n; i++) std::cin >> bs[i];
    std::cin >> m;
    std::vector<int> gs(m);
    for (int i=0; i<m; i++) std::cin >> gs[i];
    std::sort(bs.begin(), bs.end());
    std::sort(gs.begin(), gs.end());
    int point=0, res=0;
    for (int s:bs){
        while (point<m && s-1>gs[point]) point++;
        if (s-1<=gs[point] && s+1>=gs[point]){
            res++;
            point++;
        }
    }
    std::cout << res << std::endl;
    return 0;
}