#include <iostream>
#include <string>

int main(){
    std::string s;
    std::cin >> s;
    bool check = false;
    for (char c : s){
        switch(c){
            case 'H':
                check=true;
                break;
            case 'Q':
                check=true;
                break;
            case '9':
                check=true;
                break;
                break;
            default: 
                continue;
        }
    }
    if (check) std::cout << "YES" << std::endl;
    else std::cout << "NO" << std::endl;

    return 0;
}