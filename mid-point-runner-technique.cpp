//In Runner technique, we will maintain 2 pointers, one will take 2 steps at a time
//the other will take 1 step at a time, when the 1st pointer reaches the end of the linked
//list, the other reaches the middle of the linked list.
#include<iostream>
using namespace std;

//TIME COMPLEXITY : O(N)

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

node* midpoint(node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }    
    node* slow = head; //initialise with the 1st element
    node* fast = head->next; //initialise with the 2nd element, so that when there are even no. of elements, we get the 1st middle element.
    while(fast!=NULL && fast->next!=NULL){
        fast=fast->next->next; //2 jumps
        slow=slow->next; //1 jump
    }
    return slow;
}

int main(){
    node* head; 
    cin>>head;
    cout<<head;
    node* mid=midpoint(head);
    cout<<mid->data<<endl;
    return 0;
}