#include <iostream>
#include <string>

int main(){
    std::string s;
    std::cin >> s;
    if (int(s[0])>96){
        s[0] = char(int(s[0])-32);
    }
    std::cout << s << std::endl;
    return 0;
}