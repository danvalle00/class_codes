#include <iostream>

class Stack
{
private:
    int *stack;
    int capacity;
    int stack_top;

    // Normalmente os métodos são listados como public e os elementos como privados.
public:
    // Construtor da classe:
    Stack(int size)
    {
        capacity = size;
        stack = new int[capacity];
        stack_top = -1; // Seta o topo da pilha como (vazia);
    }

    void push(int value)
    {
        if (stack_top == capacity)
        {
            std::cout << "Error: Stack Full";
        }
        else
        {
            stack_top++;
            stack[stack_top] = value;
        }
    }

    int pop()
    {
        if (stack_top == -1)
        {
            std::cout << "Stack Empty";
            return -1;
        }
        else
        {
            int element = stack[stack_top];
            stack_top--;
            return element;
        }
    }

    int top()
    {
        if (stack_top == -1)
        {
            std::cout << "Stack Empty";
            return -1;
        }
        else
        {
            return stack[stack_top];
        }
    }
};

int main()
{
    Stack my_stack(10);
    my_stack.push(4);
    my_stack.push(5);
    my_stack.push(6);
    my_stack.push(7);
    my_stack.push(8);
    my_stack.push(9);
    std::cout << my_stack.top() << std::endl;
    std::cout << "^ Top e em seguida o pop" << std::endl;
    std::cout << my_stack.pop() << std::endl;
    std::cout << my_stack.top() << std::endl;
    std::cout << my_stack.pop() << std::endl;
}
