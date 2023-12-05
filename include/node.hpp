#ifndef NODE_HEADER
#define NODE_HEADER
#include <iostream>

class Node{
    public:
        Node();
        Node(unsigned long int a00, unsigned long int a01, unsigned long int a10, unsigned long int a11);
        ~Node();
        void print();
       unsigned long int (*getMatrix())[2];
    private:
       unsigned long int _matrix[2][2] = {0};

};

#endif