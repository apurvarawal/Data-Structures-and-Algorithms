//We will take node*c, which will point to the smallest 1st element of either of the 2 sorted linkedlist.
//If it points to the 1st element of the 1st linkedlist, then we will point to the next element of the same 
//linkedlist, using recursion. Similarly, it will point to elements of the 2nd linkedlist.
//If the 1st linked list ends, we will return the 2nd linked list, since it's already sorted and vice versa.
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

void insertAtTail(node* &head, int data){
    if(head==NULL){
        head = new node(data);
        return;
    }
    node* tail = head;
    while(tail->next!=NULL){ //we are moving the tail in the backward direction
        tail=tail->next;;
    }
    tail->next = new node(data);
    return;
}

int length(node* head){ //since we are not concerned with the value at head, we will pass the node by value.
    int cnt=0;
    while(head!=NULL){
        cnt++;
        head=head->next;
    }
    return cnt;
}

void insertInMiddle(node* &head, int data, int position){
    //corner case
    if(head==NULL || position==0){
        insertAtHead(head,data);
    }
    else if(position>length(head)){
        insertAtTail(head,data);
    }
    else{
        //take position-1 jumps
        int jump=1;
        node* temp = head; // initially
        while(jump<=position-1){
            temp=temp->next;
            jump++;
        }
        node* n = new node(data);
        n->next=temp->next; //we need to pass the address of the node which is present after temp, 
                            //since it's address is stored in temp->next, we will write this.
        temp->next=n;
    }
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

node* merge(node* head, node* head2){
    //base case
    if(head==NULL){
        return head2;
    }
    if(head2==NULL){
        return head;
    }
    node* c;
    if(head->data < head2->data){
        c=head;
        c->next=merge(head->next,head2);
    }
    else{
        c=head;
        c->next=merge(head->next,head2);
    }
    return c;
}

int main(){
    node* head; 
    node* head2;
    cin>>head>>head2;
    node* order = merge(head,head2);
    cout<<order;
    return 0;
}