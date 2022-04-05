#include <iostream>

int main(){
    __int64 res=0;
    int n, m, curr=1, target;
    std::cin >> n >> m;
    for (int i=0; i<m; i++){
        std::cin >> target;
        if (target >= curr){
            res += target - curr;
        }else{
            res += (n-curr)+target;
        }
        curr = target;
    }
    std::cout << res << std::endl;
    return 0;
}