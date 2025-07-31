#include<iostream>
#include<list>
#include<iterator>
using namespace std;

void printLL(list<int>ll){
    list<int> :: iterator itr;
    for(itr = ll.begin(); itr != ll.end(); itr++){
        cout<< (*itr)<<" -> ";
    }
    cout<<"NULL"<<endl;
}

int main(){
    list<int>ll;

    ll.push_front(2);
    ll.push_front(1);
    ll.push_back(3);
    ll.push_back(4);

    printLL(ll);

    cout<<"Size = "<<ll.size()<<endl;
    cout<<"Head = "<<ll.front()<<endl;
    cout<<"Tail = "<<ll.back()<<endl;

    // ll.pop_front();
    // printLL(ll);
    // ll.pop_back();
    // printLL(ll);

    ll.insert(ll.begin(), 5);  
    printLL(ll); 


    ll.insert(ll.end(), 50);   
    printLL(ll); 

    auto it = ll.begin();
    advance(it, 2);
    ll.insert(it, 20);
    printLL(ll);

    // 4. Insert multiple copies
    it = ll.begin();
    advance(it, 2);  
    ll.insert(it, 2, 15); 

    printLL(ll);  

    return 0;
}