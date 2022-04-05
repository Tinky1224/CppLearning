#include <iostream>
#include <string>

int main(){
    std::string s, res;
    std::cin >> s;
    for (char c:s){
        if (int(c)<97){
            c = char(int(c)+32);
        }
        if (c!='a' && c!='e' && c!='i' && c!='o' && c!='u' && c!='y'){
            res.push_back('.');
            res.push_back(c);
        }
    }
    std::cout << res << std::endl;
    return 0;
}