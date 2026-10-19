class MyCircularQueue {
public:
  struct Node {
        int val;
        Node* next;
        Node(int x) : val(x), next(NULL) {}
    };

    Node* front;
    Node* rear;
    int size;
    int capacity;
    MyCircularQueue(int k) {
      front=NULL;
      rear=NULL;
      size=0;
      capacity=k;        
    }
    
    bool enQueue(int value) {
     if(isFull()) return false;  
     //dalna hai
     //dekho pehla node hai kya
     if(isEmpty()){
        Node* n=new Node(value);
        //front aur rear dono ko update kar do
        front=n;
        rear=n;
     }else{
      Node* n=new Node(value);
      rear->next=n;
      rear=n;
     }
    rear->next=front;
    size++;
      return true;
    }
    
    bool deQueue() {
    if(isEmpty()) return false;
     //first node
     if(front==rear){
        delete front;
        front=NULL;
        rear=NULL;       
     }
     else{
        Node* temp=front;
    
        front=front->next;
        rear->next=front;
        delete temp;
     }
     size--;
     return true;
    }
    
    int Front() {
      if(isEmpty()) return -1;
      return front->val;  
    }
    
    int Rear() {
       if(isEmpty()) return -1;
       return rear->val; 
    }
    
    bool isEmpty() {
       return size==0; 
    }
    
    bool isFull() {
        return (size==capacity);
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */