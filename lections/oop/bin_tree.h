#pragma once


template <typename T>
class BinTree {
    struct Node{
        Node *left, *right, *parent;
        T data;
        Node(const T& X) : left(nullptr), right(nullptr), parent(nullptr), data(X) {}
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
public:
    BinTree() : root(nullptr), count(0) {}
    ~BinTree();
    void clear() {
        delete root;
        root = nullptr;
        count = 0;
    }
    void empty() {clear();}
    size_t size() const {return count;}
    size_t height() const {return root->height();}
    void insert(const T&);
    typename BinTree<T>::iterator find(const T& X) const;
    void erase(typename const BinTree<T>::iterator&);


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
void BinTree<T>::insert(const T& X) {
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
typename BinTree<T>::iterator BinTree<T>::find(const T& X) const {
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
void BinTree<T>::erase(typename const BinTree<T>::iterator& pos) {
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