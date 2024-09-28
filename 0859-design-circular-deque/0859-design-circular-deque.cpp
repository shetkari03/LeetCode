class MyCircularDeque {
public:
class Node {
public:
    // Data part of the node.
    int val;
    // Pointer to the next node.
    Node* next;
    // Pointer to the previous node.
    Node* prev;

    // Constructor to initialize the node with given data.
    Node(int val)
    {
        this->val = val;
        this->next = nullptr;
        this->prev = nullptr;
    }
};
Node* head=new Node(0);
Node* tail=new Node(0);
int n=0,m=0;
    MyCircularDeque(int k) {
        n=k;
    }
    
    bool insertFront(int value) {
        if(n==m)return 0;
        Node* temp=new Node(value);
        if(m==0){
            head=temp;
            tail=temp;
        }
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;
        }
        m++;
        return 1;
    }
    
    bool insertLast(int value) {
        if(m==n)return 0;
        Node* temp=new Node(value);
        if(m==0){
            tail=temp;
            head=temp;
        }
        else{
            tail->next=temp;
            temp->prev=tail;
            tail=temp;
        }
        m++;
        return 1;
    }
    
    bool deleteFront() {
        if(m==0)return 0;
        head=head->next;
        m--;
        return 1;
    }
    
    bool deleteLast() {
        if(m==0)return 0;
        tail=tail->prev;
        m--;
        return 1;
    }
    
    int getFront() {
        if(m==0)return -1;
        return head->val;
    }
    
    int getRear() {
        if(m==0)return -1;
        return tail->val;
    }
    
    bool isEmpty() {
        return (!m);
    }
    
    bool isFull() {
        return (m==n);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */