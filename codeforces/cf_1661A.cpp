#include <iostream>
#include <cmath>

int main(){
    int t, n;
    std::cin >> t;
    long long a[25], b[25], res, res1, res2;
    for (int i=0; i<t; i++){
        std::cin >> n;
        res = 0;
        for (int j=0; j<n; j++) {
            std::cin >> a[j];
        }
        for (int j=0; j<n; j++) {
            std::cin >> b[j]; 
        }
        for (int j=1; j<n; j++){
            res1 = std::abs(a[j]-a[j-1]) + std::abs(b[j]-b[j-1]);
            res2 = std::abs(a[j]-b[j-1]) + std::abs(b[j]-a[j-1]);
            res += std::min(res1, res2);
        }
        std::cout << res << std::endl;
    }
    return 0;
}