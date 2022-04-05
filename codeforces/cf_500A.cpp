#include <iostream>

int main(){
    int n, t, curr=1, a;
    std::cin >> n >> t;
    for (int i=1; i<=n-1; i++){
        std::cin >> a;
        if (i==curr){
            curr += a;
        }
        if (curr==t){
            std::cout << "YES" << std::endl;
            return 0;
        }else if (curr > t){
            break;
        }
    }
    std::cout << "NO" << std::endl;
    return 0;
}