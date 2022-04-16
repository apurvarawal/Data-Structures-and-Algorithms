#include<iostream>
#include<list>
using namespace std;
int main(){
    list<int> l{6,2,7,4,5};
    l.push_back(6); //we can also use l.push_front(6), to push 6 in front
    cout<<l.front()<<endl;
    l.pop_front(); //we can also use l.pop_front(), to pop front element.
    for(auto s:l){
        cout<<s<<" -> ";
    }
    //sort 
    l.sort();
    cout<<endl;
    for(auto s:l){
        cout<<s<<" -> ";
    }
    //reverse
    l.reverse();
    cout<<endl;
    for(auto s:l){
        cout<<s<<" -> ";
    }

    //calling out last element of the list
    cout<<endl<<l.back()<<endl;

    //to remove all occrences of '5' in the list
    l.remove(5);

    //to insert element in the list
    auto it = l.begin();
    it++;
    l.insert(it,11);

    //Iterate over the list
    for(auto s=l.begin(); s!=l.end(); s++){
        cout<<*s<<" -> ";
    } 
    return 0;
}