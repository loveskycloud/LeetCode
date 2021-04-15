#include <iostream>
#include <memory>
namespace haizei {
template<typename T>
    struct BSNode {
        BSNode(const T &data) : data(data), lchild(nullptr), rchild(nullptr) {}
        T data;
        std::shared_ptr<BSNode> lchild, rchild; 
    };

template<typename T>
    struct BSTree {
        BSTree() : root(T()) {}


    private:
        BSNode<T> root;
    };


}



int main()
{
    

    return 0;
}

