#include <iostream>
#include <map>
#include <string>

int main(){
    int n;
    std::cin >> n;
    std::map<std::string, int> names;
    std::string name;
    for (int i=0; i<n; i++){
        std::cin >> name;
        if (names[name]==0){
            names[name]++;
            std::cout << "OK" << std::endl;
        }else{
            std::cout << name+std::to_string(names[name]++) << std::endl;
        }
    }
    return 0;
}