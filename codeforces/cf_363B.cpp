#include <iostream>
#include <vector>

int main(){
    int n, k, res=-1, curr=110000000;
    std::cin >> n >> k;
    std::vector<int> hs(n), prefix(n+1);
    for (int i=0; i<n; i++){
        std::cin >> hs[i];
        prefix[i+1] = prefix[i]+hs[i];
    }
    for (int i=0; i<n-k+1; i++){
        if (prefix[i+k]-prefix[i] < curr){
            res = i+1;
            curr = prefix[i+k]-prefix[i];
        }
    }
    std::cout << res << std::endl;
    return 0;

}