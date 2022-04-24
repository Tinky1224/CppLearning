#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--){
        int n, c=0;
        bool check = true;
        std::cin >> n;
        std::vector<int> x(n);
        for (int i=0; i<n; i++) std::cin >> x[i];
        for (int i=1; i<n; i++){
            if (x[i]-x[i-1]>3){
                check = false;
                break;
            }
            c += x[i]-x[i-1]-1;
        }
        if (c>=3) check=false;
        if (check) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
}