#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "Node.h"

class LinkedList
{
    public:
        Node* head = NULL;
        Node* tail = NULL;
        LinkedList() {}

        void add(int data) {
            Node* newNode = new Node(data);
            if (head == NULL) {
                head = tail = newNode;
                return;
            }

            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }

        void insertAfter(int data, int flag) {

            Node* flagNode = getNode(flag);

            if (flagNode == NULL) {
                cout << "The flag is not found." << endl;
                return;
            }

            Node* newNode = new Node(data);

            if (flagNode == head && flagNode == tail) {
                newNode->prev = flagNode;
                flagNode->next = newNode;
                tail = newNode;
            } else if (flagNode == tail) {
                newNode->prev == flagNode;
                flagNode->next = newNode;
                tail = newNode;
            } else {
                Node* A = flagNode->next;
                A->prev = newNode;
                newNode->next = A;
                flagNode->next = newNode;
                newNode->prev = flagNode;
            }
        }

        void insertBefore(int data, int flag) {
            Node* flagNode = getNode(flag);

            if (flagNode == NULL) {
                cout << "The flag is not found." << endl;
                return;
            }

            Node* newNode = new Node(data);

            if (flagNode == head) {
                newNode->next = flagNode;
                flagNode->prev = newNode;
                head = newNode;
            } else {
                Node* A = flagNode->prev;
                newNode->prev = A;
                newNode->next = flagNode;
                flagNode->prev = newNode;
                A->next = newNode;
            }
        }

        int getCount() {
            Node* current = head;
            int Count = 0;
            while (current != NULL) {
                Count++;
                current = current->next;
            }
            return Count;
        }

        void getIndex(int index) {
            Node* current = head;
            int Count = 0;
            while (current != NULL) {
                if (Count == index) {
                    cout << current->data << endl;
                    return;
                }

                Count++;
                current = current->next;
            }
            cout << "Not Found Ya Basha";
            return;
        }

        void Remove(int data) {
            Node* node = getNode(data);

            if (node != NULL) {
                if (node == head) {
                    if (node == tail) {
                        head = tail = NULL;
                    }
                    head = node->next;
                    head->prev = NULL;
                } else if (node == tail) {
                    tail = node->prev;
                    tail->next = NULL;
                } else {
                    Node* prev = node->prev;
                    Node* next = node->next;

                    prev->next = next;
                    next->prev = prev;
                }
                delete(node);
            }
        }

        void display() {
            Node* currentNode = head;

            while (currentNode != NULL) {
                cout << currentNode->data << "\t";
                currentNode = currentNode->next;
            }
            cout << endl;
        }

    protected:

    private:
        Node* getNode(int data) {
            Node* currentNode = head;

            while (currentNode != NULL) {
                if (currentNode->data == data)
                    return currentNode;
                else
                    currentNode = currentNode->next;
            }
            return NULL;
        }
};

#endif // LINKEDLIST_H
