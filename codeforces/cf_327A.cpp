#include <iostream>
#include <vector>

int main(){
    int n, res=-2, curr, total=0;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i=0; i<n; i++) {
        std::cin >> a[i];
        if (a[i]) total++;
    }
    for (int i=0; i<n; i++){
        curr = 0;
        for (int j=i; j<n; j++){
            if (a[j]) curr--;
            else curr++;
            if (curr>res) res=curr;
        }
    }
    std::cout << total + res << std::endl;
    return 0;
}