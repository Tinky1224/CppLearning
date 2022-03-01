#include <iostream>
#include <string>
#include <unordered_map>

int main(){
     //宣告變數 std::unordered_map<key_type, value_type>
    std::unordered_map<std::string,std::string> hash = {
        {"Hello","World"},
        {"Tinky","Winky"},
        {"Leet","Code"}
    };
    ////////////////////////////////
    //賦值的兩種方法
    //(A)使用 hash[key]=value 來插入元素，當map中key值已經存在時，會將value值覆蓋掉。
    hash["hello"] = "world";
    //(B)使用hash.insert(std::pair<key_type,value_type>(key,value))來插入元素，當hash中key值已經存在時，會回傳0。
    std::pair<std::unordered_map<std::string, std::string>::iterator, bool> respair;
    respair = hash.insert(std::pair<std::string,std::string>("hello","fucker"));
    std::cout << "insert fail return : " << respair.second << "\n";
    hash.insert(std::pair<std::string,std::string>("Mirco","soft"));
    std::cout << "insert : " << "Mirco" << hash["Mirco"] << "\n";
    std::cout << "\n";
    ////////////////////////////////
    //取值
    //(A)直接利用[key]取出元素，若key值不在map中，則會令value為預設值，例如"",0.
    std::cout << "[key] : " << hash["Tinky"] << "\n";
    //(B)使用hash.at(key)，若key值不存在，則會回報out of range. (std::out_of_range)
    std::cout << "at(key) : " << hash.at("Tinky") << "\n";
    //(C)使用hash.find(key)，獲得的並非value，而是一個iterator，分別使用iter->first, iter->second可取得key, value. 
    //若key值不存在，則會指向hash.end()，也就是hash中最後一個鍵值對的後方的位置。
    std::unordered_map<std::string, std::string>::iterator success_iter = hash.find("Tinky"), fail_iter = hash.find("TT");
    std::cout << "success : " << success_iter->first << " " << success_iter->second << "\n";
    //(D)使用hash.begin(),hash.end()來遍歷整個map以找到目標
    for (auto iter = hash.begin(); iter != hash.end(); ++iter){
        if (iter->first == "Tinky"){
            std::cout << "begin,end travel : " << iter->second << "\n";
            break;
        }
    }
    std::cout << "\n";
    ////////////////////////////////
    //獲取hash的大小
    std::cout << "size : " << hash.size() << "\n";
    std::cout << "\n";
    ////////////////////////////////
    //移除元素
    //erase中可以放入 iterator,key, (iterator,iterator) 分別代表某個(key,value), key, (key,value)的range.
    //(A) iterator
    std::cout << "original : \n";
    for (auto p:hash){
        std::cout << p.first << " : " << p.second << "\n";
    }
    std::cout << "\n";
    hash.erase(hash.begin());
    std::cout << "after erase by iterator(begin) : \n";
    for (auto p: hash){
        std::cout << p.first << " : " << p.second << "\n";
    }
    std::cout << "\n";
    //(B) key
    std::cout << "original : ]n";
    for (auto p:hash){
        std::cout << p.first << " : " << p.second << "\n";
    }
    std::cout << "\n";
    hash.erase("hello");
    std::cout << "after erase by key : \n";
    for (auto p: hash){
        std::cout << p.first << " : " << p.second << "\n";
    }
    std::cout << "\n";
    //(C) iterator, iterator (range)
    std::cout << "original : \n";
    for (auto p:hash){
        std::cout << p.first << " : " << p.second << "\n";
    }
    std::cout << "\n";
    auto iter=hash.begin();
    iter++;
    hash.erase(iter,hash.end());
    std::cout << "after erase by iterator(range) : \n";
    for (auto p: hash){
        std::cout << p.first << " : " << p.second << "\n";
    }
    std::cout << "\n";
    /////////////////////////////////////
    //清空整個map可以使用hash.clear()
    hash["A"] = "a";
    hash["B"] = "b";
    hash["C"] = "c";
    std::cout << "original : \n";
    for (auto p: hash){
        std::cout << p.first << " : " << p.second << "\n";
    }
    hash.clear();
    std::cout << "after clear : \n";
    for (auto p: hash){
        std::cout << p.first << " : " << p.second << "\n";
    }
    std::cout << "\n";
    ////////////////////////////////
    //判斷map是否為空可以使用hash.empty()
    std::cout << "empty? : " << hash.empty() << "\n";
    std::cout << "\n";
    ////////////////////////////////

    std::string key;
    std::cout << "input key : ";
    std::cin >> key;
    if (hash.find(key) == hash.end()){
        std::cout << "key error!\n" ;
    }else{
    std::cout << hash[key] << '\n';
    }
    return 0;
}