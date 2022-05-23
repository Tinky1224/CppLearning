#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class SegmentTree{
    private:
        std::vector<int> nums, counts, max, min, sum;
        int n;

        void _update(int left, int right, int curr, int ind, int val){
            if (left == right && left == ind){
                nums[curr] += val;
                if (nums[curr] == 1) counts[curr] = 1;
                else if (nums[curr] == 0) counts[curr] = 0;
            }else{
                int mid = (left+right)/2;
                if (ind <= mid) _update(left, mid, curr*2+1, ind, val);
                else _update(mid+1, right, curr*2+2, ind, val);
                counts[curr] = counts[curr*2+1] + counts[curr*2+2];
            }
        }

        int _query(int left, int right, int curr, int start, int end){
            if (left == start && right == end) return counts[curr];
            int mid = (left + right)/2;
            if (end <= mid) return _query(left, mid, curr*2+1, start, end);
            else if (start > mid) return _query(mid+1, right, curr*2+2, start, end);
            return _query(left, mid, curr*2+1, start, mid) + _query(mid+1, right, curr*2+2, mid+1, end);
        }
    public:
        SegmentTree(int size){
            n = size;
            nums.resize(4*n);
            counts.resize(4*n,0);
        }

        void update(int ind, int val){
            _update(0, n-1, 0, ind, val);
        }

        int query(int start, int end){
            return _query(0, n-1, 0, start, end);
        }
};

int main(){
    int n, q, type, x, y, x1, y1, x2, y2;
    std::cin >> n >> q;
    SegmentTree row(n), col(n);
    while (q--){
        std::cin >> type;
        if (type == 3){
            std::cin >> x1 >> y1 >> x2 >> y2;
            if (row.query(x1-1, x2-1) == x2-x1+1 || col.query(y1-1, y2-1) == y2-y1+1){
                std::cout << "YES" << std::endl;
            }else{
                std::cout << "NO" << std::endl;
            }
        }else{
                std::cin >> x >> y;
                if (type == 1){
                    row.update(x-1, 1);
                    col.update(y-1, 1);
                }else{
                    row.update(x-1, -1);
                    col.update(y-1, -1);
                }
            }
    }
    return 0;
}