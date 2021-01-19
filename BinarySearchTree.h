#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H
#include <cstdlib>
#include <iostream>
#include <string>
#include "BinaryNode.h"
#include "Filmes.h"
#include "Datas.h"
template <class T> class BinarySearchTree{
    private:
        BinaryNode<T>* m_root;
        BinaryNode<T>* insert(T x, BinaryNode<T>* t){
            if(t==NULL){
                t= new BinaryNode<T>(x,NULL,NULL);
            }
            else if(x < t->element){
                t->left = insert(x,t->left);
            }
            else if(x > t->element){
                t->right = insert(x,t->right);
            }
            return t;
        }

        BinaryNode<T>* clear(BinaryNode<T>* t){
            if(t==NULL){
                return t;
            }
            BinaryNode<T>* nodeToBeDeleted = t;
            clear(t->left);
            clear(t->right);
            t=NULL;
            delete nodeToBeDeleted;
            return t;
        }

        void printOrdem(BinaryNode<T>* t){
            if(t==NULL){
                return;
            }
            printOrdem(t->left);
            cout<<" "<<t->element;
            printOrdem(t->right);
        }

        void printPreOrdem(BinaryNode<T>* t){
            if(t==NULL){
                return;
            }
            cout<<" "<<t->element;
            printPreOrdem(t->left);
            printPreOrdem(t->right);
        }

        void printPosOrdem(BinaryNode<T>* t){
            if(t==NULL){
                return;
            }
            printPosOrdem(t->left);
            printPosOrdem(t->right);
            cout<<" "<<t->element;
        }

        BinaryNode<T>* find(T i, BinaryNode<T>* t){
            if(t==NULL){
                return NULL;
            }
            if(i < t->element){
                return find(i, t->left);
            }
            else if(i > t->element){
                return find(i, t->right);
            }
            else{
                return t;
            }
        }

        T findMin(BinaryNode<T>* t){
            if(t->left==NULL){
                return t->element;
            }
            return findMin(t->left);
        }

        T findMax(BinaryNode<T>* t){
            if(t->right==NULL){
                return t->element;
            }
            return findMax(t->right);
        }

        BinaryNode<T>* remove(T x, BinaryNode<T>* t){
            if(t==NULL){
                return t;
            }
            if(x < t->element){
                t->left = remove(x, t->left);
            }
            else if(x > t->element){
                t->right = remove(x, t->right);
            }
            else if(t->left!=NULL && t->right!=NULL) {// nó com dois filhos
                t->element = findMin(t->right);
                t->right = remove(t->element,t->right);
            }
            else {// nó com um ou nenhum filho
                BinaryNode<T>* nodeToBeDeleted = t;
                if(t->left!=NULL){
                    t=t->left;
                }
                else{
                    t=t->right;
                }
                delete nodeToBeDeleted;
            }
            return t;
        }
    public:
        BinarySearchTree(){
            m_root = NULL;
        }

        bool isEmpty(){
            return(m_root==NULL);
        }

        void clear(){
            if(isEmpty()){
                throw "Arvore Vazia!";
            }
            m_root=clear(m_root);
            cout<<"Arvore Limpa!"<<endl;
        }

        void insert(T x){
            m_root=insert(x,m_root);
        }

        bool find(T x){
            return find(x,m_root)!=NULL;
        }

        T findMin(){
            if(isEmpty()){
                throw "Arvore Vazia!";
            }
            return findMin(m_root);
        }

        T findMax(){
            if(isEmpty()){
                throw "Arvore Vazia!";
            }
            return findMax(m_root);
        }

        void remove(T x){
            if(!isEmpty()){
                m_root=remove(x,m_root);
            }            
        }

        void print(int percurso){
            if(!isEmpty()){
                switch(percurso){
                    case -1:
                        printPreOrdem(m_root);
                        break;
                    case 0:
                        printOrdem(m_root);
                        break;
                    case 1:
                        printPosOrdem(m_root);
                        break;
                    default:
                        cout<<"Opcao Invalida!"<<endl;
                        return;
                }
            }
        }

        ~BinarySearchTree(){
        }
};
#endif /* BINARYSEARCHTREE_H */

