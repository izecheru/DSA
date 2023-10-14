#include <iostream>
using std::cout;
using std::cin;

class Stack
{
    int top;
    size_t capacity;
public:
    int* arr = nullptr;

    Stack()
    {
        top = -1;
        // we allocate blocks of 10s 
        capacity = 10;
        arr = (int*)malloc(sizeof(int)*capacity);
    }

    void clean();
    void push(int element);
    void pop();
    int head();
    bool isEmpty();
    int size();
    void printAllElements();
};

void Stack::clean()
{
    free(arr);
    capacity = 0;
    top = -1;
}

void Stack::printAllElements()
{
    if(size() == 0)
        return;

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
    if(size() == capacity)
    {
        capacity *= 2;
        arr = (int*)realloc(arr, sizeof(int) * capacity);
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
    --top;
}

int Stack::size()
{
    // since it is 0 at the first push
    return top + 1;
}