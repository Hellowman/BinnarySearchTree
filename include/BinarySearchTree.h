#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include <iostream>
#include <cstddef>
#include <fstream>

template <typename T>
class BinarySearchTree {
public:
    /*void Testk(){
        root_.Test();
    }*/
    class Node;


    BinarySearchTree():root_(nullptr),size_(0){};
    BinarySearchTree(const std::initializer_list<T> & list):BinarySearchTree()
    {
        for (auto& value : list)
            insert(value);

    };

    auto size() const noexcept -> size_t{
        return size_;
    }
    auto insert(const T & value) noexcept -> bool
    {
        if (size_==0)
        {
            root_=new Node(value);
            size_=1;
            return true;
        }
        else
        {
            Node* cut_node=root_;
            Node* buf_node=nullptr;
            while (cut_node)
            {
                buf_node=cut_node;
                if (value==cut_node->value_) return false;
                else if (value < cut_node->value_) cut_node=cut_node->left_;
                else cut_node=cut_node->right_;
            }
            if (value < buf_node->value_) buf_node->left_=new Node(value);
            else buf_node->right_=new Node(value);
            size_++;
            return true;

        }
    }
    auto find(const T & value) const noexcept -> const T *
    {
        if (size_==0) return nullptr;
        Node* cut_node=root_;
        while (cut_node) {
            if (value == cut_node->value_)return &cut_node->value_;
            else if (value > cut_node->value_) cut_node = cut_node->right_;
            else cut_node = cut_node->left_;
        }return nullptr;
    }

    friend std::ostream& operator<<(std::ostream& os, const BinarySearchTree<T>& test)
    {
        if (test.size_) os << *test.root_;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, BinarySearchTree<T>& test)
    {
        T value;
        while (is >> value) test.insert(value);
        return is;
    }

    ~BinarySearchTree()
    {
        delete root_;
        size_=0;
    }
    class Node {
    public:
        Node(T value) : value_(value), left_(nullptr), right_(nullptr) {}
        T value_;
        Node * left_;
        Node * right_;
        friend std::ostream& operator<<(std::ostream& os, const Node& node)
        {

            if (node.left_) os << *node.left_;//доходим до самого левого значения
            os << node.value_ << ' ';//печатаем
            if (node.right_) os << *node.right_;//доходим до самого правого
            return os;
        }
        /*void Test(){
            Node* G=root_;
            while (G){
                if (G->left_) G=*G->left_;
                std::cout << &G->value_ << std::endl;
                if (G->right_) G=*G->rigth_;
            }
        }*/


        ~Node()
        {
             delete left_;
             delete right_;
        }
    };
private:
    Node * root_;
    size_t size_;


};

#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H
