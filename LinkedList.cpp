#include <iostream>
using namespace std;
template<typename T>
class List {
public:
    List();
    List(const List<T>& other);
    ~List();
    void insert(T data, int index);
    void push_back(T data);         
    void push_front(T data);
    int getSize() { return size; }

    void print();
    void pop_front();
    void removeAt(int index);
    void pop_back();

    void reverseList();
    void clear();


    List<T>& operator = (const List<T>& other);
    T& operator [] (const int index);

private:

    template<typename T>
    class Node {
    public:
        T data;
        Node* next;
        Node(T data = T(), Node* next = nullptr)
        {
            this->data = data;
            this->next = next;
        }
    };
    int size;
    Node<T> *head;
};

template<typename T>
void List<T>::insert(T data, int index)
{
    if (index == 0) {
        push_front(data);
    }
    else {
        Node<T>* prev = this->head;

        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }
        Node<T>* newNode = new Node<T>(data, prev->next);
        prev->next = newNode;
        ++size;
    }
}
template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    }
    else {
        Node<T>* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = new Node<T>(data);
    }
    ++size;
}

template<typename T>
void List<T>::push_front(T data)
{
    head = new Node<T>(data, head);
    ++size;
}

template<typename T>
void List<T>::pop_front()
{
    if (!head) return;
    Node<T>* temp = head;
    head = head->next;
    delete temp;
    --size;
}

template<typename T>
void List<T>::removeAt(int index)
{
    if (index < 0 || index > size) return;
    if (index == 0) {
        pop_front();
    }
    else {
        Node<T>* prev = head;
        for (int i = 0; i < index - 1; ++i) {
            prev = prev->next;
        }
        Node<T>* del = prev->next;
        prev->next = del->next;
        delete del;
        --size;
    }
}

template<typename T>
void List<T>::pop_back()
{
    removeAt(size - 1);
}

template<typename T>
void List<T>::reverseList()
{
    if (!head || !head->next) {
        return;
    }
    Node<T>* current = head;
    Node<T>* prev = nullptr;
    Node<T>* next;
    while (current) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
}

template<typename T>
void List<T>::clear()
{
    while (size) {
        pop_front();
    }
}

template<typename T>
List<T>& List<T>::operator=(const List<T>& other)
{
    if (this == &other) return *this;
    clear();

    if (!other.head) return *this;
    Node<T> head = new Node<T>(other.head->data);
    Node<T>* current = head;
    Node<T>* otherCurrent = other.head->next;

    while (other.head) {
        current->next = new Node<T>(otherCurrent->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    size = other.size;
    return *this;

}

template<typename T>
T& List<T>::operator[](const int index)
{
    if (index < 0 || index > size) {
        throw out_of_range("Index out of range");
    }
    int counter = 0;
    Node<T>* current = head;
    while (current) {
        if (counter == index) {
            return current->data;
        }
        current = current->next;
        ++counter;
    }
}

template<typename T>
void List<T>::print() {
    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }
    Node<T>* current = head;
    while (current) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;

}
int main()
{
    // Create a list of integers
    List<int> myList;

    // Add elements to the list
    myList.push_back(10);  // Add to the end of the list
    myList.push_back(20);
    myList.push_back(30);
    myList.push_front(5);  // Add to the front of the list

    // Print the list
    cout << "Original List: ";
    myList.print();  // Output: 5 -> 10 -> 20 -> 30 -> NULL

    // Access an element using the [] operator
    cout << "Element at index 1: " << myList[1] << :endl;  // Output: 10

    // Insert an element at a specific position
    myList.insert(15, 2);  // Insert 15 at index 2

    // Print the modified list
    cout << "List after insertion: ";
    myList.print();  // Output: 5 -> 10 -> 15 -> 20 -> 30 -> NULL

    // Reverse the list
    myList.reverseList();
    cout << "Reversed List: ";
    myList.print();  // Output: 30 -> 20 -> 15 -> 10 -> 5 -> NULL

    // Remove element from the front
    myList.pop_front();
    cout << "List after pop_front: ";
    myList.print();  // Output: 20 -> 15 -> 10 -> 5 -> NULL

    // Remove element from the back
    myList.pop_back();
    cout << "List after pop_back: ";
    myList.print();  // Output: 20 -> 15 -> 10 -> NULL

    // Remove element at a specific index
    myList.removeAt(1);  // Remove element at index 1
    cout << "List after removeAt(1): ";
    myList.print();  // Output: 20 -> 10 -> NULL

    // Clear the list
    myList.clear();
    cout << "List after clear: ";
    myList.print();  // Output: List is empty
}

template<typename T>
List<T>::List()
{
    size = 0;
    head = nullptr;
}

template<typename T>
List<T>::List(const List<T>& other)
{
    size = 0;
    head = nullptr;

    clear();

    if (!other.head) return;

    head = new Node<T>(other.head->data);
    Node<T>* current = head;
    Node<T>* otherCurrent = other.head->next;

    while (otherCurrent) {
        current->next = new Node<T>(otherCurrent->data);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
    size = other.size;
    
}

template<typename T>
List<T>::~List()
{
    clear();
}


