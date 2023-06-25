#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

class Element {
public:
    int value;
    Element* next;

    Element(int val) {
        this->value = val;
        this->next = NULL;
    }

    int length() {
        if (next == NULL) {
            return 1;
        }

        return 1 + next->length();
    }

    void setNext(Element* e) { this->next = e;}
    Element* getNext() { return this->next; }

    void printList() {
        cout << this->value << "\n";

        Element* nextElement = this->next;

        while (nextElement != NULL) {
            cout << nextElement->value << "\n";
            nextElement = nextElement->next;
        }
    }

};

class List {
public:
    static Element* makeList(int length);
    static int benchmark();
    static bool isShorterThan(Element* x, Element* y);
    static Element* tail(Element* x, Element* y, Element* z);
};

Element* List::makeList(int lenght) {
    if (lenght == 0 ) {
        return NULL;
    }
    Element* e = new Element(lenght);
    e->setNext(makeList(lenght - 1));

    return e;
}

bool List::isShorterThan(Element* x, Element* y) {
    Element* xTail = x;
    Element* yTail = y; 

    while (yTail != NULL) {
        if (xTail == NULL) { return true; }
        xTail = xTail->getNext();
        yTail = yTail->getNext();
    }

    return false;
    
}

Element* List::tail(Element* x, Element* y, Element* z) {
    if (isShorterThan(y,x)) {
        return tail(tail(x->getNext(), y, z),
                    tail(y->getNext(), z, x),
                    tail(z->getNext(), x, y));
    } else {
        return z;
    }
}

int List::benchmark() {
    Element* result = tail(makeList(15), makeList(10), makeList(6));

    return result->length();
}


int main() {
    auto start = high_resolution_clock::now();
    List::benchmark();
    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<microseconds>(stop - start);

    cout << "Starting List benchmark ... \n";
    cout << "List iterations=1 runtime: " << duration.count() << " μs" << "\n";

}