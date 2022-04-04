#include <iostream>
#include <string>

int main(){
    std::string s;
    std::cin >> s;
    char pre=s[0];
    int accu=0;
    for (char c:s){
        if (c==pre) accu++;
        else{
            accu=1;
            pre = c;
        }
        if (accu==7) {
            std::cout << "YES" << std::endl;
            break;
        }
    }
    if (accu<7) std::cout << "NO" << std::endl;
    return 0;
}