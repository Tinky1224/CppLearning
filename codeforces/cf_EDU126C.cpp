#include <iostream>
#include <vector>

long long binary_search(std::vector<int> &hs, int target){
//    std::cout << "target: " << target << std::endl;
    int n = hs.size();
    long long needs[2]={0,0}, l=0, r, m, one, two, remain;
    for (int h:hs){
        needs[1] += (target-h)/2;
        needs[0] += (target-h)%2;
    }
//    std::cout << "Needs: " << needs[0] << ", " << needs[1] << std::endl;
    r = (needs[0]+needs[1]*2)*2-1;
    while (l<r){
        m = (l+r)/2;
        two = m/2;
        one = two+m%2;
        remain = needs[0];
        if (needs[1] > two) remain += (needs[1]-two)*2;
//        std::cout << "l, r, m: " << l << ", " << r << ", " << m << std::endl;
//        std::cout << "one, two, remain: " << one << ", " << two << ", " << remain << std::endl;
        if (remain > one) l = m+1;
        else r = m; 
    }
    return l;
};

int main(){
    int t, n, Max;
    long long res1, res2;
    std::cin >> t;
    for (int i=0; i<t; i++){
        Max = 0;
        res1 = 0;
        res2 = 0;
        std::cin >> n;
        std::vector<int> hs(n);        
        for (int j=0; j<n; j++){
            std::cin >> hs[j];
            if (hs[j]>Max) Max=hs[j];
        }
        res1 = binary_search(hs,Max);
        res2 = binary_search(hs,Max+1);
        if (res1>=res2) std::cout << res2 << std::endl;
        else std::cout << res1 << std::endl;
    }
    return 0;
};