#include <iostream>
#include <math.h>

using namespace std;

class Term {
public:
    double coef;
    int degree;
    Term *next;

    Term(double coef, int degree, Term *next = nullptr) {
        this->coef = coef;
        this->degree = degree;
        this->next = next;
    }

    void print(ostream &os) {
        if (degree == 0)
            os << coef;
        else if (degree == 1)
            os << coef << "x";
        else
            os << coef << "x^" << degree;
    }
};

class Poly {
private:
    Term *head;
public:
    Poly() {
        head = nullptr;
    }
    void addFront(double coef, int degree) {
        Term *n = new Term(coef, degree);
        n->next = head;
        head = n;
    }
    void print(ostream &os) {
        Term *cur = head;
        while (cur != nullptr) {
            cur->print(os);
            if (cur->next != nullptr)
                os << " + ";

            cur = cur->next;
        }
    }
    bool search(int degree) {
        for (Term *cur = head; cur != nullptr; cur = cur->next) {
            if (degree == cur->degree) {
                return true;
            }
        }
        return false;
    }
    double eval(double x) {
        double sum = 0;
        for (Term *cur = head; cur != nullptr; cur = cur->next) {
            sum += cur->coef * pow(x, cur->degree);
        }
        return sum;
    }
    void addBack(double coef, int degree) {
        Term *n = new Term(coef, degree);
        if (head == nullptr) {
            head = n;
            return;
        }
        else {
            Term *cur = head;
            while (cur->next != nullptr) {
                cur = cur->next;
            }
            cur->next = n;
            return;
        }
    }
    void addOrdered(double coef, int degree) {
        Term *n = new Term(coef, degree);
        if (head == nullptr) { // empty
            head = n;
        }
        else if (degree > head->degree) { // insert front
            n->next = head;
            head = n;
        }
        else { // middle & back
            Term *prev = head;
            Term *cur = head->next;
            while (cur != nullptr) {
                if (degree > cur->degree) {
                    break;
                }
                prev = prev->next;
                cur = cur->next;
            }
            if(degree < prev->degree){
            prev->next = n;
            n->next = cur;
            }
            else if(degree == prev->degree){
            prev->coef += n->coef;
            }
            else{
            prev->next = n;
            n->next = cur;
            }
        }
    }
    bool remove(int degree) {
        if (!search(degree)) {
            return false;
        }
        else if (head->degree == degree) { // front
            Term *del = head;
            head = head->next;
            delete del;

            return true;
        }
        else { // middle & back
            Term *prev = head;
            Term *cur = head->next;
            while (cur->degree != degree) {
                prev = prev->next;
                cur = cur->next;
            }
            prev->next = cur->next;
            delete cur;

            return true;
        }
    }
    void clear() {
        while (head != nullptr) {
            Term *del = head;
            head = head->next;
            delete del;
            // remove(head->degree);
        }
    }

    ~Poly() {
        clear();
    }

    void deepCopy(const Poly &src) {
        for (Term *cur = src.head; cur != nullptr; cur = cur->next) {
            this->addBack(cur->coef, cur->degree);
        }
    }

    Poly(const Poly &src) {
        head = nullptr;
        deepCopy(src);
    }

    const Poly &operator=(const Poly &src) {
        if (this != &src) {
            clear();
            deepCopy(src);
        }
        return *this;
    }
};

ostream &operator<<(ostream &os, Poly &poly) {
    poly.print(os);
    return os;
}

int main() {
    Poly poly;
    poly.addOrdered(1, 5);
    poly.addOrdered(1, 7);
    poly.addOrdered(1, 1);
    poly.addOrdered(1, 6);
    poly.addOrdered(1, 4);
    poly.addOrdered(1, 0);
    poly.addOrdered(2,0);
    poly.addOrdered(6,2);
    poly.addOrdered(3,7);
    poly.addOrdered(8,6);
    poly.addOrdered(1, 5);
    poly.addOrdered(1, 7);
    poly.addOrdered(1, 1);
    poly.addOrdered(1, 6);
    poly.addOrdered(1, 4);
    poly.addOrdered(1, 0);
    poly.addOrdered(2,0);
    poly.addOrdered(6,2);
    poly.addOrdered(3,7);
    poly.addOrdered(8,6);
    poly.addOrdered(1, 5);
    poly.addOrdered(1, 7);
    poly.addOrdered(1, 1);
    poly.addOrdered(1, 6);
    poly.addOrdered(1, 4);
    poly.addOrdered(1, 0);
    poly.addOrdered(2,0);
    poly.addOrdered(6,2);
    poly.addOrdered(3,7);
    poly.addOrdered(8,6);
    poly.addOrdered(1, 5);
    poly.addOrdered(1, 7);
    poly.addOrdered(1, 1);
    poly.addOrdered(1, 6);
    poly.addOrdered(1, 4);
    poly.addOrdered(1, 0);
    poly.addOrdered(2,0);
    poly.addOrdered(6,2);
    poly.addOrdered(3,7);
    poly.addOrdered(8,6);
    poly.addOrdered(1, 5);
    poly.addOrdered(1, 7);
    poly.addOrdered(1, 1);
    poly.addOrdered(1, 6);
    poly.addOrdered(1, 4);
    poly.addOrdered(1, 0);
    poly.addOrdered(2,0);
    poly.addOrdered(6,2);
    poly.addOrdered(3,7);
    poly.addOrdered(8,6);
    poly.addOrdered(1, 5);
    poly.addOrdered(1, 7);
    poly.addOrdered(1, 1);
    poly.addOrdered(1, 6);
    poly.addOrdered(1, 4);
    poly.addOrdered(1, 0);
    poly.addOrdered(2,0);
    poly.addOrdered(6,2); 
    poly.addOrdered(3,7);
    poly.addOrdered(8,6);
    Poly poly2;
    cout << poly << endl;
    poly2.deepCopy(poly);
    poly2.addOrdered(9,3);
    cout << poly2 << endl;

    return 0;
}