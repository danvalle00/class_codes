#include <iostream>

class Queue
{
private:
    int front;
    int back;
    int size;
    int capacity;
    int *elements;

public:
    Queue(int mq_capacity)
    {
        this->capacity = mq_capacity;
        this->elements = new int[mq_capacity];
        this->size = 0;
        this->front = 0;
        this->back = -1;
    }

    ~Queue()
    {
        delete[] elements;
    }
    // Add an element
    int push(int value)
    {
        if (size >= capacity)
        {
            std::cerr << "Error, Queue Full";
            return -1;
        }
        back += 1;
        elements[back] = value;
        size++;
    }
    // Remove and returns the first element in queue
    int pop()
    {
        if (size <= 0)
        {
            std::cerr << "Error, Queue Empty";
            return -1;
        }
        int front_value = elements[front];
        front += 1;
        size--;
        return 0;
    }

    int value_front()
    {
        if (size <= 0)
        {
            std::cerr << "Error, Queue Empty";
            return -1;
        }
        return elements[front];
    }

    int queue_actual_size()
    {
        return size;
    }
};

int main()
{
    Queue my_queue(5);
}