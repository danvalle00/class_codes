#include <iostream>


int main()
{
    int my_array[5] = {10, 20, 30, 40, 50};
    int * ptr;
    ptr = my_array;
    std::cout << "ptr: " << ptr << std::endl;
    ptr++;
    std::cout<< "ptr++: " << ptr << std::endl;
    std:: cout<< "conteudo de ptr++:" << *ptr << std::endl;
}