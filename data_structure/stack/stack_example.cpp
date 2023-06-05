#include <iostream>
#include <string>
#include <sstream>

class Stack
{
    // "Struct"
private:
    int stack_top;
    int size;
    float *stack;

    // "Methods"
public:
    Stack(int value)
    {
        stack = new float[value];
        std::cout << "Creating Stack, Size " << size << std::endl;
        stack_top = -1;
        size = value;
    }

    int push(float value)
    {
        if (stack_top >= size)
        {
            std::cerr << "Error: Stack Full" << std::endl;
            return 1;
        }
        stack++;
        stack[stack_top] = value;
        return 0;
    }

    int pop()
    {
        if (stack_top < 0)
        {
            std::cerr << "Error: Stack Empty" << std::endl;
            return 1;
        }
        stack_top--;
        return 0;
    }

    float top()
    {
        std::cout << "Value: " << stack[stack_top] << std::endl;
        return stack[stack_top];
    }

    void print()
    {
        for (int i; i < size; i++)
        {
            std::cout << i << " -> " << stack[i] << std::endl;
        }
    }
};

bool isOperator(std::string value)
{
    if (value == "+" || value == "-" || value == "/" || value == "*")
    {
        return true;
    }
    return false;
}

// Não entendi nada
/* bool isFloat(std::string value)
{
    std::isstringstream iss(value);
    float f;
    iss >> std::noskipws >> f;
    return iss.eof() && !iss.fail();
} */

int main()
{
    Stack my_stack(10);

    std::string input;
    float n1, n2, result;

    do
    {
        std::cout << "Input: ";
        std::getline(std::cin, input);
        bool valid = true;

        if (isOperator(input))
        {
            n1 = my_stack.top();
            my_stack.pop();
            n2 = my_stack.top();
            my_stack.pop();
        }
        else
        {
            if (isFloat(input))
            {
                // Que lógica feia
                my_stack.push(std::stof(input));

                if (input == "+")
                {
                    result = n1 + n2;
                }

                if (input == "-")
                {
                    result = n1 - n2;
                }

                if (input == "/")
                {
                    result = n1 / n2;
                }

                if (input == "*")
                {
                    result = n1 * n2;
                }

                std::cout << "Result: " << result << std::endl;
                my_stack.push(result);
            }
            else
            {
                std::cout << std::endl
                          << "Error, Invalid Input" << std::endl;
            }
        }
    } while (input != "!");
    return 0;
}