#include <iostream>
#include "segtree.hpp"


using namespace std;
int main() {
    int qtd_tempos, qtd_operacoes, instant;
    char option;
    Node node;

    cin >> qtd_tempos >> qtd_operacoes;

    SegTree *segTree = new SegTree(qtd_tempos);

    for(int i = 0; i < qtd_operacoes; i++) {
        cin >> option;

        if (option == 'u') {
            cin >> instant;
            unsigned long int a00, a01, a10, a11;
            cin >> a00 >> a01;
            cin >> a10 >> a11;
            
            node = Node(a00, a01, a10, a11);
            segTree->update(instant, node, 1, 0, qtd_tempos - 1);
        } else if(option == 'q') {
            int interval_start, interval_end, x, y;
            cin >> interval_start >> interval_end >> x >> y;

            node = segTree->query(interval_start, interval_end, 1, 0, qtd_tempos - 1);
            segTree->applyTransform(node, x, y);
        } else {
            throw invalid_argument("Invalid Argument");
        }
    }
    // segTree->printTree();
    return 0;
}