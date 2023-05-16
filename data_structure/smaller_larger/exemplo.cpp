#include <iostream>
#define SIZE_VECTOR 5


int main()
{
    int numbers[SIZE_VECTOR];
    std::string value;
    int * ptr;
    int larger, smaller;
    int med = 0;
    
    // Populating
    for (int i = 0; i < SIZE_VECTOR; i++)
    {
        std::cin >> value; 
        numbers[i] = stoi(value);
    }
    
    // Searching 
    smaller = numbers[0]; 
    for (int elements : numbers)
    {
        med += elements; 
        if (elements > larger)
        {
            larger = elements;
        }
        if (smaller > elements)
        {
            smaller = elements;
        }
    }
    
    std::cout << "larger: " << larger << std::endl;
    std::cout << "smaller: " << smaller << std::endl;
    std::cout << "med: " << (med / SIZE_VECTOR) << std::endl;
}