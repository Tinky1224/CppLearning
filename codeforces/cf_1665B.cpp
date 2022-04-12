#include <iostream>
#include <map>

int main(){
    int t, n, Max, curr, res;
    std::cin >> t;
    std::map<int, int> c;
    for (int i=0; i<t; i++){
        c.clear();
        Max = 0;
        res = 0;
        std::cin >> n;
        for (int j=0; j<n; j++){
            std::cin >> curr;
            c[curr]++;
            if (c[curr]>Max){
                Max = c[curr];
            }
        }
        res = n-Max;
        while (Max<n){
            Max *= 2;
            res++;
        }
        std::cout << res << std::endl;
    }
    return 0;
}