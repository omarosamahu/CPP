#include <iostream>

struct Node
{
    int data;
    struct Node *next;
};

class LinkedList{
    private:
    Node *head,*tail;
    public:
    LinkedList(){
        head = NULL;
        tail = NULL;
    }
    void add_node(int n){
        //Create the node itself
        Node *tmp = new Node;
        tmp->next = NULL;
        tmp->data = n;

        if(head == NULL){
            head = tmp;
            tail = tmp;
        }
        else{
            tail->next = tmp;
            tail = tail->next;
        }
        
    }
};

int main(int argc, char const *argv[])
{
    LinkedList a;
    a.add_node(3);
    a.add_node(5);
    return 0;
}
