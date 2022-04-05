#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int n;
    std::cin >> n;
    std::vector<int> res(n);
    for (int i=0; i<n; i++){    
        std::cin >> res[i];
    }
    std::sort(res.begin(), res.end());
    for (int i=0; i<n; i++) std::cout << res[i] << ' ';
    return 0;
}