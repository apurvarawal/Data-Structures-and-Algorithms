//We will not use swapping for this, as it is expensive so using it 
//is a bad idea. 
#include<iostream>
using namespace std;

//with the help of operator overloading, there is no need to write the
//print function for every linkedlist.

class node{
    public:
    int data;
    node* next;

    node(int data){
        this -> data = data;
        this -> next = NULL;
    }
};

void insertAtHead(node* &head, int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    //1. make a new node for the given data
    node* n = new node(data);
    //2. store the address of head in the second box of node
    n->next = head; //(*n).next = head
    //3. make the newly created node as the head of the list
    head = n;
}

void print(node* head){
    while(head!=NULL){
        cout<<head -> data<<" -> ";
        head = head->next;
    }
    cout<<"NULL";
    cout<<endl;
}

node* inputdata(){
    int data;
    cin>>data;
    node* head=NULL;
    while(data!=-1){
        insertAtHead(head,data);
        cin>>data;
    }
    return head;
}

ostream& operator<<(ostream &p, node* head){ //since we didn't had to modify head, so we passed it by value
    print(head);
    return p;// it will return cout
}

istream& operator>>(istream &k,node*&head){ //since we have to modify the head, so we will pass it by reference.
    head=inputdata();
    return k;
}

//O(N) time and O(1) stack (more efficient than recursive)

void reverselinkedlist(node*&head){
    node* prev = NULL;
    node* current = head;
    node* n; //next node
    while(current!=NULL){
        //save the next node
        n = current->next;
        //make the current node point to prev
        current->next=prev;
        prev=current;
        current=n;
    }
    head=prev;
}

int main(){
    node* head; 
    cin>>head;
    cout<<head;
    reverselinkedlist(head);
    cout<<head;
//=>cout<<head2 (once head has been printed)
    return 0;
}
