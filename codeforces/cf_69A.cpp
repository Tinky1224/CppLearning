#include <iostream>

int main(){
    int n, cx=0, cy=0, cz=0, x, y, z;
    std::cin >> n;
    for (int i=0; i<n; i++){
        std::cin >> x >> y >> z;
        cx += x;
        cy += y;
        cz += z;
    }
    if (cx==0 && cy==0 && cz==0) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
    return 0;
}