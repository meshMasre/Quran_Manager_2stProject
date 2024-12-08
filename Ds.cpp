#include <iostream>
#include <string>
#include <fstream>
using namespace std;
#pragma once

template <typename T>
struct node // The initialize of the node struct
{
    T Data;
    node *next; // Creating pointer to (The next node in the list)
    node *prev; // Creating pointer to (The prev node in the list)
    node() : Data(), next(nullptr), prev(nullptr) {};
    node(const T &Element) : Data(Element), next(nullptr), prev(nullptr) {};
};

template <typename T>
class DLL // Creating a class for double linked list
{
private:
    node<T> *Head; // Points to first node
    node<T> *Tail; // Points to last node
    unsigned int Capacity = 0;
    // Helper functions
    bool IsEmpty() { return (Head == nullptr); } // Check the list is empty

public:
    // Constructor
    DLL() : Head(nullptr), Tail(nullptr) {};
    // Destructor
    ~DLL()
    {
        node<T> *Current;
        node<T> *NToD = Head;
        while (NToD != nullptr)
        {
            Current = NToD->next;
            delete NToD;
            NToD = Current;
        }
    }
    // 1.Insert at begin
    void InsertBegin(const T &Element)
    {
        node<T> *newNode = new node<T>(Element);
        if (IsEmpty()) // Checks if the list is empty
        {
            Head = newNode;
            Tail = newNode;
        }
        else
        {
            newNode->next = Head;
            Head->prev = newNode;
            Head = newNode;
        }
        Capacity++;
    }
    // 2.Insert at end
    void InsertEnd(const T &Element)
    {
        if (IsEmpty())
            InsertBegin(Element);
        else
        {
            node<T> *newNode = new node<T>(Element);
            newNode->prev = Tail;
            Tail->next = newNode;
            Tail = newNode;
            Capacity++;
        }
    }
    // 3.Insert at index
    void InsertIndex(const T &Element, int Index)
    {
        if (Index < 1)
        {
            cout << "Invalid index!!\n";
            return;
        }
        if (Index == 1)
        {
            InsertBegin(Element);
            return;
        }
        node<T> *Current = Head;
        for (int i = 1; Current != nullptr && i < Index - 1; i++)
        {
            Current = Current->next;
        }
        if (Current == nullptr)
        {
            cout << "Index out of range!!\n";
            return;
        }
        if (Current->next == nullptr)
        {
            InsertEnd(Element);
            return;
        }
        node<T> *newNode = new node<T>(Element);
        newNode->next = Current->next;
        newNode->prev = Current;
        Current->next->prev = newNode;
        Current->next = newNode;
        Capacity++;
    }
    // 4.Delete at begin
    void DeleteBegin()
    {
        if (IsEmpty())
        {
            cout << "The list is already empty!!\n";
            return;
        }
        if (Head->next == nullptr) // Checks if there is only one node
        {
            delete Head;
            Head = Tail = nullptr;
        }
        else
        {
            node<T> *Temp = Head;
            Head = Head->next;
            Head->prev = nullptr;
            delete Temp;
        }
        Capacity--;
    }
    // 5.Delte at end
    void DeleteEnd()
    {
        if (IsEmpty())
        {
            cout << "The list is already empty!!\n";
            return;
        }
        if (Head->next == nullptr)
        {
            delete Head;
            Head = Tail = nullptr;
        }
        else
        {
            node<T> *NToD = Tail;
            Tail = Tail->prev;
            Tail->next = nullptr;
            delete NToD;
        }
        Capacity--;
    }
    // 5.Display nodes data
    void Display()
    {
        if (Head == nullptr)
            cout << "There is no data in the list!!\n";
        else
        {
            node<T> *Current = Head;
            while (Current != nullptr)
            {
                cout << Current->Data << endl;
                Current = Current->next;
            }
        }
    }
    // 6.Get the data of first node
    T GetHead()
    {
        if (IsEmpty())
        {
            cout << "There is no data in the list!!\n";
            return;
        }
        return Head->Data;
    }
    // 7.Get data of last node
    T GetTail()
    {
        if (IsEmpty())
        {
            cout << "There is no data in the list!!\n";
            return;
        }
        return Tail->Data;
    }
    // 8.Get data of index node
    T GetData(int Index)
    {
        if (IsEmpty()) // Checks if the list is empty
        {
            cout << "There is no data in the list!!\n";
            return T();
        }
        if (Index < 1) // Checks if index is out of range
        {
            cout << "Invalid index!!\n";
            return T();
        }
        node<T> *Current = Head;
        for (int i = 1; Current != nullptr && i < Index; i++)
        {
            Current = Current->next;
        }
        if (Current == nullptr) // Checks if index is out of range
        {
            cout << "Index out of range!!\n";
            return T();
        }
        return Current->Data;
    }
    // 9.Get number of nodes
    int GetCapacity() { return Capacity; }
    // 10.Get 

};