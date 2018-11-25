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

    bool IsEmpty()
    {
        return len == 0;
    }
    DLL()
    {
        Node<Type>* head = tail = NULL;
        len = 0;
    }

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
        if(index >= 0 && index <= len )
        {
            if (index == 0)
            {
                if ( len == 0)
                {
                    head = tail = new Node<Type>;
                    head -> data = data ;
                }
                else
                {
                    head -> prev = new Node<Type> ;
                    head ->prev -> next = head ;
                    head = head -> prev ;
                    head -> data = data ;
                }
            }

            else if (index == len )
            {
                tail -> next = new Node<Type>;
                tail ->next -> prev = tail ;
                tail = tail -> next ;
                tail -> data = data ;
            }
            else
            {
                Node<Type>* temp ;
                if (index <= len /2)
                {
                    temp = head ;
                    for ( int j = 0; j < index; j ++)
                    {
                        temp =temp -> next ;
                    }
                }
                else
                {
                    temp = tail ;
                    for ( int j = 0; j < len -index -1; j ++)
                    {
                        temp = temp -> prev ;
                    }
                }

                Node<Type>* newNode = new Node<Type> ;
                newNode -> data = data ;
                newNode -> prev = temp -> prev ;
                newNode -> next = temp ;
                temp ->prev -> next = newNode ;
                temp -> prev = newNode ;

                }
            len ++;
        }

        else
        {
            cout << " Index is out of range " << endl ;
        }
    }

    Type Pop()
    {
        Type val;
        if (len == 0)
        {
            val = -1;
            cout<<"Can not pop. List is empty"<<endl;
            return val;
        }

        val = tail->data;
        if(head==tail)
        {
            Node<Type>* tem = head;
            head = head->next = head->prev = NULL;
            tail = tail->next = tail->prev = NULL;
            delete tem;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
        }
        len--;
        return val;
    }

    Type Pop(int index)
    {
        Type val;

        if (index<0 || index>=len)
        {
            cout<<"invalid index"<<endl;
            return -1;
        }

        if (len == 0)
        {
            cout<<"Can not pop. List is empty"<<endl;
            return -1;
        }

        if(index==len-1 && index!=0)
        {
            val = tail->data;
            tail = tail->prev;
            delete tail->next;
            tail->next = NULL;
            len--;
        }

        else if (index == 0)
        {
            Node<Type>* c_node = head;
            val = head->data;
            if(head==tail)
            {
                head = head->next = head->prev = NULL;
                tail = tail->next = tail->prev = NULL;
                delete c_node;
            }
            else
            {
                head = head->next;
                delete c_node;
            }
            len--;
        }

        else
        {
            Node<Type>* c_node = head;
            int i=0;
            while(i!=index)
            {
                c_node = c_node->next;
                i++;
            }
            val = c_node->data;
            c_node->prev->next = c_node->next;
            c_node->next->prev = c_node->prev;
            delete c_node;
            len--;
        }
        return val;
    }

    void Show()
    {
        std::cout << endl<<"CURRENT LEN " << len << std::endl;
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

