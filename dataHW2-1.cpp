//Implement a stack using singly linked list
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* link;
};

Node* head;

void push(int data)
{

    Node* temp = new Node();

    if (!temp)
    {
        cout << "\nStack Overflow";
        exit(1);
    }

    temp->data = data;
    temp->link = head;
    head = temp;
}

int isEmpty()
{

    return head == NULL;
}

int top()
{

    if (!isEmpty())
        return head->data;
    else
        exit(1);
}

void pop()
{
    Node* temp;

    if (head == NULL)
    {
        cout << "\nStack Underflow" << endl;
        exit(1);
    }
    else
    {

        temp = head;
        head = head->link;
        free(temp);
    }
}

void displayStack()
{
    Node* temp;

    if (head == NULL)
    {
        cout << "\nStack Underflow";
        exit(1);
    }
    else
    {
        temp = head;
        while (temp != NULL)
        {

            cout << temp->data << "-> ";
            temp = temp->link;
        }
    }
}

int getCount(Node* head)
{
    int count = 0;
    Node* current = head;
    while (current != NULL)
    {
        count++;
        current = current->link;
    }
    return count;
}

int main()
{

    push(1);
    push(3);
    push(7);
    displayStack();
    push(17);
    cout << "\nTop is " << top() << endl;
    cout << "count of nodes is " << getCount(head) << endl;
    pop();
    pop();
    push(37);
    push(71);
    pop();
    displayStack();
    cout << "\nTop is " << top() << endl;
    cout << "count of nodes is " << getCount(head);

    return 0;
}