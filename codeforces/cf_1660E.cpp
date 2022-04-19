//1600 Matrix and shifts
#include <iostream>
#include <vector>
#include <string>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, n, total, best;
    std::string row;
    std::cin >> t;
    for (int CASE=0; CASE<t; CASE++){
        total=0;
        best=0;
        std::cin >> n;
        std::vector<int> accu(n,0);

        for (int r=0; r<n; r++){
            std::cin >> row;
            for (int c=0; c<n; c++){
                if (row[c]=='1') {
                    accu[(c-r+n)%n]++;
                    total++;
                }
            }
        }

        for (int num:accu){
            if (num>best) best = num;
        }

        std::cout << (total-2*best+n) << std::endl;
    }
    return 0;
}