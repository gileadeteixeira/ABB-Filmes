#ifndef BINARYNODE_H
#define BINARYNODE_H
#include <cstdlib>
using namespace std;
template <class T> class BinaryNode{
public:
    T element;
    BinaryNode<T>* left;
    BinaryNode<T>* right;
    BinaryNode(T e, BinaryNode<T>* l, BinaryNode<T>* r){
        element = e;
        left = l;
        right = r;
    }
};
#endif /* BINARYNODE_H */

