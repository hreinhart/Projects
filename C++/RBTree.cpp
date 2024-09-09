#include <bits/stdc++.h>
using namespace std;

enum color{
    red,
    black
};

template<typename keytype, typename valuetype> class Node{
    public:
    keytype *k;
    valuetype *v;
    Node *left, *right, *parent;
    color col;
    int size;
    Node(){
        k = new keytype;
        v = new valuetype;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        size = 0;
        col = red;
    }
    Node(keytype key, valuetype val){
        k =  new keytype(key); *k = key;
        v = new valuetype(val); *v = val;
        col = red;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        size = 1;
    }
    Node(color c){
        k = nullptr;
        v = nullptr;
        left = nullptr;
        right = nullptr;
        parent = nullptr;
        col = black;
        size = 0;
    }
    ~Node(){
        if(k != nullptr){
            delete k;}
        if(v != nullptr){
            delete v;}

    }
    void decon(Node *TNULL){
        if(this == TNULL){
            return;
        }
        if(left != TNULL && left != nullptr){
            left->decon(TNULL);
        }
        if(right != TNULL && right != nullptr){
            right->decon(TNULL);
        }
        delete this;
    }
    Node( keytype key, valuetype val, color c,int s, Node<keytype, valuetype> *p){
        k = new keytype(key);
        v = new valuetype(val);
        left = nullptr;
        right = nullptr;
        parent = p;
        col = c;
        size = s;
    }
    Node& operator=(Node src){
        if (this == src){
            return *this;
        }
        delete k; k = new keytype(src.k);
        delete v; v = new keytype(src.v);
        col = src.col;
        return *this;
    }
    Node(const Node<keytype,valuetype> &src){
        *k = *src.k;
        *v = *src.v;
        left = src.left;
        right = src.left;
        parent = src.parent;
        col = src.col;
        size = src.size;
    }
    void pre(){
        if(k == nullptr){
            return;
        }
        cout << *k;
        if(left->k != nullptr){
            cout << " ";
            left->pre();
        }
        if(right->k != nullptr){
            cout << " ";
            right->pre();
        }
    }
    void in(){
        if(k == nullptr){
            return;
        }
        if(left->k != nullptr){
            left->in();
            cout << " ";
        }
        cout << *k;
        if(right->k != nullptr){
            cout << " ";
            right->in();
        }
    }
    void post(){
        if(k == nullptr){
            return;
        }
        if(left->k != nullptr){
            left->post();
            cout << " ";
        }
        if(left->k != nullptr){
            right->post();
            cout << " ";
        }
        cout << *k;
    }
    void printk(int &key){
        if(left->k != nullptr){
            left->printk(key);
            if(key > 0){
                cout << " ";
            }
        }
        if(key < 1){
            return;
        }
        cout << *k;
        key--;
        if(key < 1){
            return;
        }
        if(right->k != nullptr){
            cout << " ";
            right->printk(key);
        }
        
    }
    Node<keytype, valuetype> *sNode (keytype key){
        //cout << endl << "Motherfucker" << endl;
        if(key == (*k)){
          //  cout << endl << "shouldn't happen" << endl;
            return this;
        }
        else if(key < (*k) && left->k != nullptr){//cout << endl << "left" << endl;
            return left->sNode(key);
            
        }
        else if(key > (*k) && right->k != nullptr){//cout << endl << "right" << endl;
            return right->sNode(key);
        }
        else{
            //cout << endl << "Fucking hello?" << endl;
            return nullptr;
        }
    }
    valuetype *sVal(keytype key){
        if(key == *k){
            return v;
        }
        else if(key < *k && left != nullptr){
            return left->sVal(key);
        }
        else if(key > *k && right != nullptr){
            return right->sVal(key);
        }
        else{
            return nullptr;
        }
    }
    Node<keytype, valuetype> *pred(){
        if(left == nullptr){
            return nullptr;
        }
        Node *cur;
        for(cur = left; cur->left != nullptr; cur = cur->left){continue;}
        return cur;
    }
    Node<keytype, valuetype> *min(){
        if(k == nullptr){
            return this;
        }
        Node *cur;
        for(cur = left; cur->left != nullptr; cur = cur->left){continue;
        }
        return cur;
    }
    keytype select(int k1){
        if(k1 == left->size+1){
            return(*k);
        }
        else if(k1 <= left->size){
            return left->select(k1);
        }
        else{
            return right->select(k1 - left->size -1);
        }
    }
};

 template <typename keytype, typename valuetype> class RBTree {
    Node<keytype, valuetype> *root, *TNULL;

    void copy(Node<keytype, valuetype> *TNcop, Node<keytype, valuetype> *Ncop, Node<keytype, valuetype> *&newN, Node<keytype, valuetype> *&newP){
        newN = new Node<keytype, valuetype>(*(Ncop->k), *(Ncop->v), Ncop->col, Ncop->size, newP);

        if(Ncop->left == TNcop || Ncop->left == nullptr){
            newN->left = TNULL;
        }
        else{
            copy(TNcop, Ncop->left, newN->left, newN);
        }
        if(Ncop->right == TNcop || Ncop->right == nullptr){
            newN->right = TNULL;
        }
        else{
            copy(TNcop, Ncop->right, newN->right, newN);
        }
    }
    Node<keytype, valuetype> *min(Node<keytype, valuetype> *n){
        for(n; n->left != TNULL; n = n->left){continue;}
        return n;
    }
    Node<keytype,valuetype> *max(Node<keytype,valuetype> *n){
        for(n; n->right != TNULL; n = n->right){continue;}
        return n;
    }
    void insertFix(Node<keytype,valuetype> *c){
        Node<keytype,valuetype> *b;

        while(c->parent->col == red){
            if(c->parent == c->parent->parent->left){
                b = c->parent->parent->right;

                if(b->col == red){
                    c->parent->col = black;
                    b->col = black;
                    c->parent->parent->col = red;
                    c = c->parent->parent;
                }
                else{
                    if(c == c->parent->right){
                        c = c->parent;
                        leftRot(c);
                    }
                    c->parent->col = black;
                    c->parent->parent->col = red;
                    rightRot(c->parent->parent);
                }
            }
            else{
                b = c->parent->parent->left;
                if(b->col == red){
                    c->parent->col = black;
                    b->col = black;
                    c->parent->parent->col = red;
                    c = c->parent->parent;
                }
                else{
                    if(c == c->parent->left){
                        c = c->parent;
                        rightRot(c->parent->parent);
                    }
                    c->parent->col = black;
                    c->parent->parent->col = red;
                    leftRot(c->parent->parent);
                }
            }
        }
        root->col = black;
    }
    void deleteFix(Node<keytype, valuetype> *a){
        Node<keytype, valuetype> *b;
        while(a != root && a->col == black){
            if(a == a->parent->left){
                b = a->parent->right;
                if(b->col == red){
                    b->col = black;
                    a->parent->col = red;
                    leftRot(a->parent);
                    b = a->parent->right;
                }
                if(b->left->col == black && b->right->col == black){
                    b->col = red;
                    a = a->parent;
                }
                else{
                    if(b->right->col == black){
                        b->left->col = black;
                        b->col = red;
                        rightRot(b);
                        b = a->parent->right;
                    }
                    b->col = a->parent->col;
                    a->parent->col = black;
                    b->right->col = black;
                    leftRot(a->parent);
                    a = root;
                }
            }
            else{
                b = a->parent->left;
                if(b->col == red){
                    b->col = black;
                    a->parent->col = red;
                    rightRot(a->parent);
                    b = a->parent->left;
                }
                if(b->right->col == black && b->left->col == black){
                    b->col = red;
                    a = a->parent;
                }
                else{
                    if(b->left->col == black){
                        b->right->col =  black;
                        b->col = red;
                        leftRot(b);
                        b = a->parent->left;
                    }
                

                b->col = a->parent->col;
                a->parent->col = black;
                b->left->col = black;
                rightRot(a->parent);
                a = root;
                }
            }
        }
    }
    void rightRot(Node<keytype, valuetype> *a){
        Node<keytype, valuetype> *b = a->left;
        a->left = b->right;
        if(b->right != TNULL){
            b->right->parent = a;
        }
        b->parent = a->parent;
        if(a->parent == TNULL){
            root = b;
        }
        else if(a == a->parent->right){
            a->parent->right = b;
        }
        else{
            a->parent->left = b;
        }
        b->right = a;
        a->parent = b;
        b->size = a->size;
        a->size = a->left->size + a->right->size +1;
    }
    void leftRot(Node<keytype, valuetype> *a){
        Node<keytype, valuetype> *b = a->right;
        a->right = b->left;
        if(b->left!= TNULL){
            b->left->parent = a;
        }
        b->parent = a->parent;
        if(a->parent == TNULL){
            root = b;
        }
        else if(a == a->parent->left){
            a->parent->left = b;
        }
        else{
            a->parent->right = b;
        }
        b->left = a;
        a->parent = b;
        b->size = a->size;
        a->size = a->left->size + a->right->size +1;
    }
    void transplant(Node<keytype, valuetype> *u1, Node<keytype, valuetype> *v1){
        if(u1->parent == TNULL){
            root = v1;
        }
        else if(u1 == u1->parent->left){
            u1->parent->left = v1;
        }
        else{
            u1->parent->right = v1;
        }
        v1->parent = u1->parent;
    }
    public:
    RBTree(){
        TNULL = new Node<keytype, valuetype>(black);
        root = TNULL;
    }
    RBTree(keytype k, valuetype v){
        TNULL = new Node<keytype,valuetype>(black);
        root = new Node<keytype,valuetype>(k,v);
        root->col = black;
    }
    RBTree(keytype *k, valuetype *v, int s){
        TNULL = new Node<keytype,valuetype>(black);
        root = TNULL;
        for(int i = 0; i < s; i++){
            insert(k[i],v[i]);
        }

    }
    RBTree(const RBTree<keytype, valuetype> &src){
        TNULL = new Node<keytype,valuetype>(black);
        root = TNULL;
        copy(src.TNULL,root,TNULL);
    }
    ~RBTree(){
        root->decon(TNULL);
    }
    RBTree<keytype, valuetype> &operator=(const RBTree<keytype,valuetype> &src){
        if(this == &src){
            return *this;
        }

        root->decon(TNULL);
        TNULL = new Node<keytype,valuetype>(black);
        root = TNULL;
        copy(*&src.TNULL, *&src.root, root, TNULL);
        return *this;
    }

    void preorder(){
        root->pre();
        cout << endl;
    }
    void inorder(){
        root->in();
        cout << endl;
    }
    void postorder(){
        root->post();
        cout << endl;
    }
    void printk(int k){
        root->printk(k);
        cout << endl;
    }
    int size(){
        return root->size;
    }
    valuetype *search(keytype k){
        return root->sVal(k);
    }
    void insert(keytype k, valuetype v){
        Node<keytype, valuetype> *c = new Node<keytype,valuetype>(k,v);
        c->size = 1;
        c->left = TNULL;
        c->right = TNULL;
        Node<keytype, valuetype> *b = TNULL;
        Node<keytype, valuetype> *a = root;

        while(a != TNULL){
            (a->size)++;

            b = a;

            if (*(c->k) < *(a->k)){
                a = a->left;
            }
            else{
                a = a->right;
            }
        }

        c->parent = b;
        if(b == TNULL){
            root = c;
        }
        else if(*(c->k) < *(b->k)){
            b->left = c;
        }
        else{
            b->right = c;
        }

        c->left = TNULL;
        c->right = TNULL;
        insertFix(c);
    }
    int remove(keytype k){
        // cout << endl << " fuk " << endl;
        Node<keytype, valuetype> *c = root->sNode(k);
        // cout << endl << " Safe " << endl;
        if (c == nullptr){
            return 0;
        }
        Node<keytype, valuetype> *b = c;
        Node<keytype, valuetype> *a;

        for(Node<keytype, valuetype> *i = c->parent; i != TNULL; i = i->parent){
            i->size--;
        }

        color origcol = b->col;
        if(c->left == TNULL){
            a = c->right;
            // cout << endl << "Ya " << endl;
            transplant(c, c->right);
            // cout << endl << "507+" << endl;
        }
        else if(c->right == TNULL){
            a = c->left;
            // cout << endl << "AHHHHHH" << endl;
            transplant(c, c->left);
            // cout << endl << "512+ " << endl;
        }
        else{
            b = max(c->left);
            // cout << endl << "514+" << endl;
            origcol = b->col;
            a = b->left;
            if(b->parent == c){
                a->parent = b;
            }
            else{
                transplant(b, b->left);
                b->left = c->left;
                b->left->parent = b;
                for(Node<keytype, valuetype> *i = a->parent; i != TNULL && i != b; i = i->parent){
                    i->size--;
                }
            }
            transplant(c,b);
            // cout << "help";
            b->right = c->right;
            b->right->parent = b;
            b->col = c->col;
            b->size = b->left->size + b->right->size+1;
        }
        if(origcol == black){
            deleteFix(a);
        }
        
        return 1;
    }
    int rank(keytype k){
        Node<keytype, valuetype> *n = root->sNode(k);
        if(n == nullptr){
            return 0;
        }
        int rank = n->left->size+1;
        for(Node<keytype,valuetype> *cur = n; cur != root; cur = cur->parent){
            if(cur == cur->parent->right){
                rank += cur->parent->left->size+1;
            }
        }
        return rank;
    }

    keytype select(int key){
        return root->select(key);
    }

    keytype *successor(keytype key){
        Node<keytype,valuetype> *cur = root->sNode(key);
        if(cur == nullptr){
            return nullptr;
        }
        if(cur->right != TNULL){
            for(cur = cur->right; cur->left != TNULL; cur = cur->left){
                continue;
            }
            return cur->k;
        }
        else{
            Node<keytype, valuetype> *sec;
            for(sec = cur->parent; sec != TNULL && cur == sec->right; sec = sec->parent){
                cur == sec;
            }
            return sec->k;
        }
    }
    keytype *predecessor(keytype key){
        Node<keytype, valuetype> *cur = root->sNode(key);
        if(cur == nullptr){
            return nullptr;
        }
        if(cur->left != TNULL){
            for(cur = cur->left; cur->right != TNULL; cur = cur->right){
                continue;
            }
            return cur->k;
        }
        else{
            Node<keytype, valuetype> *sec;
            for(sec = cur->parent; cur!= TNULL && cur == sec->left; sec = sec->parent){
                cur = sec;
            }
            return sec->k;
        }
    }
 };