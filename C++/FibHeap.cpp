
#ifndef FIBHEAP
#define FIBHEAP

#include "CircularDynamicArray.cpp"
#include <cmath>
 
using namespace std;

template<typename KeyType>
class FibHeapNode{
    public:
    FibHeapNode<KeyType> *l, *r, *p, *ch, *ct;
    KeyType key;
    int rk;
    bool m;
    FibHeapNode(){
    rk = 0; p = nullptr;
    r = nullptr; l = nullptr;
    ch = nullptr; ct = nullptr;
    m = false;
    }
    FibHeapNode(KeyType k){
        key = k; rk = 0;
        l = this; r = this;
        p = nullptr; ch = nullptr;
        ct = nullptr; m = false;
    }
    
    ~FibHeapNode(){//nope
    }
    
    void actDestruct(FibHeapNode<KeyType> *a){
        if(ch != nullptr){
            ch->actDestruct(ch);
        }
        if(r != nullptr){
            r->actDestruct(this);
        }
        delete this;
    }
    void cutC(FibHeapNode<KeyType> *cutN){
        if(cutN->r == cutN){
            ch = nullptr;
            ct = nullptr;
        }
        else{
        cutN->l->r = cutN->r;
        cutN->r->l = cutN->l;
        if(ch == cutN){
            ch = cutN->r;
        }
        if(ct == cutN){
            ct = cutN->l;
        }
        }
        cutN->p = nullptr;
        rk--;
    }
    int getRank(){return rk;}
    void addC(FibHeapNode<KeyType> *newN){
        if(ch == nullptr){
            ch = newN;
            ct = newN;
        }
        else{
            ch->l = newN;
            ct->r = newN;
            newN->l = ct;
            newN->r = ch;
            ch = newN;
        }
        newN->p = this;
        rk++;
    }
};
template <typename KeyType>
class FibHeap{
    public:
    FibHeapNode<KeyType> *h, *t, *m;
    int size;

    FibHeap(){
    m = nullptr;
    h = nullptr;
    t = nullptr;
    size = 0;}
    FibHeap(KeyType *k, int s, CircularDynamicArray<FibHeapNode<KeyType>*> &in){
        m = nullptr;
        h = nullptr;
        t = nullptr;
        size = 0;
        for(int i = 0; i < s; i++){
            FibHeapNode<KeyType> *newN = new FibHeapNode<KeyType>(k[i]);
            insert(newN);
            in.addEnd(newN);
        }
        size = s;
        consolidate();
    }
    ~FibHeap(){actDestruct(h);}
    void actDestruct(FibHeapNode<KeyType> *n){
        if(n == nullptr){
            return;
        }
        FibHeapNode<KeyType> *n2 = n;
        do{
            if(n2->ch != nullptr){
                actDestruct(n2->ch);
            }
            FibHeapNode<KeyType> *ri = n2->r;
            delete n2;
            n2 = ri;
        } while(n2 != n);
    }

    void printKey(){
        if(h != nullptr){
            printRec(h);
        }
    }
    void printRec(FibHeapNode<KeyType> *a){
        FibHeapNode<KeyType> *tmp = a;
        do{
            if(tmp->p == nullptr){
                cout << "Rank " << tmp->rk << endl;
            }
            cout << tmp->key << " ";
            if(tmp->ch != nullptr){
                printRec(tmp->ch);
            }
            if(tmp->p == nullptr){
                cout << endl;
                if(tmp->r != a){
                    cout << endl;
                }
            }
            tmp = tmp->r;
        }while(tmp != a);
    }
    KeyType peekKey(){
        return m->key;
    }
    int getSize(){
        return size;
    }
    KeyType extractMin(){
        FibHeapNode<KeyType> *old = m;
        KeyType retV = old->key;
        if(old != nullptr){
            FibHeapNode<KeyType> *child = old->ch;
            while(child != nullptr){
                old->cutC(child);
                insert(child);
                child = old->ch;
            }
            FibHeapNode<KeyType> *tmpRi = old->r; 
            remove(old);
            if(m != nullptr){
                m = tmpRi;
                consolidate();
            }
            size--;
        }
        delete old;
        return retV;
    }

    FibHeapNode<KeyType> *insert(KeyType k){
        FibHeapNode<KeyType> *newN = new FibHeapNode<KeyType>(k);
        insert(newN);
        size++;
        return newN;
    }

    bool decreaseKey(FibHeapNode<KeyType> *a, KeyType k){
        if(k >= a->key){
            return false;
        }
        a->key = k;
        FibHeapNode<KeyType> *tmp = a->p;
        if(tmp != nullptr && a->key < tmp->key){
            Cut(a);
            Cascade_Cut(tmp);
        }
        if(a->key < m->key){
            m = a;
        }
        return true;
    }

    void merge(FibHeap<KeyType> &a){
        t->r = a.h;
        a.h->l = t;
        a.t->r = h;
        h->l = a.t;
        t = a.t;
        if(a.m < m){
            m = a.m;
        }
        size += a.size;
        a.m = nullptr;
        a.h= nullptr;
        a.t = nullptr;
        a.size=0;
    }

    private:
    void insert(FibHeapNode<KeyType> *n){
        if(m == nullptr){
            m = n;
            h = n;
            t = n;
        }
        else{
            t->r = n;
            h->l = n;
            n->l = t;
            n->r = h;
            t = n;
            if(n->key < m->key){
                m = n;
            }
        }
    }
    void Cut(FibHeapNode<KeyType> *a){
        a->p->cutC(a);
        insert(a);
        a->m = false;
    }
    void Cascade_Cut(FibHeapNode<KeyType> *a){
        FibHeapNode<KeyType> *ap = a->p;
        if(ap != nullptr){
            if(!(a->m)){
                a->m = true;
            }
            else{
                Cut(a);
                Cascade_Cut(ap);
            }
        }
    }
    void remove(FibHeapNode<KeyType> *n){
        if(n->r == n){
            m = nullptr;
            h = nullptr; 
            t = nullptr;
        }
        else{
            if(n == h){
                h = n->r;
            }
            if(n == t){
                t = n->l;
            }
            n->l->r = n->r;
            n->r->l = n->l;
        }
        n->l = n;
        n->r = n;
    }
    void connect(FibHeapNode<KeyType> *newC, FibHeapNode<KeyType> *newP){
        remove(newC);
        if(newP->r == newP){
            h = newP;
            t = newP;
            m = newP;
        }
        newP->addC(newC);
    }

    void consolidate(){
        float flD = log2(size);
        int D = flD;
        FibHeapNode<KeyType> *ranks[D];
        for(int i = 0; i <= D; i++){
            ranks[i] = nullptr;
        }
        FibHeapNode<KeyType> *tmp = h;
        do{
            int tmpD = tmp->rk;
            while(ranks[tmpD] != nullptr && ranks[tmpD] != tmp){
                FibHeapNode<KeyType> *tmp2 = ranks[tmpD];
                if(tmp->key > tmp2->key){
                    FibHeapNode<KeyType> *tmp3 = tmp;
                    tmp = tmp2;
                    tmp2 = tmp3;
                }
                connect(tmp2, tmp);
                ranks[tmpD] = nullptr;
                tmpD++;
            }
            ranks[tmpD] = tmp;
            tmp = tmp->r;
        }while(tmp != h);
        h = nullptr;
        t = nullptr;
        m = nullptr;
        for(int i = 0; i <= D; i++){
            if(ranks[i] != nullptr){
                insert(ranks[i]);
            }
        }
    }
};
#endif