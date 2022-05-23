#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define ll long long

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--){
        int n, res=0;
        bool check = false;
        std::cin >> n;
        std::vector<int> a(n);
        for (int i=0; i<n; i++) std::cin >> a[i];
        for (int i=1; i<n; i++){
            for (int j=i-1; j>=0; j--){
                while (a[j] >= a[j+1]){
                    if (a[j]==0) {
                        check = true;
                        break;
                    }
                    a[j] /= 2;
                    res++;
                }
                if (check) break;
            }
            if (check) break;
        }
        if (check) std::cout << -1 << std::endl;
        else std::cout << res << std::endl;
    }
    return 0;
}