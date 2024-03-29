#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#define ll long long

class FenwickTree{
private:
    std::vector<std::vector<ll>> mod;
public:
    int base, L;
    FenwickTree(int n){
        mod = std::vector<std::vector<ll>> (3, std::vector<ll> ((n*2+1)/3+10, 0));
        base = n;
        L = (n*2+1)/3+10;
    }
    ll update(int ind){
        int m = (ind+300000)%3, new_ind=(ind+base)/3+2, res;
        res = get(L-1,m) - get(new_ind-1, m);
        while (new_ind < L){
            mod[m][new_ind] += 1;
            new_ind += (new_ind & -new_ind);
        }
        return res;
    };
    ll get(int ind, int m){
        ll total = 0;
        while (ind > 0){
            total += mod[m][ind];
            ind -= (ind & -ind);
        }
        return total;
    }
};

class SegmentTree{
    private:
        int left, right, val, sum, max, min;
        SegmentTree *leftNode, *rightNode;
    public:
        SegmentTree(int start, int end, std::vector<int> &vals){
            left = start;
            right = end;
            if (left == right){
                val = vals[left];
                sum = val;
                max = val;
                min = val;
            }else{
                int mid = (left+right)/2;
                leftNode = new SegmentTree(left, mid, vals);
                rightNode = new SegmentTree(mid+1, right, vals);
                sum = leftNode->sum +  rightNode->sum;
                max = std::max(leftNode->max, rightNode->max);
                min = std::min(leftNode->min, rightNode->min);
            }
        }

        void update(int ind, int new_val){
            if (left==right && left == ind){
                val = new_val;
                sum = val;
                max = val;
                min = val;
                return ;
            }
            int mid = (left+right)/2;
            if (ind <= mid){
                leftNode->update(ind, new_val);
            }else{
                rightNode->update(ind, new_val);
            }
            sum = leftNode->sum + rightNode->sum;
            max = std::max(leftNode->max, rightNode->max);
            min = std::min(leftNode->min, rightNode->min);
            return ;
        }

        int query_sum(int start, int end){
            //[start, end].
            if (left == start && right == end) return sum;
            int mid = (left+right)/2;
            if (end <= mid){
                return leftNode->query_sum(start, end);
            }else if (start > mid){
                return rightNode->query_sum(start, end);
            }
            return leftNode->query_sum(start, mid) + rightNode->query_sum(mid+1, end);
        }

        int query_max(int start, int end){
            //[start, end].
            if (left == start && right == end) return max;
            int mid = (left+right)/2;
            if (end <= mid){
                return leftNode->query_max(start, end);
            }else if (start > mid){
                return rightNode->query_max(start, end);
            }
            return leftNode->query_max(start, mid) + rightNode->query_max(mid+1, end);
        }

        int query_min(int start, int end){
            //[start, end].
            if (left == start && right == end) return min;
            int mid = (left+right)/2;
            if (end <= mid){
                return leftNode->query_min(start, end);
            }else if (start > mid){
                return rightNode->query_min(start, end);
            }
            return leftNode->query_min(start, mid) + rightNode->query_min(mid+1, end);
        }
};

int main(){
    int n, q, type, x, y, x1, y1, x2, y2;
    std::cin >> n >> q;
    std::vector<int> r(n,0), c(n,0);
    SegmentTree row(0, n-1, r), col(0, n-1, c);
    while (q--){
        std::cin >> type;
        if (type == 3){
            std::cin >> x1 >> y1 >> x2 >> y2;
            if (row.query_sum(x1-1, x2-1) == x2-x1+1 || col.query_sum(y1-1, y2-1) == y2-y1+1){
                std::cout << "YES" << std::endl;
            }else{
                std::cout << "NO" << std::endl;
            }
        }else{
                std::cin >> x >> y;
                if (type == 1){
                    r[x-1]++;
                    c[y-1]++;
                    if (r[x-1] == 1) row.update(x-1, 1);
                    if (c[y-1] == 1) col.update(y-1, 1);
                }else{
                    r[x-1]--;
                    c[y-1]--;
                    if (r[x-1] == 0) row.update(x-1, 0);
                    if (c[y-1] == 0) col.update(y-1, 0);
                }
            }
    }
    return 0;
}