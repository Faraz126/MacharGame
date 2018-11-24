#include <iostream>
using namespace std;

template <class Type>
struct Node
{
    Type data;
    Node* next;
    Node* prev;
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
        Node<Type>* head= tail = 0;
        len = 0;
    }

    DLL(const DLL& list_given)
    {
        head = tail = 0;
        len = 0;
        Node<Type>* temp = list_given.head;
        while (temp != list_given.tail)
        {
            Append(temp->data);
            temp = temp->next;
        }
        Append(temp->data);

    }

    void Append(Type data)
    {
        if (len == 0)
        {
            head = tail = new Node<Type>;
            head->data = data;
            head->next= 0;
            head->prev = 0;
        }
        else
        {
            tail->next = new Node<Type>;
            tail->next->data = data;
            tail->next->prev = tail;
            tail->next->next = 0;
            tail = tail->next;
        }
        len++;

    }
    void Append(Type data, int index)
    {
        if((index<0) || (index > len))
        {
            cout<<"invalid index";
        }
        else
        {
            Node<Type>* c_node  = new Node<Type>;
            Node<Type>* temp  = new Node<Type>;
            c_node->data = data;
            temp =head;
            if(index==0)
            {

                c_node->next = head;
                head = c_node;
            }
            else
            {
                int iter = 0;
                while(iter!=index)
                {
                    temp = temp->next;
                    iter++;
                }
                c_node->prev = temp->prev;
                c_node->next = temp->next;

            }

            len++;
        }
    }
    Type Pop()
    {
        Type val;
        if (len == 0)
        {
            return -1;
        }
        val = tail->data;
        tail = tail->prev;
        if (tail != 0 && tail->next != 0)
        {
            delete tail->next;
            tail->next= 0;
        }


        len--;
        return val;

    }
    Type Pop(int index)
    {
        Type val;
        Node<Type>* c_node = head;

        if (index == 0)
        {
            if (head == tail)
            {
                tail = head->next;
            }
            head = head->next;
            if (head != 0)
            {
                head->prev = 0;
            }

            val = c_node->data;
            len--;
            delete c_node;
            return val;
        }

        else if (index == len-1)
        {
            return Pop();
        }

        int c_index = 0;
        while (c_index != index)
        {
            c_node = c_node->next;
            c_index++;
        }
        val = c_node->data;
        c_node->prev->next = c_node->next;
        c_node->next->prev = c_node->prev;
        delete c_node;

        return val;

    }
    void Show()
    {
        std::cout << "CURRENT LEN " << len << std::endl;
        if (len == 0)
        {
            return;
        }
        Node<Type>* c_node = head;
        while(c_node != 0)
        {
            std::cout << c_node->data << " ";
            c_node = c_node->next;
        }
        std::cout<< std::endl;
    }


};

