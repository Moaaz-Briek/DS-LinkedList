#ifndef NODE_H
#define NODE_H


class Node
{
    public:
        int data;
        Node* next = NULL;
        Node* prev = NULL;
        Node(int data) {this->data = data;}

    protected:

    private:
};

#endif // NODE_H
