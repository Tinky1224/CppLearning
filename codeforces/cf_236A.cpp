#include <iostream>
#include <string>

int main(){
    bool c[26];
    for (int i=0; i<26; i++){
        c[i] = false;
    }
    std::string s;
    std::cin >> s;
    int n = s.size();
    for (int i=0; i<n; i++){
        c[int(s[i])-97] = true;
    }
    int res=0;
    for (bool b:c){
        if (b==true) res++;
    }
    if (res%2==1){
        std::cout << "IGNORE HIM!" << std::endl;
    }else{
        std::cout << "CHAT WITH HER!" << std::endl;
    }
    return 0;
}