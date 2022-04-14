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

//Why do we do dynamic allocation?
//Because in static allocation, node get destroyed.

//Functions (procedural programming)
//pass head by reference, since we are not dealing with the value of head, but the head itself.
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

void deleteAthead(node*&head){
    if(head==NULL){
        return;
    }
    node* temp = head->next; //so that we don't lose the address stores in the head.
    delete head;
    head = temp;
}

node* getnode(node* temp, int idx){
    int jump=1;
    while(jump<idx && temp!=NULL){
        temp=temp->next;
        jump++;
    }
    return temp;
}

void deleteInmiddle(node*&head, int position){
    if(head==NULL){
        return;
    }
    if(position==0){
        deleteAthead(head);
        return;
    }
    node* current=getnode(head,position);
    node* prev=getnode(head,position-1);
    prev->next=current->next;
    delete current;
}

void deleteAttail(node*&head){
    node* prev=getnode(head,length(head)-1);
    node* tail=getnode(head,length(head));
    delete tail;
    prev->next = NULL;
}

void print(node* head){
    while(head!=NULL){
        cout<<head -> data<<" -> ";
        head = head->next;
    }
    cout<<"NULL";
    cout<<endl;
}

int main(){
    node* head = NULL;
    insertAtHead(head,4);
    insertAtHead(head,2);
    insertAtHead(head,1);
    insertAtHead(head,0);

    print(head);

    insertInMiddle(head,3,3);
    insertAtTail(head,5);


    print(head);

    deleteInmiddle(head,4);
    deleteAthead(head);
    deleteAttail(head);

    print(head); 
    return 0;
} 