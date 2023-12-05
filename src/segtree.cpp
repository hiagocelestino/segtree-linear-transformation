#include "segtree.hpp"
using namespace std;

SegTree::SegTree(int num_instantes) {
    num_nodes = 4*num_instantes;
    _nodes = new Node[num_nodes];
    build(0, num_instantes - 1);
}

SegTree::~SegTree() {
   delete[] _nodes;
}

Node SegTree::build(int left, int right) {
    if (left == right) return  _nodes[left] = Node();

    int median = (left + right) / 2;

    build(left, median);
    build(median+1, right);
}

Node SegTree::update(int instant, Node new_matrix, int p, int left, int right) {
    if (instant < left || right < instant) {
        return _nodes[p - 1];
    }

    if (left == right) {
        return _nodes[p - 1] = new_matrix;
    }

    int median = (left + right) / 2;

    Node node_left = update(instant, new_matrix, 2*p, left, median);
    Node node_right = update(instant, new_matrix, 2*p+1, median+1, right);
    return _nodes[p - 1] = multiplication(node_left, node_right);
}

Node SegTree::multiplication(Node node1, Node node2) {
    // [[a1(00) b1(01)], [c1(10) d1(11)]] x [[a2(00) b2(01)], [c2(10) d2(11)]]
    // [[a1a2+b1c2  a1b2+b1d2], [c1a2+d1c2 c1b2+d1d2]]
    unsigned long int a00 = (node1.getMatrix()[0][0] * node2.getMatrix()[0][0]) % MOD + (node1.getMatrix()[0][1]*node2.getMatrix()[1][0]) % MOD;
    unsigned long int a01 = (node1.getMatrix()[0][0] * node2.getMatrix()[0][1]) % MOD + (node1.getMatrix()[0][1]*node2.getMatrix()[1][1]) % MOD;
    unsigned long int a10 = (node1.getMatrix()[1][0] * node2.getMatrix()[0][0]) % MOD + (node1.getMatrix()[1][1]*node2.getMatrix()[1][0]) % MOD;
    unsigned long int a11 = (node1.getMatrix()[1][0] * node2.getMatrix()[0][1]) % MOD + (node1.getMatrix()[1][1]*node2.getMatrix()[1][1]) % MOD;

    return Node(a00, a01, a10, a11);
}

Node SegTree::query(int int_left, int int_right, int p, int left, int right) {
    if (int_right < left or right < int_left) return Node();
    if (int_left <= left and right <= int_right ) return _nodes[p-1];
    int median = (left + right) / 2;

    Node node_left = query(int_left, int_right, 2*p, left, median);
    Node node_right = query(int_left, int_right, 2*p+1, median+1, right);

    return multiplication(node_left, node_right);
}

void SegTree::applyTransform(Node node, unsigned long long int x, unsigned long long int y) {
    // A = [[a(0,0) b(0,1)],[c(1,0) d(1,1)]]
    // b = [x y]
    // Axb = [a*x + y*b, cx + dy]
    unsigned long long int new_x = (node.getMatrix()[0][0] * x + node.getMatrix()[0][1] * y) % MOD;
    unsigned long long int new_y = (node.getMatrix()[1][0] * x + node.getMatrix()[1][1] * y) % MOD;

    cout << new_x << " " << new_y << endl;
}

void SegTree::printTree() {
    for(int i = 0; i < num_nodes; i++) {
        _nodes[i].print();
    }
}