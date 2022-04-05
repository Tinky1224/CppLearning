#include <iostream>
#include <string>

int main(){
    std::string s;
    std::cin >> s;
    bool change=true;
    for (int i=0; i<s.size(); i++){
        if (int(s[i])>96){
            if (i==0){
                continue;
            }else{
                change=false;
                break;
            }
        }
    }
    if (change){
        for (int i=0; i<s.size(); i++){
            if (int(s[i])<97) s[i] = char(int(s[i])+32);
            else s[i] = char(int(s[i])-32);
        }
    }
    std::cout << s << std::endl;
    return 0;
};