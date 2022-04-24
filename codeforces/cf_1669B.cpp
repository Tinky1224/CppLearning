#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t=0;
    std::cin >> t;
    std::vector<int> a(200001,0);
    while (t>0){
        t--;
        int n, res=-1, curr=0;
        std::cin >> n;
        for (int i=0; i<n; i++){
            std::cin >> curr;
            a[curr]++;
            if (a[curr]>=3) res = curr;
        }
        std::cout << res << std::endl;
        for (int i=0; i<200001; i++) a[i]=0;
    }
    return 0;
}