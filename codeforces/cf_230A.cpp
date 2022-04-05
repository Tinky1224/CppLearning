#include <iostream>
#include <vector>
#include <algorithm>

int main(){
    int s, n;
    std::cin >> s >> n;
    std::vector<std::vector<int>> dragons(n, std::vector<int>(2));
    for (int i=0; i<n; i++){
        std::cin >> dragons[i][0] >> dragons[i][1];
    }
    std::sort(dragons.begin(), dragons.end(), [](std::vector<int>a, std::vector<int>b){return a[0]>b[0];});
    while (!dragons.empty()){
        if (s <= dragons.back()[0]){
            std::cout << "NO" << std::endl;
            return 0;
        }else{
            s += dragons.back()[1];
            dragons.pop_back();
        }
    }
    std::cout << "YES" << std::endl;
    return 0;
};