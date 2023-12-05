#include "node.hpp"
using namespace std;

Node::Node() {
    for(int i = 0; i < 2; i++) {
        for(int j = 0; j < 2; j++) {
            if (j == i) {
                _matrix[i][j] = 1;
            }
        }
    }
}

Node::Node(unsigned long long int a00, unsigned long long int a01, unsigned long long int a10, unsigned long long int a11){
    _matrix[0][0] = a00;
    _matrix[0][1] = a01;
    _matrix[1][0] = a10;
    _matrix[1][1] = a11;
}

Node::~Node() {
}

unsigned long long int (*Node::getMatrix())[2] {
    return _matrix;
}

void Node::print() {
    cout << "[[" << _matrix[0][0] << " " << _matrix[0][1] <<  "], ";
    cout << "[" << _matrix[1][0] << " " << _matrix[1][1] <<  "]]" << endl;
}