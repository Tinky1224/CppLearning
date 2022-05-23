#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

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
//                SegmentTree L(left, mid, vals);
//                SegmentTree R(mid+1, right, vals);
//                leftNode = &L;
//                rightNode = &R;
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
    std::vector<int> vals{1,2,3,4,5,6};
    SegmentTree tree(0, 5, vals);
    std::cout << (tree.query_sum(0,5)) << std::endl;
    tree.update(1,10);
    std::cout << (tree.query_sum(0,5)) << std::endl;
    tree.update(2,10);
    std::cout << (tree.query_sum(0,5)) << std::endl;
    tree.update(5,0);
    std::cout << (tree.query_sum(0,5)) << std::endl;
    return 0;
}