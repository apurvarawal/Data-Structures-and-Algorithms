//First we will divide the linkedlist about it's mid point, using mid point runner
//then we will apply merge sort, using recursion, and finally combine those arrays
//using the method used in "merge 2 sorted linkedlist"
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

node* merge(node* head1, node* head2){
    //base case
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    node* c;
    if(head1->data < head2->data){
        c=head1;
        c->next=merge(head1->next,head2);
    }
    else{
        c=head2;
        c->next=merge(head1,head2->next);
    }
    return c;
}

node* mergeSort(node* head){
    //base case
    if(head==NULL || head->next==NULL){
        return head;
    }
    //recursive case
    //1. find the mid point
    node* mid = midpoint(head);

    //2. divide the linkedlist in 2 equal parts
    node* a = head;
    node* b = mid->next;
    mid->next = NULL;

    //3. sort the 2 linked lists
    a = mergeSort(a);
    b = mergeSort(b);

    //4. merge the 2 linkedlist
    
    return merge(a,b);
}

int main(){
    node* head; 
    cin>>head;
    head=mergeSort(head);
    cout<<head;
    return 0;
}