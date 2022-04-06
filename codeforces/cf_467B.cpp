#include <iostream>
#include <vector>

int count1(int x){
    int res=0;
    while (x){
        if (x&1) res++;
        x >>= 1;
    }
    return res;
};

int main(){
    int n, m, k, res=0;
    std::cin >> n >> m >> k;
    std::vector<int> ss(m+1);
    for (int i=0; i<m+1; i++){
        std::cin >> ss[i];
    }
    for (int i=0; i<m; i++){
        if (count1(ss[i]^ss[m]) <= k) res++;
    }
    std::cout << res << std::endl;
    return 0;
}