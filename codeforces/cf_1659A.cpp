#include <iostream>
#include <string>

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t, n, r, b, max;
    std::cin >> t;
    std::string res; 
    for (int i=0; i<t; i++){
        res.clear();
        std::cin >> n >> r >> b;
        if (r==b){
            for (int j=0; j<r; j++) res+="RB";
        }else if (r>b){
            max = r/(b+1) + (r%(b+1)>0);
            while (r>b+max && b>0){
                for (int j=0; j<max; j++) res += 'R';
                res += 'B';
                r -= max;
                b--;
            }
            for (int j=r-b; j>0; j--){
                res += 'R';
                r--;
            }
            while (r>0 && b>0){
                res += "BR";
                r--;
                b--;
            }
        }else{
            max = b/(r+1) + (b%(r+1)>0);
            while (b>r+max && b>0){
                for (int j=0; j<max; j++) res += 'B';
                res += 'R';
                b -= max;
                r--;
            }
            for (int j=b-r; j>0; j--){
                res += 'B';
                b--;
            }
            while (r>0 && b>0){
                res += "RB";
                r--;
                b--;
            }
        }
        std::cout << res << std::endl;
    }
    return 0;
}