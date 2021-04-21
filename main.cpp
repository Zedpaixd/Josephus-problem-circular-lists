#include <iostream>
#include <Windows.h>
#include <conio.h>
using namespace std;


class node

    {private:
        int data;
    public:
        node* next;
        node* prev;
        node* operator = (node*);
        node (int = -1, node* = nullptr, node* = nullptr); // default constructor
        node (const node&); // copy constructor
        float show() const;
        void set(float);};



node::node(int tmp, node* nxt, node* prv)

    {data = tmp;
    next = nxt;
    prev = prv;}



node::node(const node& to_copy)

    {next = to_copy.next;
    prev = to_copy.prev;
    data = to_copy.data;}



float node::show() const

    {return data;}



void node::set(float tmp)

    {data = tmp;}



node* node::operator=(node* element)

    {if (this != element)
        {data = element->data;
        next = element->next;
        prev = element->prev;}

    return this;}


class c_list

    {private:
        node* first;
        node* last;
    public:
        void josephusProblem(int, node*);
        int size = 0;
        c_list (node* = nullptr, node* = nullptr);
        node* getNode(int);
        void show() const;
        void insert( node * );
        void print() const;
        node* list_3rd (node*) const;
        void removeNode (node *);};



void c_list::removeNode(node* to_remove)

    {
    if (size == 0) return;
    if (to_remove == first)
    {
        first->next->prev = first->prev;
        first->prev->next = first->next;
        first = first->next;
        size--;
    }
    else if (to_remove == last)
    {
        last->next->prev = last->prev;
        last->prev->next = last->next;
        last = last->prev;
        size--;
    }
    else if (size != 1)
    {
        to_remove->next->prev = to_remove->prev;
        to_remove->prev->next = to_remove->next;
        to_remove = to_remove->next;
        size--;
    }
}


node* c_list::getNode(int index)
{
    node* temp = first;
    int something=0;
    while (something < index)
    {
        temp = temp->next;
        something++;
    }
    return temp;
}


node* c_list::list_3rd(node* given) const

    {int  i = 0;
    if (size > 1)
    {
     node* thirdElem;
    thirdElem = given;
    thirdElem->next = given->next;
    while (i < 3) {
        thirdElem = thirdElem->next;
        if (i == 2) std::cout << "3rd element from given one is: "<<thirdElem->show() << std::endl;
        i++;
    }
    return thirdElem;
    }
    if (size == 1)
        return given;
    }



void c_list::print() const

    {node* show;
    int i = 0;
    if (size != 0)
        {show = first;
        while (i < size)
            {std::cout << show->show() << "  ";
            show = show->next;
            i = i + 1;}
        }
};



void c_list::show() const

	{std::cout << "First element in list : \n"
              << first->show()
              << "\nLast element in list : \n"
              << last->show()
              << "\nSize of list: \n"
              << size << std::endl;}



c_list::c_list(node* f, node* l)

	{first = f;
	last = l;
	if ((first != nullptr) || (last != nullptr))
        size = size + 1;

    if ((first != nullptr) && (last != nullptr))
        {first->next = last;
        last->prev = first;
        first->prev = last;
        last->next = first;
        size = size + 1;}}



void c_list::insert(node* to_add)

    {
        if (size == 0)
        {first = to_add;
        size = size + 1;}

    else

        {if (last == nullptr)
            {last = to_add;
            first->next = last;
            last->prev = first;
            last->next = first;
            first->prev = last;
            size = size + 1;}

        else
            {to_add->prev = last;
            last->next = to_add;
            last = to_add;
            first->prev = last;
            last->next = first;
            size = size + 1;}
        }
}

void c_list::josephusProblem(int key, node* givenNode)
{
    node* temp = new node;
    temp = givenNode;
    while (size > 1)
    {
        for (int i = 0; i < key - 1; i++)
            temp = temp->next;
        temp = temp->next;
        removeNode(temp->prev);
    }
}

int main()

    {int elemCount , i=1 , j=0 , key , firstnode;
    c_list circularlist;
    float data;

    cout << "how many elements do you want to add?\n";
    cin >> elemCount;
    node* array = new node[elemCount];



    system("cls");

    cout << "What is the key you want to use?\n";
    cin >> key;

    system("cls");

    cout << "What about the first node (1 being first) ?\n";
    cin >> firstnode;
    firstnode--;

    system("cls");


    while (i < elemCount+1)
        {node* temp = new node;
        *temp = i;
        array[j] = temp;
        circularlist.insert(&array[j]);
        i++;
        j++;}



    while (1)
    {system("cls");
    cout<<"What would you like to do from here?\n"
        <<"(from here on, indexes start from 1)\n\n"
        <<"1. Insert an element\n"
        <<"2. Show some details about the list\n"
        <<"3. Print the list\n"
        <<"4. List 3rd element from given element\n"
        <<"5. Remove a node\n"
        <<"6. Run the josephus problem\n"
        <<"7. Change the key\n"
        <<"8. Change the first node\n"
        <<"-----------------------------------------\n"
        <<"Input:";
    int choice;
    cin>>choice;

    switch(choice){

    case 1:
    {
        system("cls");
        int insertion;
        node* temporary;
        temporary = new node;
        cin>> insertion;
        *temporary = insertion;
        circularlist.insert(temporary);
        break;
    }
    case 2:
    {
        system("cls");
        circularlist.show();
        getch();
        break;
    }
    case 3:
    {
        system("cls");
        circularlist.print();
        getch();
        break;
    }
    case 4:
    {
        system("cls");
        circularlist.print();
        int index;
        cout<<"\nafter which index would you like to see 3rd element?\n";
        cin>>index;
        circularlist.list_3rd(circularlist.getNode(index-1));
        getch();
        break;
    }
    case 5:
    {
        int where;
        system("cls");
        circularlist.print();
        cout<<"\nWhich index would you like to remove?\n";
        cin>>where;
        circularlist.removeNode(circularlist.getNode(where-1));
        break;
    }
    case 6:
    {
        system("cls");
        cout << "The elements in the array are:\n";
        circularlist.print();
        circularlist.josephusProblem(key,circularlist.getNode(firstnode));
        cout << "\nAnd the last element left after it being processed is:\n";
        circularlist.print();
        cout << "\n\n\n";
        getch();
        break;
    }
    case 7:
    {
     system("cls");
     cout<<"Input the new key:\n";
     cin>>key;
     break;
    }
    case 8:
    {
     system("cls");
     cout<<"Input the new first node:\n";
     cin>>firstnode;
     firstnode--;
     break;
    }

    }
}






    /*circularlist.insert
    * show
    * print
    * list_3rd
    * removeNode
    * josephusproblem
    * getNode
    */

}
