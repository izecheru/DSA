#include <iostream>
using std::cout;
using std::cin;

class Stack
{
    int top;
public:
    int arr[100];

    Stack()
    {
        top = -1;
    }

    void push(int element);
    void pop();
    int head();
    bool isEmpty();
    int size();
    void printAllElements();
};

void Stack::printAllElements()
{
    for(int i = top; i >=0 ; i--)
    {
        cout << "arr[" << i << "]=" << arr[i] << "\n";
    }
}

bool Stack::isEmpty()
{
    if(size() == -1)
        return false;

    return true;
}

int Stack::head()
{
    return arr[top];
}

void Stack::push(int element)
{
    if(size() == 100)
    {
        cout << "stack is full";
        return;
    }

    arr[++top] = element;
}

void Stack::pop()
{
    if(top < 0)
    {
        cout << "stack is empty\n";
        return;
    }

    arr[top] = 0;
    top--;
}

int Stack::size()
{
    // since it is 0 at the first push
    int size = top + 1;
    return size;
}