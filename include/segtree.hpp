#ifndef SEGTREE_HEADER
#define SEGTREE_HEADER
#include "node.hpp"
#include <iostream>

class SegTree{
    public:
        SegTree(int qtd_instantes);
        ~SegTree();
        void build(int left, int right);
        Node query(int int_left, int int_right, int X, int left, int right);
        Node update(int instant, Node new_matrix, int X, int left, int right);
        void applyTransform(Node node, unsigned long long x, unsigned long long y);
        void printTree();
    private:
        Node* _nodes;
        int num_nodes;
        unsigned long long int MOD = 100000000;

        Node multiplication(Node node1, Node node2);
};

#endif