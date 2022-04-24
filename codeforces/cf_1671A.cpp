#include <iostream>
#include <string>

int main(){
    int t;
    std::cin >> t;
    while (t--){
        std::string s;
        std::cin >> s;
        int curr = 0;
        char pre=s[0];
        bool check = true;
        for (char c:s){
            if (c!=pre){
                if (curr < 2){
                    check = false;
                    break;
                }
                pre = c;
                curr = 1;
            }else{
                curr++;
            }
        }
        if (curr==1) check = false;
        if (check) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
}