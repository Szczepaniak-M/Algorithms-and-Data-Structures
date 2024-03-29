#include <iostream>
#include <fstream>

using namespace std;

class Node
{
private:
    int val;
    Node *left;
    Node *right;

public:
    Node(int value){
        left = nullptr;
        right = nullptr;
        val = value;
    }

    ~Node()
    {
        delete left;
        delete right;
    }

    void insert(int value) {
        if (value < val)
            if (left == nullptr)
                left = new Node(value);
            else
                left->insert(value);
        else
            if (right == nullptr)
                right = new Node(value);
            else
                right->insert(value);
    }

    Node* search(int x) {
        if (val == x)
            return this;
        else if (x < val)
            left->search(x);
        else if(x > val)
            right->search(x);
        else
            return nullptr;
    }

    void preorder() {
        cout << val << " ";
        if(left != nullptr)
            left->preorder();
        if(right != nullptr)
            right->preorder();
    }

    void inorder() {
        if(left != nullptr)
            left->inorder();
        cout << val << " ";
        if(right != nullptr)
            right->inorder();
    }

    void postorder() {
        if(left != nullptr)
            left->postorder();
        if(right != nullptr)
            right->postorder();
        cout << val << " ";
    }

    int height (){
        int MaxL =0 , MaxR = 0;
        if(left != nullptr)
            MaxL = left->height();
        if(right != nullptr)
            MaxR = right->height();
        if (MaxL > MaxR)
            return MaxL + 1;
        else
            return MaxR + 1;
    }

    int max()
    {
        if(right != nullptr)
            return right->max();
        else
            return val;
    }

    int getValue() {
        return val;
    }

};

int main() {
    ifstream in;
    int x;
    Node *tree = nullptr;
    in.open("data.txt");
    while (in >> x)
        if (tree == nullptr)
            tree = new Node(x);
        else
            tree->insert(x);
    in.close();
    cout << "Height of BST: " << tree->height() << endl;
    cout << "The greatest element: " << tree->max() << endl;
    cout << "Preorder: ";
    tree->preorder();
    cout << endl << "Inorder: ";
    tree->inorder();
    cout << endl << "Postorder: ";
    tree->postorder();
    cout<< endl<<tree->search(17)->getValue();
    delete tree;
    return 0;
}
