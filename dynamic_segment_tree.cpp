#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

class SegmentTree{
    private:
        long long left=0, right=1000000000, val=0, sum=0;
        SegmentTree *leftNode=nullptr, *rightNode=nullptr;
    public:
        SegmentTree(){}
        SegmentTree(long long start, long long end){
            left = start;
            right = end;
        }
        SegmentTree(long long start, long long end, long long value){
            left = start;
            right = end;
            val = value;
            sum = val * (right-left+1);
        }

        void reset(long long start=0, long long end=1000000000, long long value=0){
            if (leftNode){
                leftNode->reset();
                delete leftNode;
                leftNode = nullptr;
                rightNode->reset();
                delete rightNode;
                rightNode = nullptr;
            }
            left = start;
            right = end;
            val = value;
            sum = val * (right-left+1);
            return ;
        }

        void update(long long start, long long end, long long value){
            if (start == left && end == right){
                reset(left, right, value);
                return ;
            }
            long long mid = (left+right)/2;
            if (!leftNode || !rightNode){
                leftNode = new SegmentTree (left, mid, val);
                rightNode = new SegmentTree (mid+1, right, val);
            }
            if (end <= mid){
                leftNode->update(start, end, value);
            }else if (start > mid){
                rightNode->update(start, end, value);
            }else{
                leftNode->update(start, mid, value);
                rightNode->update(mid+1, end, value);
            }
            sum = leftNode->sum + rightNode->sum;
            return ;
        }

        long long query_sum(long long start, long long end){
            //[start, end].
            if (left == start && right == end) return sum;
            if (!leftNode) return val*(end-start+1);;
            long long mid = (left+right)/2;
            if (end <= mid){
                return leftNode->query_sum(start, end);
            }else if (start > mid){
                return rightNode->query_sum(start, end);
            }
            return leftNode->query_sum(start, mid) + rightNode->query_sum(mid+1, end);
        }

};

int main(){
    int type, left, right, val;
    SegmentTree tree;
    std::cout << "-1: quit." << std::endl;
    std::cout << "0: reset, input:left, right, val." << std::endl;
    std::cout << "1: update, input:left, right, val." << std::endl;
    std::cout << "2: query, input:left, right." << std::endl;
    while (true){
        std::cin >> type;
        if (type==-1) break;
        else if (type==0){
            std::cin >> left >> right >> val;
            tree.reset(left, right, val);
        }else if (type==1){
            std::cin >> left >> right >> val;
            tree.update(left, right, val);
        }else if (type==2){
            std::cin >> left >> right;
            std::cout << (tree.query_sum(left, right)) << std::endl;
        }else{
            std::cout << "invalid input!" << std::endl;
        }
    }
    return 0;
}