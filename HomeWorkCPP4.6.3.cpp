#include <iostream>
#include <locale>

template <class T> class Vector {
public:
    Vector(unsigned int capacity) {
        capacity_ = 2 * capacity;
        arr = new T[capacity_]{};
    }
    ~Vector() {
        delete[] arr;
        arr = nullptr;
        if (arr_new != nullptr) {
            delete[] arr_new;
            arr_new = nullptr;
        }
    }
    Vector(const Vector&) = delete;

    Vector& operator = (const Vector& other) {
        if (this != &other) {
            size_ = other.size_;
            capacity_ = other.capacity_;
            
            delete[] arr;
            arr = new T[capacity_]{};

            for (unsigned int i = 0; i < size_; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
    }
    
    T at(unsigned int index) {
        return arr[index];
    }

    void push_back(T value) {
        
        if (size_ == capacity_) {
            capacity_ = 2 * capacity_;
            arr_new = new T[capacity_];

            for (unsigned int i = 0; i < size_; i++) {
                arr_new[i] = arr[i];
            }

            delete[] arr;
            arr = arr_new;
            arr_new = nullptr;
        }

        arr[size_] = value;
        size_++;
    }

    void pop_back() {
        size_--;
        arr[size_] = 0;
        
        if (size_ == capacity_ / 3) {
            capacity_ = 2 * size_;
            arr_new = new T[capacity_]{};

            for (unsigned int i = 0; i < size_; i++) {
                arr_new[i] = arr[i];
            }

            delete[] arr;
            arr = arr_new;
            arr_new = nullptr;
        }
    }
    
    int size() {
        return size_;
    }

    int capacity() {
        return capacity_ + 1;
    }

private:
    T* arr = nullptr;
    T* arr_new = nullptr;
    unsigned int size_ = 0;
    unsigned int capacity_ = 1;
};

int main()
{
    setlocale(LC_ALL, "Russian");
    Vector<int> vec(2);
    Vector<int> vec2(1);
    vec.push_back(6);
    vec.push_back(3);
    vec.push_back(5);
    vec.push_back(1);
    vec2 = vec;
    vec2.pop_back();
    vec2.pop_back();
    vec2.pop_back();

    std::cout << "Массив 1: ";
    for (int i = 0; i < vec.size(); i++) {
        std::cout << vec.at(i) << " ";
    }
    std::cout << "\n" << "Максимальное количество элементов: " << vec.capacity() << std::endl;

    std::cout << "Массив 2: ";
    for (int i = 0; i < vec2.size(); i++) {
        std::cout << vec2.at(i) << " ";
    }
    std::cout << "\n" << "Максимальное количество элементов: " << vec2.capacity() << std::endl;
}