#include <iostream>

int main(){
    int res, groups[4]={0,0,0,0}, curr, n;
    std::cin >> n;
    for (int i=0; i<n; i++){
        std::cin >> curr;
        groups[curr-1]++;
    }
    res += groups[3];
    res += groups[2];
    groups[0] -= groups[2];
    res += groups[1]/2 + groups[1]%2;
    groups[0] -= (groups[1]%2)*2;
    if (groups[0]>0){
        res += groups[0]/4 + (groups[0]%4>0);
    }
    std::cout << res << std::endl;
    return 0;
};