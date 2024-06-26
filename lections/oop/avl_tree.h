#pragma once


template <typename T>
class AVLTree {
    struct Node{
        Node *left, *right, *parent;
        T data;
        signed char balance;
        Node(const T& X) : left(nullptr), right(nullptr), parent(nullptr), data(X), balance(0) {}
        ~Node() {
            delete left;
            delete right;
        }
        sixe_t height() const {
            size_t L = (left == nullptr) ? 0 : left->height();
            size_t R = (right == nullptr) ? 0 : right->height();
            return (R < L) ? (L + 1) : (R + 1);
        }
        Node* minimum() {
            Node* now=this;
            while (now->left != nullptr) {
                now = now->left;
            }
            return now;
        }
        Node* next() const {
            if (right != nullptr) {
                return right->minimum();
            }
            Node* now = this;
            Node* p = parent;
            while (p != nullptr) {
                if (now == p->left) {
                    break;
                }
                now = p;
                p = now->parent;
            }
            return p;
        }
    };
    Node* prev() {
        if (left != nullptr) {
            return left->maximum();
        }
        Node* now = this;
        Node* p = parent;
        while (p != nullptr) {
            if (now == p->right) {
                break;
            }
            now = p;
            p = now->parent;
        }
        return p;
    }
    Node *root;
    size_t count;
    Node* rightRotate(Node*);
    Node* leftRotate(Node*);
    Node* doubleRightRotate(Node*);
    Node* doubleLeftRotate(Node*);
public:
    AVLTree() : root(nullptr), count(0) {}
    ~AVLTree();
    void clear() {
        delete root;
        root = nullptr;
        count = 0;
    }
    void empty() {clear();}
    size_t size() const {return count;}
    size_t height() const {return root->height();}
    void insert(const T&);
    typename AVLTree<T>::iterator find(const T& X) const;
    void erase(typename const AVLTree<T>::iterator&);


    class iterator {
        Node *current;
    public:
        iterator(Node *p=nullptr) : current(p) {
            const T& operator*() const {return current->data};
            bool operator==(const iterator& p) const {return current == p.current;}
            bool operator!=(const iterator& p) const {return current != p.current;}
            //prefix increment
            iterator& operator++() {
                if (current) {
                    current = current->next();
                } else {
                    throw "Iterator: out of bounds";
                }
                return *this;
            }
            iterator operator++(int) {
                Node* tmp = current;
                if (current) {
                    current = current->next();
                } else {
                    throw "Iterator: out of bounds";
                }
                return iterator(tmp);
            }
        }
    };
    iterator begin() const {
        if (root != nullptr) {
            return iterator(root->minimum())
        } else {
            return end();
        }
    }
    iterator end() const {return iterator(nullptr);}
};


template <typename T>
void AVLTree<T>::insert(const T& X) {
    ++count;
    if (root == nullptr) {
        root = new Node(X);
        return ;
    }
    Node *now = root;
    Node *p;
    do {
        p = now;
        if (X < now->data) {
            now = now->left;
        } else {
            now = now->right;
        }
    } while (now);
    now = new Node(X);
    now->parent = p;
    if (X < p->data) {
        p->left = now;
    } else {
        p->right = now;
    }
}


template <typename T>
typename AVLTree<T>::iterator AVLTree<T>::find(const T& X) const {
    Node* now = root;
    while (now) {
        if (X == now->daata) {
            break;
        }
        if (X < now->data) {
            now = now->left;
        } else {
            now = now->right;
        }
    }
    return iterator(now);
}

template <typename T>
void AVLTree<T>::erase(typename const AVLTree<T>::iterator& pos) {
    Node* toDelete = pos.current;
    if (toDelete == nullptr) {
        return ;
    }
    Node* alt;
    if (toDelete->right == nullptr) {
        alt = toDelete->left;
    } else if (toDelete->left == nullptr) {
        alt = toDelete->right;
    } else {
        alt = toDelete->right->minimum();
        if (alt->parent != toDelete) {
            alt->parent->left = alt->right;
            if (alt->right) {
                alt->right->parent = alt->parent;
            }
            alt->right = toDelete->right;
            toDelete->right->parent = alt;
        }
        alt->left = toDelete->left;
        toDelete->left->parent = alt;
    }
    if (toDelete -> parent==nullptr) {
        root = alt;
    } else {
        if (toDelete->parent->left == toDelete) {
            toDelete->parent->left = alt;
        } else {
            toDelete->parent->right = alt;
        }
    }
    if (alt != nullptr) {
        alt->parent = toDelete->parent;
    }
    toDelete->left == nullptr;
    toDelete->right == nullptr;
    delete toDelete;
    --count;
}


template <typename T>
void AVLTree<T>::balance() {}


template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::leftRotate(typename AVLTree<T>::Node* a) {
    if (a->balance != 2) {
        return a;
    }
    Node* b = a->right;
    if (b->balance == -1) {
        return a;
    }
    a->right = b->left;
    if (b->left) {
        b->left->parent = a;
    }
    b->parent = a->parent;
    if (a->parent) {
        if (a->parent->left == a) {
            a->parent->left = b;
        } else {
            a->parent->right = b;
        }
    } else {
        root = b;
    }
    b->left = a;
    a->parent = b;
    if (b->balance == 1) {
        a->balance = 0;
        b->balance = 0;
    } else {
        a->balance = 1;
        b->balance = -1;
    }
    return b;
}



template <typename T>
typename AVLTree<T>::Node* AVLTree<T>::rightRotate(typename AVLTree<T>::Node* b) {
    if (b->balance != 2) {
        return b;
    }
    Node* a = b->left;
    if (b->balance == -1) {
        return b;
    }
    b->left = a->right;
    if (a->right) {
        a->right->parent = b;
    }
    a->parent = b->parent;
    if (b->parent) {
        if (b->parent->left == b) {
            b->parent->left = a;
        } else {
            b->parent->right = a;
        }
    } else {
        root = a;
    }
    a->right = b;
    b->parent = a;
    if (a->balance == -1) {
        a->balance = 0;
        b->balance = 0;
    } else {
        a->balance = 1;
        b->balance = -1;
    }
    return b;
}


