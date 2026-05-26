#include <iostream>
//#include "LinkedList.cpp"
#include "DoublyLinkedList.cpp"


using namespace std;

void append(int value);
void printList();

int main(){
DoublyLinkedList* myDLL = new DoublyLinkedList(1);
    myDLL->append(2);
    myDLL->append(3);
    myDLL->append(4);
    myDLL->append(5);


    cout << "DLL before deleteNode():\n";
    myDLL->printList();


    myDLL->deleteNode(2);
    cout << "\nDLL after deleteNode() in middle:\n";
    myDLL->printList();


    myDLL->deleteNode(0);
    cout << "\nDLL after deleteNode() of first node:\n";
    myDLL->printList();


    myDLL->deleteNode(2);
    cout << "\nDLL after deleteNode() of last node:\n";
    myDLL->printList();




}
