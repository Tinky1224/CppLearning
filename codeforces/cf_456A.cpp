#include <iostream>
#include <vector>

int main(){
    int n, a, pre=0;
    bool win=false;
    std::cin >> n;
    std::vector<int> qs(n);
    for (int i=0; i<n; i++){
        std::cin >> a;
        std::cin >> qs[a-1];
    }
    for (int q:qs){
        if (q < pre){
            win = true;
            break;
        }
        pre = q;
    }
    if (win) std::cout << "Happy Alex" << std::endl;
    else std::cout << "Poor Alex" << std::endl;
    return 0;
}