#include <iostream>
#include <vector>

int main(){
    //宣告陣列<element type>
    std::vector<int> List = {1,2,3,4,5};
    //獲取容量
    //使用vector.capacity()
    std::cout << "List.capacity() : " << List.capacity() << "\n";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //獲取大小
    //使用vector.size()
    std::cout << "List.size() : " << List.size() << "\n";
    std::cout << "\n";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //是否為空
    //使用vector.empty()
    std::cout << "List.empty() : " << List.empty() << "\n";
    std::cout << "\n";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //新增元素
    //(A)使用List.push_back(element)將元素放到List的尾端。PS.會自動判定是否需要額外的記憶體，可能會導致效能降低，所以盡量能自己取好空間就先取好空間。
    std::cout << "original : [";
    for(int i=0; i<List.size(); i++) std::cout << List[i] << ", ";
    std::cout << "]\n";
    std::cout << "List.push_back(2) : [";
    List.push_back(2);
    for(int i=0; i<List.size(); i++) std::cout << List[i] << ", ";
    std::cout << "]\n";
    //(B)emplace_back(element)類似push_back(),只是他需要已經有空間才能放入，否則可能出現error.
    std::cout << "original : [";
    for(int i=0; i<List.size(); i++) std::cout << List[i] << ", ";
    std::cout << "]\n";
    std::cout << "List.emplace_back(6) : [";
    List.emplace_back(6);
    for(int i=0; i<List.size(); i++) std::cout << List[i] << ", ";
    std::cout << "]\n";
    //(C)-(1)使用vector.insert(pos(iterator),element)來將元素插入至指定位置。
    std::cout << "original : [";
    for(int i=0; i<List.size(); i++) std::cout << List[i] << ", ";
    std::cout << "]\n";
    List.insert(List.begin()+2,1);
    std::cout << "List.insert(List.begin()+2,1) : [";
    for(int i=0; i<List.size(); i++) std::cout << List[i] << ", ";
    std::cout << "]\n";
    //(C)-(2)使用vector.insert(pos(iterator),times.element)來指定插入的次數。
    List.insert(List.begin()+3,3,3);
    std::cout << "List.insert(List.begin()+3,3,3): [";
    for(int i=0; i<List.size(); i++) std::cout << List[i] << ", ";
    std::cout << "]\n";
    //(C)-(3)使用vec1.insert(vec1.pos,vec2.startpos,vec2.endpos)來將別的vector的部分插入vec1的指定位置。
    std::vector<int> vec2 = {9999,9998,9997,9996,9995,9994,9993,9992,9991,9990};
    std::cout << "original : [";
    for(int i=0; i<List.size(); i++) std::cout << List[i] << ", ";
    std::cout << "]\n";
    List.insert(List.begin()+5,vec2.begin()+4,vec2.end());
    std::cout << "List.insert(List.begin()+5,vec2.begin()+4,vec2.end()) : [";
    for(int i=0; i<List.size(); i++) std::cout << List[i] << ", ";
    std::cout << "]\n";
    std::cout << "\n";
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //增加vector的容量，因為push_back()在遇到容量不足時，會自動將空間變成兩倍大，在某些時候這是很沒有效率的選擇，所以我們可以自己手動增加空間來增加效能。
    //(A)vector.reserve(N):
    //若N<=原本的容量，則什麼都不會做。
    //當N>原本的容量時，會額外配置一個大小為N的空間，將原本vector的資料copy到新的空間，再重置原本的vector，最後再更新陣列的起點、終點、容量。
    //所以在最開始的時候就reserve出空間比較好，可以節省copy資料的時間。
    std::cout << "original : " << "capacity : " << List.capacity() << "\n";
    List.reserve(List.capacity()-1);
    std::cout << "List.reserve(List.capacity()-1) : " << "capacity : " << List.capacity() << "\n";
    List.reserve(List.capacity()+1);
    std::cout << "List.reserve(List.capacity()+1) : " << "capacity : " << List.capacity() << "\n";
    std::cout << "\n";
    //(B)vector.resize(N,element=default): 這是改變vector內的元素個數，若是>N，則從尾端開始清除，不會改變容量。
    //若是<=N，則會在尾端補上內容型態的預設值(0,"",...)。
    //在補值的時候若capacity不夠，則會跑一次reserve的流程，確保有足夠的空間。
    std::cout << "original : [";
    for(int i=0; i<List.size(); i++) std::cout << List[i] << ", ";
    std::cout << "]\n";
    std::cout << "original size : " << List.size() << "\noriginal capacity : " << List.capacity() << "\n";
    List.resize(List.size()-5);
    std::cout << "List.resize(List.size()-5) : [";
    for(int i=0; i<List.size(); i++) std::cout << List[i] << ", ";
    std::cout << "]\n";
    std::cout << "new size : " << List.size() << "\nnew capacity : " << List.capacity() << "\n";
    List.resize(List.capacity()+5);
    std::cout << "List.resize(List.capacity()+10) : [";
    for(int i=0; i<List.size(); i++) std::cout << List[i] << ", ";
    std::cout << "]\n";
    std::cout << "new size : " << List.size() << "\nnew capacity : " << List.capacity() << "\n";
    std::cout << "\n";
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //獲取元素的值
    //(A)使用[index]取值
    std::cout << "List[0] : " << List[0] << "\n";
    //(B)使用List.at(index)
    std::cout << "List.at(0) : " << List.at(0) << "\n";
    //(C)使用List.front()或List.back()獲取第一個或最後一個值
    std::cout << "List.front() : " << List.front() << "\n";
    std::cout << "List.back() : " << List.back() << "\n";
    std::cout << "\n";
    ///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //獲取疊代器(iterator)
    //(A)vector.begin()/vector.end()
    //vector.begin()是指向vector第一個元素的iterator, vector.end()是指向vector最後一個元素"下一個位置"的iterator.
    std::cout << "begin->end : [";
    for (auto iter = List.begin(); iter != List.end(); iter++) std::cout << *iter << ", ";
    std::cout << "]\n";
    //(B)vector.rbegin()/vector.rend()
    //vector.rbegin()則相反，rbegin()指向最後一個元素，rend()指向第一個元素。
    std::cout << "end->begin : [";
    for (auto iter = List.rbegin(); iter != List.rend(); ++iter) std::cout << *iter << ", ";
    std::cout << "]\n";
    std::cout << "\n";

    return 0;
}