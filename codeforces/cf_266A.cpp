#include <iostream>
#include <string>

int main(){
    int n, res=0;
    std::string stones;
    std::cin >> n >> stones;
    for (int i=1; i<n; i++){
        if (stones[i] == stones[i-1]) res++;
    }
    std::cout << res << std::endl;
    return 0;
}