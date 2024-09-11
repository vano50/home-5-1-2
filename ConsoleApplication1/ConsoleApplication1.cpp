#include <iostream>


class smart_array {
private:
    int* arr;
    unsigned int size;
    unsigned int capacity;

 

    void resize(unsigned int new_capacity) {
        int* new_arr = new int[new_capacity];
        for (unsigned int i = 0; i < size; ++i) {
            new_arr[i] = arr[i];
        }

        delete[] arr;
        arr = new_arr;
        capacity = new_capacity;
    }

public:
    
    smart_array(unsigned int initial_capacity) : size(0), capacity(initial_capacity) {
        if (initial_capacity == 0) { 
            throw std::invalid_argument("Initial capacity must be greater than zero."); 
        }
        arr = new int[capacity];
    }
    
    ~smart_array() {
        delete[] arr;
    }
    
    smart_array(const smart_array& other) : size(other.size), capacity(other.capacity) {
        arr = new int[capacity]; 
        for (unsigned int i = 0; i < size; ++i) { 
            arr[i] = other.arr[i];
        }
    }
    
    smart_array& operator=(const smart_array& other) {
        if (this != &other) { 
            delete[] arr; 
            size = other.size;
            capacity = other.capacity;
            arr = new int[capacity];
            for (unsigned int i = 0; i < size; ++i) {
                arr[i] = other.arr[i];

            }
        }
        return *this;
    }

    
    void add_element(int element) {
        if (size >= capacity) { 
            resize(capacity * 2); 
        }
        arr[size++] = element;
    }

    
    int get_element(unsigned int index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of bounds.");
        }
        return arr[index];
    }
};

int main() {
    try {
        smart_array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);

        smart_array new_array(2);
        new_array.add_element(56);
        new_array.add_element(44);

        
        arr = new_array;
        std::cout << "arr[0] = " << arr.get_element(0) << std::endl;
        std::cout << "arr[1] = " << arr.get_element(1) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << "Exception: " << ex.what() << std::endl;
    }
    return 0;
}