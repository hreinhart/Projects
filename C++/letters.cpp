#include <iostream>
#include <string>

using namespace std;

class Letter {
public:
    char ch;
    Letter *next;

    Letter(char ch, Letter *next = nullptr) {
        this->ch = ch;
        this->next = next;
    }
};

int main() {
    // Letter t('t');
    // Letter i('i');
    // Letter d('d');
    // Letter e('e');

    // t.next = &i;
    // i.next = &d;
    // d.next = &e;

    // cout << t.ch;
    // cout << t.next->ch;
    // cout << t.next->next->ch;
    // cout << t.next->next->next->ch;
    // cout << endl;

    Letter *t = new Letter('t');
    Letter *i = new Letter('i');
    Letter *d = new Letter('d');
    Letter *e = new Letter('e');

    t->next = i;
    i->next = d;
    d->next = e;

    cout << t->ch;
    cout << t->next->ch;
    cout << t->next->next->ch;
    cout << t->next->next->next->ch;
    cout << endl;

    return 0;
}