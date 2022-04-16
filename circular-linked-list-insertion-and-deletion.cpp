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

void insert(node* &head, int data){ //at head
    node* n = new node(data);
    node* tail = head;
    n -> next = head;

    if(tail!=NULL){ //more than one element is present, then we will find the tail.
        while(tail->next != head){
            tail = tail->next;
        }
        tail->next = n;
    }
    else{
        n->next = n; //self loop, if there is single element in the linked list.
    }
    head = n;
}

node* getnode(node* &head, int data){
    node* temp = head;
    while(temp->next!=head){
        if(temp->data==data){
            return temp;
        }
        temp=temp->next;
    }
    if(temp->data==data){ //for last node
        return temp;
    }
    return NULL;
}

void deleteElement(node* &head, int data){
    node* del = getnode(head,data);
    if(del==NULL){
        return;
    }

    node* temp = head;
    if(head==del){
        head=head->next;
    }
    
    while(temp->next!=del){
        temp = temp->next; //element before del
    }
    temp->next = del->next;
    delete del;
}

void print(node* head){
    node* tail = head;
    while(tail->next!=head){
        cout<<tail->data<<" -> ";
        tail = tail->next;
    }
    cout<<tail->data; //to print the last node (explicitly)
    return;
}

int main(){
    node* head = NULL;
    insert(head,10);
    insert(head,20);
    insert(head,30);
    insert(head,40);
    insert(head,50);
    deleteElement(head,30);
    print(head);
    return 0;
}