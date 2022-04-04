#include<iostream>
#include<string>

int main(){
    std::string s1, s2;
    std::cin >> s1 >> s2;
    int n=s1.size(), res=0;
    for (int i=0;i<n;i++){
        if (int(s1[i])<97) s1[i] = char(s1[i]+32);
        if (int(s2[i])<97) s2[i] = char(s2[i]+32);
        if (int(s1[i])<int(s2[i])){
            res=-1;
            break;
        }else if (int(s2[i])<int(s1[i])){
            res=1;
            break;
        }
    }
    std::cout << res << std::endl;
    return 0;
}