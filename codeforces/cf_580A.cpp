#include <iostream>

int main(){
    int n, pre=0, curr=0, accu=0, res=0;
    std::cin >> n;
    for (int i=0; i<n;i++){
        std::cin >> curr;
        if (curr>=pre){
            accu += 1;
            if (accu>res) res = accu;
        }else accu=1;
        pre = curr;
    }
    std::cout << res << std::endl;
    return 0;
}