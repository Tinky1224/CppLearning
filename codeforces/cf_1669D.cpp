#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

bool Valid(std::string &s){
    int m=s.size(), R=0, B=0;
    for (char c:s){
        if (c=='R') R++;
        else B++;
    }
    if ((R && B) || m==0) return true;
    return false;
};

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    std::cin >> t;
    while(t>0){
        t--;
        int n, m;
        std::cin >> n;
        std::string s, curr;
        std::cin >> s;
        bool check = true;
        if (n==1){
            if (s=="W") std::cout << "YES" << std::endl;
            else std::cout << "NO" << std::endl;
        }else{
            curr.clear();
            for (char c:s){
                if (c=='W'){
                    if (curr.empty()) continue;
                    m = curr.size();
                    if (!Valid(curr)){
                        check = false;
                        curr.clear();
                        break;
                    }
                    curr.clear();
                }else{
                    curr.push_back(c);
                }
            }
            if (!Valid(curr)){
                check = false;
            }
            if (check) std::cout << "YES" << std::endl;
            else std::cout << "NO" << std::endl;
        }
    }
    return 0;
}