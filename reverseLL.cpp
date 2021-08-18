#include <iostream>
using namespace std;

/* Link list node */
struct Node {
    int data;
    struct Node* next;
    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

    //Reverse Recursive

struct Node*reverseRecursive(Node*head)
    {
        if(head==NULL||head->next==NULL){
            return head;
        }
        Node *NewHead=reverseRecursive(head->next);
        head->next->next=head;
        head->next=NULL;
        return NewHead;
    }

struct LinkedList {
    Node* head;
    LinkedList() { head = NULL; }


    /* Function to reverse the linked list */
    void reverse()
    {
        // Initialize current, previous and
        // next pointers
        Node* current = head;
        Node *prev = NULL, *next = NULL;

        while (current != NULL) {
            // Store next
            next = current->next;

            // Reverse current node's pointer
            current->next = prev;

            // Move pointers one position ahead.
            prev = current;
            current = next;
        }
        head = prev;
    }

    /* Function to print linked list */
    void print()
    {
        struct Node* temp = head;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }

    void push(int data)
    {
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }
};

/* Driver code*/
int main()
{   Node * START;
   START=NULL;
    /* Start with the empty list */
    LinkedList ll;
    ll.push(20);
    ll.push(4);
    ll.push(15);
    ll.push(85);

    cout << "Given linked list\n";
    ll.print();

    ll.reverse();
    Node*newHead=reverseRecursive(START);

    cout << "\nReversed Linked list \n";
    ll.print();
    return 0;
}
