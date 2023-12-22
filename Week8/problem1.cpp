#include<iostream>
using std::cout;
using std::cin;
class Node{
private:
    int value;
    Node *next = nullptr;
    Node *prev = nullptr;
public:
    Node(int value = 0): value(value){}
    void Linkforward(Node *nextNode){
        next = nextNode;
        if(nextNode != nullptr){
        nextNode -> prev = this;
        }
    }
friend void showForward(Node *node);
friend void showBackward(Node *node);
friend void insertNode(Node *&head, Node *&tail, Node *pirorNode, Node *newNode);
};
    void insertNode(Node *&head, Node *&tail, Node *pirorNode, Node *newNode){
        if (pirorNode == nullptr )
        {
            newNode->Linkforward(head);
            head = newNode;
        }
        else if(pirorNode == tail){
            newNode->Linkforward(tail);
            tail = newNode;
        }
        else{
            newNode->Linkforward(pirorNode->next);
            pirorNode->Linkforward(newNode);
        }
        
    }
     void showForward(Node *node){
        printf("\n\nDoubl Linked List Node:  \n");
        Node *temp = node;
        while (temp != nullptr)
        {
            cout << temp->value << " --> ";
            temp = temp->next; //access next node
        }
    }
     void showBackward(Node *node){
        printf("\n\nDoubl Linked List Node:  \n");
        Node *temp = node;
        while (temp != nullptr) {
        cout << temp->value << " --> ";
        temp = temp->prev; //access next node
}
    }
int main(){
    Node node1(1);
    Node node2(6);
    Node node3(8);
    Node node4(2);
    Node *head = &node1;
    node1.Linkforward(&node2);
    node2.Linkforward(&node3);
    node3.Linkforward(&node4);
    Node *tail = &node4;

    showForward(head);
    showBackward(tail);
    cout<<"\n";
    Node node5(100);
    insertNode(head, tail,&node1, &node5);
    showForward(head);
    showBackward(tail);
    Node node6(300);
    insertNode(head, tail, nullptr, &node6);
    showForward(head);
    showBackward(tail);
    return 0; 
}