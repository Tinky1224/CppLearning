#include <iostream>
#include <vector>

int main(){
    int t, a, angles[22]={60, 90, 108, 120, 135, 140, 144, 150, 156, 160, 162, 165, 168, 170, 171, 172, 174, 175, 176, 177, 178, 179};
    std::cin >> t;
    bool in= false;
    for (int i=0; i<t; i++){
        std::cin >> a;
        in = false;
        for (int j=0; j<22; j++){
            if (angles[j]==a){
                in = true;
                break;
            }
        }
        if (in) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
}
