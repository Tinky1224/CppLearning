#include <iostream>
#include <vector>

int main(){
    int n, q, x, m;
    std::cin >> n;
    std::vector<int> prices(100001), prefix(100001);
    for (int i=0; i<n; i++){
        std::cin >> x;
        prices[x]++;
    }
    for (int i=1; i<100001; i++){
        prefix[i] = prefix[i-1] + prices[i];
    }
    std::cin >> q;
    for (int i=0; i<q; i++){
        std::cin >> m;
        if (m>100000) std::cout << n << std::endl;
        else std::cout << prefix[m] << std::endl;
    }
    return 0;
}