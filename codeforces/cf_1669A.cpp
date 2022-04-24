#include <iostream>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t=0, r[3]={1400,1600,1900};
    std::cin >> t;
    while (t>0){
        t--;
        int num=0;
        std::cin >> num;
        if (num<r[0]) std::cout << "Division 4" << std::endl;
        else if (num<r[1]) std::cout << "Division 3" << std::endl;
        else if (num<r[2]) std::cout << "Division 2" << std::endl;
        else std::cout << "Division 1" << std::endl;
    }
    return 0;
}