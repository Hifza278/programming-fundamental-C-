#include<iostream>

using namespace std;

class node
{
    public:
        int data;
        node* next;
    
        node(int val)
        {
            data = val;
            next = NULL;        
        }
};

class List
{
    private:
        node* head;
        int length;
    public:
        List()
        {
            head = NULL;
            length = 0;
        }
        void insertFirst(int val);
        void insertLast(int val);
        void insertMid(int val, int pos);
        void insert(int val, int pos);
        void printList();
        void deleteFrom(int pos);
        void deleteVal(int val); //do yourself
        int searchInd(int val); //do yourself
        int findMin(); //do yourself
        int findMax(); //do yourself
        int findSum(); //do yourself
        bool search(int val);
        bool isEmpty();
};

void List::insert(int val, int pos)
{
    if (pos < 1 || pos >  (length+1))
    {
        cout<<"Invalid position!"<<endl;
        return;
    }
    
    node* n = new node(val);

    if(pos == 1)
    {
        n->next = head;
        head = n;
    }
    else
    {
        node* curr = head;

        for (int i = 1; i < (pos - 1); i++)
        {
            curr = curr->next;
        }
        
        n->next = curr->next;
        curr->next = n;        
    }
    length++;    
}

void List::insertFirst(int val)
{
    node* n = new node(val);
    
    if(head == NULL) //if the list is empty
    {
        head = n;
        length++;
        return;
    }
    n->next = head; 
    head = n;   
    length++;
}

void List::insertLast(int val)
{
    node* n = new node(val);
    
    if(head == NULL)
    {
        head = n;
        length++;
        return;
    }
    node* curr = head;

    while (curr->next != NULL)
    {
        curr = curr->next;
    }
    curr->next = n;
    length++;    
}

void List::insertMid(int val, int pos)
{
    node* n = new node(val);
    node* curr = head;
    int count = 1;

    while (count < (pos - 1))
    {
        curr = curr->next;
        count++;
    }
    n->next = curr->next;
    curr->next = n; 
    length++;   
}

void List::printList()
{
    if(isEmpty()) //head == NULL
    {
        cout<<"List is empty!"<<endl;
        return;
    }

    node* curr = head;
    while (curr != NULL)
    {
        cout<<curr->data<<"\t";
        curr = curr->next;
    }
    cout<<endl;
}

bool List::isEmpty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

bool List::search(int val)
{
    if (isEmpty())
        cout<<"List is empty!"<<endl;
    else
    {
        node* curr = head;
        while (curr != NULL)
        {
            if(curr->data == val)
                return true;
            curr = curr->next;
        }
        return false;       
    }
}

void List::deleteFrom(int pos)
{
    if (pos < 1 || pos > length)
    {
        cout<<"Invalid Position"<<endl;
        return;
    }

    node* curr = head;
    
    if(pos == 1) //delete head
    {
        head = curr->next;
        delete curr;
    }
    else
    {
        for (int i = 1; i < (pos-1); i++) //stop a node before the one to be deleted
            curr = curr->next;

        node* delptr = curr->next; //node to be deleted
        curr->next = curr->next->next; //curr->next = delptr->next;
        delete delptr;
    }
    length--; //length decreased
}

int main()
{
    List l;
    l.deleteFrom(4);
    l.insertFirst(0);
    l.insertFirst(1);
    l.insertFirst(2);
    l.insertMid(4, 2);
    l.insert(7, 5);
    l.insert(-1, 1);
    l.insert(8, 3);
    l.printList();
    if(l.search(81))
        cout<<"found!"<<endl;
    else
        cout<<"not found!"<<endl;

    l.deleteFrom(7);
    l.printList();
    return 0;
}

