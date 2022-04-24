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
    std::vector<int> res, w(200020);
    while (t>0){
        t--;
        res.clear();
        int n, a=0, b=0, p1, p2;
        std::cin >> n;
        p1 = 0;
        p2 = n-1;
        for (int i=0; i<n; i++) std::cin >> w[i];
        while (p1 <= p2){
            if (a==b) {
                res.push_back(p1+n-p2-1);
                a += w[p1++];
            } else if (a < b){
                a += w[p1++];
            } else {
                b += w[p2--];
            }
        }
        if (a==b){
            res.push_back(n);
        }
        std::cout << res.back() << std::endl;
    }
    return 0;
}