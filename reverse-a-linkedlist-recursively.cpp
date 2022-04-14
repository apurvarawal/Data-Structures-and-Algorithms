#include<iostream>
using namespace std;

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

node* reverselinkedlist(node*head){//in recursive, we will pass head by value
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    //recursive case
    node* shead = reverselinkedlist(head->next);//this is the tail of the initial linkedlist
    node* temp = head->next;// temp is the last element after reversing the initial linkedlist, we are approaching towards it from the front side of initial linkedlist.
    temp->next = head; // this reversed last element will point towards the last element of the unreversed linkedlist
    head->next = NULL; // the last element has been reversed now, and it will be updated as pointing towards NULL
    return shead; //this will not change it's position, initially it was the tail, after reversing, it has become the head.
}

int main(){
    node* head; 
    cin>>head;
    cout<<head;
    head=reverselinkedlist(head);//since we are return shead, we will equate it with head,
    cout<<head;                  //to update it
    return 0;
}
