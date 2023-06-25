#include "som/Random.hpp"
#include "som/Object.hpp"
#include <iostream>
#include <vector>


using namespace std;

class Storage {
    public:
        int count;

        int benchmark();
        Object buildTreeDepth(int depth, Random* random);
};

int Storage::benchmark() {
    count = 0;
    Random rdn;
    buildTreeDepth(7, &rdn);
    return count;
}

Object Storage::buildTreeDepth(int depth, Random* random) {
    this->count++; 

    if (depth == 1) {
        int randomNumber = random->next() % 10 + 1;
        Object obj; 
        obj.createChild(randomNumber);
    }

    Object obj;

    for (int i = 0; i < 4; i++) {
        obj.addChild(this->buildTreeDepth(depth-1, random));
    }

    return obj;
}


int main() {
    Storage str; 
    cout << str.benchmark() << endl;

    return 0;
}