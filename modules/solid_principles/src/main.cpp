#include <iostream>

/***********************************************************************
S - single responsibility
    "Every software component should have one and only one responsibility"
    "Every software component should have one and only one reason to change"
O - open-closed principle
    "Software components should be closed for modification, but open for extension"
L - liskov substitution principle
    "Objects should be replaceable with their subtypes without affecting the correctness of the program"
I - interface segregation principle
    "No client should be forsed depend on methods it does not use"
D
***********************************************************************/

#include "lsp.h"

int main(int argc, char *argv[]) {

    XeroxWorkCentre* x = new XeroxWorkCentre();
    x->print();
    delete x;

    return 0;
}