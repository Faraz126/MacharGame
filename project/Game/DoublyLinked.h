#pragma once
#include <iostream>


using namespace std;

template <typename Type>
struct Node
{
    Type data;
    Node<Type>* next;

};

template <class Type>
class DLL
{

    Node<Type>* head;
    Node<Type>* tail;
    int len;

public:

    DLL()
    {
        head = tail = NULL;
        len = 0;

    }


    /// TO WRITE DESTRUCTORRRRRRRRRRRRRRRRRR

    DLL(const DLL& list_given)
    {
        head = tail = NULL;
        len = 0;
        Node<Type>* temp = list_given.head;
        while (temp != list_given.tail)
        {
            Append(temp->data);
            temp = temp->next;
        }
        Append(temp->data);

    }
    void display()
    {
       Node<Type>* ptr;
       ptr = head;
       while (ptr != NULL)
        {
            cout<< ptr->data <<" ";
            ptr = ptr->next;
        }
    }

    void Append(Type data)
    {
        Node<Type>* temp = new Node<Type>;
        temp->data = data;
        temp->next = NULL;
        if(head == NULL)
        {
            head = tail = temp;
            tail->next = NULL;
        }
        else
        {
            tail->next = temp;
            tail = temp;
            tail->next = NULL;
        }
        len++;



    }

    Type Pop()
    {

        Type x = 0;
        if(head == NULL || len == 0)
        {
            cout<<"Queue khaali hai";
        }
        else
        {
            Node<Type>* temp = head;
            x = temp->data;
            head = head->next;
            delete(temp);
            return(x);
        }
        len--;
    }

     void RemoveItem(Type val)
    {
        if (len == 0)
        {
            cout<<"Can not pop. List is empty"<<endl;
        }

        if(head->data == val)
        {
            Node<Type>* c_node = head;
            if(head==tail)
            {
                head = head->next = NULL;
                tail = tail->next = NULL;
            }
            else
            {
                head = head->next;
            }
            delete c_node;
            len--;
            return;
        }
        Node<Type>*ptr = head;
        while (ptr != NULL)
        {
            if (val == ptr->next->data)
            {
                ptr->next = ptr->next->next;
                break;
            }

        ptr = ptr->next;
        }
        if (ptr != NULL)
        {
            delete ptr;
            len--;
        }


    }

    Type GiveItem(int index)
    {
        Type val = 0;
        Node<Type>* c_node = head;
        if (index<0 || index>=len)
        {
            cout<<"invalid index"<<endl;
            return val;
        }

        if (len == 0)
        {
            cout<<"Can not pop. List is empty"<<endl;
            return val;
        }

        else
        {
            int i = 0;
            while (i!= index && c_node !=NULL )
            {
                c_node = c_node->next;
                i++;
            }
            if (c_node == 0)
            {
                return val;
            }
            val = c_node->data;
        }
        delete c_node;
        return val;



    }


    int GetLength()
    {
        return len;
    }

    bool IsEmpty()
    {
        return len == 0;
    }
};


