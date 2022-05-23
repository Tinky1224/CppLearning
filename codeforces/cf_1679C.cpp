#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cmath>
#define ll long long

class FenwickTree{
    private:
        std::vector<int> nums;
        std::vector<int> sums;
        int N;
    public:
        FenwickTree(int n){
            N = n;
            nums = std::vector<int> (n+1, 0);
            sums = std::vector<int> (n+1, 0);
        }

        bool update(int ind, int val){
            if (ind < 0 || ind >= N) return false;
            ind++;
            int diff = nums[ind]-val;
            nums[ind] = val;
            while (ind-1 < N){
                sums[ind] -= diff;
                ind += (ind & -ind);
            }
            return true;
        }

        int query(int ind){
            if (ind < 0 || ind >= N) return 0;
            ind++;
            int total=0;
            while (ind > 0){
                total += sums[ind];
                ind -= (ind & -ind);
            }
            return total;
        }

        int sum(int l, int r){
            return query(r) - query(l-1);
        }
};

int main(){
    std::cout.sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, q, type, x, y, x1, x2, y1, y2;
    std::cin >> n >> q;
    std::vector<int> row(n,0), col(n,0);
    FenwickTree R(n), C(n);
    while (q--){
        std::cin >> type;
        if (type == 3){
            std::cin >> x1 >> y1 >> x2 >> y2;
            x1--;
            x2--;
            y1--;
            y2--;
            if (R.sum(x1, x2)==x2-x1+1 || C.sum(y1, y2)==y2-y1+1) std::cout << "YES" << std::endl;
            else std::cout << "NO" << std::endl;
        }else{
            std::cin >> x >> y;
            x--;
            y--;
            if (type==1){
                row[x]++;
                if (row[x]==1) R.update(x, 1);
                col[y]++;
                if (col[y]==1) C.update(y, 1);
            }else{
                row[x]--;
                if (row[x]==0) R.update(x, 0);
                col[y]--;
                if (col[y]==0) C.update(y, 0);
            }
        }
    }
    return 0;
}