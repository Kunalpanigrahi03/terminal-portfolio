#include <iostream>
#include <memory>

template<typename T>
class Deque {
private:
    struct Node {
        T data;
        std::shared_ptr<Node> next;
        std::shared_ptr<Node> prev;

        Node(T value) : data(value), next(nullptr), prev(nullptr) {}
    };

    std::shared_ptr<Node> front;
    std::shared_ptr<Node> back;

public:
    Deque() : front(nullptr), back(nullptr) {}

    ~Deque() {
        clear();
    }

    void pushBack(const T& item) {
        auto newNode = std::make_shared<Node>(item);
        if (back) {
            back->next = newNode;
            newNode->prev = back;
        } else {
            front = newNode; // If deque is empty, new node is also the front
        }
        back = newNode;
    }

    void pushFront(const T& item) {
        auto newNode = std::make_shared<Node>(item);
        if (front) {
            front->prev = newNode;
            newNode->next = front;
        } else {
            back = newNode; // If deque is empty, new node is also the back
        }
        front = newNode;
    }

    std::shared_ptr<T> popBack() {
        if (isEmpty()) {
            return nullptr;
        }

        auto dataPtr = std::make_shared<T>(back->data);
        back = back->prev;

        if (back) {
            back->next = nullptr;
        } else {
            front = nullptr; // If deque is now empty
        }

        return dataPtr;
    }

    std::shared_ptr<T> popFront() {
        if (isEmpty()) {
            return nullptr;
        }

        auto dataPtr = std::make_shared<T>(front->data);
        front = front->next;

        if (front) {
            front->prev = nullptr;
        } else {
            back = nullptr; // If deque is now empty
        }

        return dataPtr;
    }

    std::shared_ptr<T> backValue() const {
        if (isEmpty()) {
            return nullptr;
        }
        return std::make_shared<T>(back->data);
    }

    std::shared_ptr<T> frontValue() const {
        if (isEmpty()) {
            return nullptr;
        }
        return std::make_shared<T>(front->data);
    }

    void clear() {
        front = nullptr;
        back = nullptr;
    }

    bool isEmpty() const {
        return front == nullptr;
    }

    int size() const {
        int count = 0;
        auto current = front;
        while (current) {
            count++;
            current = current->next;
        }
        return count;
    }
};

int main() {
    Deque<int> deque;
    deque.pushBack(1);
    deque.pushBack(2);
    deque.pushFront(0);

    std::cout << "Front: " << *deque.frontValue() << std::endl; // Output: 0
    std::cout << "Back: " << *deque.backValue() << std::endl;   // Output: 2

    std::cout << "Popped from front: " << *deque.popFront() << std::endl; // Output: 0
    std::cout << "Popped from back: " << *deque.popBack() << std::endl;   // Output: 2

    std::cout << "Size after pops: " << deque.size() << std::endl; // Output: 1

    return 0;
}