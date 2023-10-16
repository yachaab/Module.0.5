#include <iostream>

class List
{
private:
    class Node;
private:
    Node* head;
    Node* tail;
public:
    List();
    void pushBack( int );
    void getHead();
};

class List::Node
{
public:
    int data;
    Node* next;
    Node* prev;
public:
    Node( int );
};

List::List() : head ( NULL ), tail ( NULL ) { std::cout << "Calling List()\n"; }

List::Node::Node( int data ) : data ( data ) { std::cout << "Calling Node()\n"; }

void List::pushBack( int data )
{
    if ( !head )
        head = new Node( data );
    else
    {
        Node* tmp = head;
        while ( tmp->next )
            tmp = tmp->next;
        tmp->next = new Node( data );
        tmp->next->prev = tmp;
    }
}

void List::getHead()
 {
    Node* tmp = head;
    while ( tmp )
    {
        std::cout << tmp->data << "\n";
        tmp = tmp->next;
    }
}

int main()
{
    List* lst = new List();
    lst->pushBack( 1 );
    lst->pushBack( 2 );
    lst->getHead();

}