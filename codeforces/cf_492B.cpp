#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n, l;
    double res;
    std::cin >> n >> l;
    std::vector<double> ls(n);
    for (int i = 0; i < n; i++){
        std::cin >> ls[i];
    }
    std::sort(ls.begin(), ls.end());
    res = std::max(ls[0],l-ls[n-1]);
    for (int i = 0; i<n-1; i++){
        res = std::max(res, (ls[i+1]-ls[i])/2);
    }
    printf("%1f", res);
    return 0;
}