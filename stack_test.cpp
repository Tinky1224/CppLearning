#include <iostream>
#include <stack>

int main(){
    std::stack<int> stack;
    //放入元素。PS.放進去的是一個copy，不在同個位置。
    stack.push(123);
    //獲取元素個數
    std::cout << "stack.size() : " << stack.size() << "\n";
    //取得最上方的元素的reference，若stack是空的，則會出現runtime error.
    int &tmp = stack.top();
    std::cout << "stack.top() : " << tmp << "\n";
    //移除最上方的元素(最後進入)，若stack是空的，則會出現runtime error.
    stack.pop();
    //檢查stack是否為空
    std::cout << "stack.empty() : " << stack.empty() << "\n";
    return 0;
}