#include <iostream>
#include <vector>

int main(){
    int n, m, l;
    std::cin >> n >> m;
    std::vector<int> a(n), c(100001, 0), res(n+1,0);
    for (int i = 0; i < n; i++){
        std::cin >> a[i];
    }
    for (int i=n-1; i>=0; i--){
        if (c[a[i]]==0){
            c[a[i]] = 1;
            res[i] = res[i+1]+1;
        }else res[i] = res[i+1];
    }
    for (int i=0; i<m; i++){
        std::cin >> l;
        std::cout << res[l-1] << std::endl;
    }
    return 0;

}