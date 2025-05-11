#include <iostream>
#include <vector>
#include <stdexcept>

// Custom exceptions inheriting from std::exception
class QueueOverflowException : public std::exception {};
class QueueUnderflowException : public std::exception {};

template <typename T>
class Queue {
private:
    std::vector<T> data;
    int front, rear, count, capacity;

public:
    Queue(int size) : data(size), front(0), rear(0), count(0), capacity(size) {}

    void enqueue(T value) {
        if (count == capacity) {
            throw QueueOverflowException();
        }
        data[rear] = value;
        rear = (rear + 1) % capacity;
        ++count;
    }

    T dequeue() {
        if (count == 0) {
            throw QueueUnderflowException();
        }
        T value = data[front];
        front = (front + 1) % capacity;
        --count;
        return value;
    }

    bool isEmpty() const {
        return count == 0;
    }

    bool isFull() const {
        return count == capacity;
    }
};

int main() {
    Queue<int> q(2);

    try {
        std::cout << "Attempting to enqueue to a full queue...\n";
        q.enqueue(1);
        q.enqueue(2);
        q.enqueue(3); // This should throw
    } catch (const QueueOverflowException& e) {
        std::cout << "Caught QueueOverflowException - what(): " << e.what() << '\n';
    }

    try {
        std::cout << "\nAttempting to dequeue from an empty queue...\n";
        q.dequeue();
        q.dequeue();
        q.dequeue(); // This should throw
    } catch (const QueueUnderflowException& e) {
        std::cout << "Caught QueueUnderflowException - what(): " << e.what() << '\n';
    }

    return 0;
}
