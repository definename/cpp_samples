#include <iostream>
#include <vector>

/***********************************************************************
S - single responsibility
    "Every software component should have one and only one responsibility"
    "Every software component should have one and only one reason to change"
O - open-closed principle
    "Software components should be closed for modification, but open for extension"
L - liskov substitution(замена) principle
    "Objects should be replaceable with their subtypes without affecting the correctness of the program"
I - interface segregation(разделение) principle
    "No client should be forsed depend on methods it does not use"
D - dependency inversion principle
    "High-level modules should not depend on low-level modules. Both should depend on abstractions"
    "Abstraction should not depend on details. Details should depend on abstractions"
***********************************************************************/

#include "open_close_principle.h"
#include "liskov_substitution_principle.h"
#include "interface_segregation_principle.h"
#include "dependency_inversion_principle.h"

int main(int argc, char *argv[]) {
    // Open close principle
    std::list<CustomerProfile*> customerList{
        new VehicleInsuranceCustomerProfile(),
        new HomeInsuranceCustomerProfile(),
        new HealthInsuranceCustomerProfile()};

    for (auto customer: customerList) {
        std::cout << "Open close discount:" << DiscountCalculator::calculateDiscountPercent(customer) << std::endl;
    }

    while (!customerList.empty()) {
        delete customerList.front();
        customerList.pop_front();
    }

    // Liskov substitution principle
    std::vector<Product*> productList{new Product(), new InHouseProduct()};
    for (auto product: productList) {
        std::cout << "Liskov discount:" << product->getDiscount() << std::endl;
    }

    while (!productList.empty()) {
        delete productList.back();
        productList.pop_back();
    }

    // Interface segregation principle
    XeroxWorkCentre* x = new XeroxWorkCentre();
    x->print();
    delete x;

    // Dependency inversion principle
    ProductRepository* pr = ProductFactory::create();
    ProductCatalog pc(pr);
    pc.listAllProducts();
    delete pr;

    return EXIT_SUCCESS;
}