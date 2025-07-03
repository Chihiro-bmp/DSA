#ifndef ARRAY_LIST_H
#define ARRAY_LIST_H

#include <iostream>

class ArrayList
{
private:
    int *data;
    int capacity;
    int size;

    void resize(int newCapacity)
    {

        int *new_data = new int[newCapacity];

        for (int i = 0; i < size; i++)
        {
            new_data[i] = data[i];
        }

        delete[] data;
        data = new_data;
        capacity = newCapacity;
    }

public:
    ArrayList()
    {

        capacity = 2;
        size = 0;
        data = new int[capacity];
    }

    ArrayList(const ArrayList &other) : size(other.size), capacity(other.capacity),
                                        data(new int[other.capacity])
    {
        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }
    }

    ~ArrayList()
    {

        delete[] data;
    }

    void append(int value)
    {

        if (size >= capacity / 2)
        {

            resize(capacity * 2);
        }

        data[size++] = value;
    }

    bool isAvailable(int value) const
    {

        for (int i = 0; i < size; i++)
        {
            if (data[i] == value)
                return true;
        }

        return false;
    }

    void remove(int value)
    {

        int index = -1;

        for (int i = 0; i < size; i++)
        {

            if (data[i] == value)
            {
                index = i;
                break;
            }
        }
        if (index == -1)
        {
            std::cout << "Not found" << std::endl;
            return;
        }

        for (int i = index; i < size - 1; i++)
        {
            data[i] = data[i + 1];
        }
        size--;

        if (size < capacity / 4 && capacity > 2)
        {
            resize(capacity / 2);
        }
    }

    void clear()
    {

          size=0;
          capacity=2;

          int* newData=new int[capacity];
          delete[] data;
          data=newData;
        
    }

    int getSize() const
    {
        return size;
    }

    int operator[](int index) const
    {
        return data[index];
    }

    ArrayList &operator=(const ArrayList &other)
    {

        if (this == &other)
            return *this;

        delete[] data;

        size = other.size;
        capacity = other.capacity;

        data = new int[capacity];

        for (int i = 0; i < size; i++)
        {
            data[i] = other.data[i];
        }

        return *this;
    }
};
#endif // ARRAY_LIST_H