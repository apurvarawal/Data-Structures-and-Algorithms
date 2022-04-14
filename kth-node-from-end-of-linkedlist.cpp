//In this we will maintain 2 pointers, fast and slow, both starting from the 1st element,
//fast will initially take (n-k) jumps, while the slow pointer will remain at the start.
//then the fast pointer will again take (n-k) steps, and now for it's each step, the slow 
//pointer will take one step forward.
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

int length(node* head){ //since we are not concerned with the value at head, we will pass the node by value.
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}

node* kthElement(node* head, int k){
    if(head==NULL || head->next==NULL){
        return head;
    }    
    node* slow = head; 
    node* fast = head; 
    int i=1;
    while(k--){
        fast=fast->next; //it will take (n-k) steps
    }
    if(fast==NULL){
        return NULL; //as we need to find the nextt element to this, and fast has become NULL, so the next element will be obviously NULL.
    }
    while(fast!=NULL){
        slow=slow->next;
        fast=fast->next;
    }
    return slow;
}

int main(){
    node* head; 
    cin>>head;
    cout<<head;
    node* kth=kthElement(head,5);
    cout<<kth->data<<endl;
    return 0;
}