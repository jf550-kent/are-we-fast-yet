#include "Random.hpp"
#include <iostream>
#include <stdexcept>

using namespace std;


Random::Random() {
    this->seed = 74755;
}

int Random::next() {
    this->seed = ((this->seed * 1309) + 13849) & 65535;
    return this->seed;
}

int main() {
    // Random r1;
    // std::cout << r1.seed << "\n"; // 74755
    // std::cout << r1.next() << "\n"; // 22896

    cout << "Testing random number generator ..." << "\n" ;
    Random* rnd = new Random();

    try {
        if (rnd->next() != 22896) { throw "ERROR";}
        if (rnd->next() != 34761) { throw "ERROR"; }
        if (rnd->next() != 34014) { throw "ERROR"; }
        if (rnd->next() != 39231) { throw "ERROR"; }
        if (rnd->next() != 52540) { throw "ERROR"; }
        if (rnd->next() != 41445) { throw "ERROR"; }
        if (rnd->next() !=  1546) { throw "ERROR"; }
        if (rnd->next() !=  5947) { throw "ERROR"; }
        if (rnd->next() != 65224) { throw "ERROR"; }

    } catch (string e) {
        cout << e << "\n";
    }

    cout << "YES!! PASSED :)" << endl;
}