#include <iostream>
#include <string>

int main(){
    std::string ori, res;
    std::cin >> ori;
    int c1=0, c2=0, c3=0, n=ori.size();
    for (int i=0; i<n; i++){
        if (ori[i]=='1') c1++;
        else if (ori[i]=='2') c2++;
        else if (ori[i]=='3') c3++;
    }
    for (int i=0; i<c1; i++) res+="1+";
    for (int i=0; i<c2; i++) res+="2+";
    for (int i=0; i<c3; i++) res+="3+";
    res.pop_back();
    std::cout << res << std::endl;
    return 0;
}