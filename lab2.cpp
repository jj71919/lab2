#include <iostream>
#include <algorithm>

template <typename T, size_t N>
class Stack {
private:
    T data[N];
    size_t current_size;
public:
    Stack() : current_size(0) {}

    void push(const T& item) {
        if (current_size < N)
            data[current_size++] = item;
        else
            std::cerr << "Stack overflow!" << std::endl;
    }

    size_t size() const {
        return current_size;
    }

    bool identical(const Stack<T, N>& other) const {
        if (current_size != other.size())
            return false;
        for (size_t i = 0; i < current_size; ++i) {
            if (data[i] != other.data[i])
                return false;
        }
        return true;
    }

    template<typename U>
    friend void replace(Stack<U, N>& stack, const U& oldItem, const U& newItem);
};

template<typename T, size_t N>
void replace(Stack<T, N>& stack, const T& oldItem, const T& newItem) {
    std::replace(stack.data, stack.data + stack.current_size, oldItem, newItem);
}

// Main function
int main() {
    // Testing problem 1
    Stack<int, 5> intStack;
    intStack.push(1);
    intStack.push(2);
    std::cout << "Size of intStack: " << intStack.size() << std::endl;

    // Testing problem 2
    Stack<int, 5> stack1;
    stack1.push(1);
    stack1.push(2);

    Stack<int, 5> stack2;
    stack2.push(1);
    stack2.push(2);

    std::cout << "Are stack1 and stack2 identical? " << stack1.identical(stack2) << std::endl;

    // Testing problem 3
    Stack<char, 5> charStack;
    charStack.push('a');
    charStack.push('b');
    charStack.push('c');
    replace(charStack, 'b', 'x');

    return 0;
}
