#include <iostream>
#include <vector>

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
};