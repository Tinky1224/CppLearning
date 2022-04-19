#include <iostream>

int min(int a, int b) {
    if (a>b) return b;
    return a;
};

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t>0){
        t--;
        int n, m, res=0, Min, tmp;
        std::cin >> n >> m;
        if (n==1 && m==1) {
            std::cout << 0 << std::endl;
            continue;
        }
        if (n==1 || m==1) {
            if (n==2 || m==2) std::cout << 1 << std::endl;
            else std::cout << -1 << std::endl;
            continue;
        }else{
            Min = min(n, m);
            res += 2*(Min-1);
            tmp = n+m-2*Min;
            if (tmp%2==1) {
                tmp--;
                res++;
            }
            res += tmp*2;
            std::cout << res << std::endl;
        }
    }
    return 0;
}