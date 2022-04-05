#include <iostream>
#include <string>

int main(){
    std::string s, target="olleh";
    std::cin >> s;
    for (char c:s){
        if (c==target.back()) target.pop_back();
        if(target.empty()) break;
    }
    if (target.empty()) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;
    return 0;
}