#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t=0, c[2]={0};
    std::cin >> t;
    std::vector<int> a;
    while (t>0){
        t--;
        int n;
        std::cin >> n;
        c[0]=0;
        c[1]=0;
        a.clear();
        a.resize(n);
        for (int i=0; i<n; i++) std::cin >> a[i];
        for (int i=0; i<n; i+=2) c[a[i]%2]++;
        if (c[0]!=0 && c[1]!=0){
            std::cout << "NO" << std::endl;
            continue;
        }
        c[0]=0;
        c[1]=0;
        for (int i=1; i<n; i+=2) c[a[i]%2]++;
        if (c[0]!=0 && c[1]!=0) {
            std::cout << "NO" << std::endl;
            continue;
        }
        std::cout << "YES" << std::endl;
    }
    return 0;
}