//2000 GCD guess
#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
//I think it is return the gcd of x and (a-b),for a>b.
//so we can use a=2^30, b=2^29 to check the last '1' bit index.
//every time we find it and diff it.
/*

long long GCD(long long a, long long b){
    long long r;
    while (a>0 && b>0){
        b %= a;
        r = b;
        b = a;
        a = r;
    }
    return a+b;
};
*/

int main(){
    std::ios::sync_with_stdio(false);
    long long t, x, a=std::pow(2,30), b=std::pow(2,29), curr, ret, hidden;
    std::cin >> t;
    for (int i=0; i<t; i++){
 //       std::cin >> hidden;
        x = 0;
        for (int curr=0; curr<29; curr++){
//            std::cout << curr << ", " << x << std::endl;
            std::cout << "? " << a-x << " " <<  b-x << std::endl;
            std::cin >> ret;
//            ret = GCD(hidden+a-x, hidden+b-x);
 //           std::cout << ret << std::endl;
            if (ret>=b){
                std::cout << "? " << a-x+10 << " " << b-x+5 << std::endl;
                std::cin >> ret;
                if (ret!=b+5) x += b;
                break;
            }
            x += ret;
        }
        std::cout << "! " << x << std::endl;
    }
    return 0;
}