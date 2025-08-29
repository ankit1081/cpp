// data is stored in key value pairs in map
//map - diplaying of map will be done in sorted order while random display will be done on unordered_map
// map - rb tree , unodmap - hash table
// tc of lookup, insertion and deletion (map - logn, inodmap - 1)
// in both duplicates key not allowed 
//range queries are not supported in unordered map
#include <iostream>
#include <map>
#include <unordered_map>
using namespace std;

int main()
{
    // creation
    unordered_map<string, int> m;



    // insertion
    // 1 way- make a pair and directly insert it into the map
    pair<string, int> p1 = make_pair("akki", 1);
    m.insert(p1);
    // 2 way
    pair<string, int> p2("ankit", 2);
    m.insert(p2);
    // 3 way
    m["an"] = 3;
    // 4 way
    m.insert({"nki", 4});
    // 5 way
    m.emplace("it", 4);
    // if we insert different values with same key , then the existing value will replace the new value
    // m["it"] =10; other operatiors such as m.insert({"it",10}); will not work ,only the mentioned wil work




    // serch
    cout << "............searching............" << endl;
    //1 way
    cout << m["akki"] << endl;
    //2 way
    cout << m.at("ankit") << endl;
    // non present key search will show error terminate called after throwing an instance of 'std::out_of_range'
    // cout<<m.at("david")<<endl;
    // but if we access it same key with first way then it will create an entry which will display value as 0 and
    // then the second method will also be able to display that value
    cout<< m["david"] << endl;
    cout<<m.at("david")<<endl;




    //checking size
    cout<<"............size..........."<<endl;
    cout<<m.size()<<endl;



    //checking if a key is present or not 
    cout<<"....checking key prsence......"<<endl;
    cout<<m.count("bro")<<endl;
    cout<<m.count("akki")<<endl;


    //erase 
    cout<<".....Erasing values ........."<<endl;
    m.erase("an");
    m.erase("nki");
    m.erase("it");
    cout<<m.size()<<endl;



    // display
    cout << "........display........." << endl;
    for (auto it : m)
    {
        cout << it.first << " ->" << it.second << endl;
    }
    /*display using iterator
    unordered_map<string,int>::iterator it = m.begin();
    while(it != m.end()){
        cout << it->first << " ->" << it->second << endl;
        it++;
    }*/
    return 0;
}