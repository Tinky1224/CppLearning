#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define ll long long

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while (t--){
        int n, l, r, pre1=-1, pre2=-1, curr1=0, curr2=0;
        std::cin >> n;
        std::string a, b;
        std::cin >> a >> b;
        l = 0;
        r = n-1;
        while (r >= 0){
            if (a[r]=='*' || b[r]=='*') break;
            r--;
        }
        while (l < n){
            if (a[l]=='*' || b[l]=='*') break;
            l++;
        }
        for (l; l<=r; l++){
            pre1++;
            pre2++;
            curr1 = pre1;
            curr2 = pre2;
            if (a[l]=='*' && b[l]=='*'){
                curr1 = curr2 = std::min(pre1, pre2)+1;
            }else{
                if (a[l]=='*') curr2 = std::min(pre1, pre2)+1;
                if (b[l]=='*') curr1 = std::min(pre1, pre2)+1;
            }
            pre1 = curr1;
            pre2 = curr2;
//            std::cout << "curr:" << curr1 << ", " << curr2 << std::endl;
        }
        std::cout << (std::min(curr1, curr2)) << std::endl;
    }
    return 0;
}

