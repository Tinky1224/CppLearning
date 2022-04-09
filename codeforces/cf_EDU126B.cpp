#include <iostream>

int main(){
    int t, a, best, tmp, multi;
    std::cin >> t;
    for (int i = 0; i < t; i++){
        std::cin >> a;
        if (a==0){
            std::cout << 0 << " ";
            continue;
        }
        best = 16;
        for (int j=0; j<16; j++){
            tmp = (a+j)&(-(a+j));
            multi = 0;
            while (tmp<32768){
                multi++;
                tmp <<= 1;
            }
            if (multi+j < best) best = multi+j;
        }
        std::cout << best << " ";
    }
    return 0;
}