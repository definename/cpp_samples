#include <list>
#include <string>
#include <iostream>

/* High-level module(ProductCatalog) low-level module(SQLProductRepository) depend on this interface */
class ProductRepository {
    public:
    virtual std::list<std::string> getAllProductNames() const = 0;
};

/* Low-level module(SQLProductRepository) depends on ProductRepository interface */
class SQLProductRepository: public ProductRepository {
    public:
    std::list<std::string> getAllProductNames() const {
        return std::list<std::string>{"name1", "name2"};
    }
};

class ProductFactory {
    public:
    static ProductRepository* create() {
        return new SQLProductRepository();
    }
};

/*
 High-level module(ProductCatalog) depends on ProductRepository interface
 Dependency injection happens through constructor of ProductCatalog
*/
class ProductCatalog {
    public:
    ProductCatalog(ProductRepository* pr)
    : pr_(pr) {
    }

    void listAllProducts() const {
        std::list<std::string> plist = pr_->getAllProductNames();
        std::list<std::string>::const_iterator it = plist.begin();
        for (it; it != plist.end(); ++it) {
            std::cout << *it << std::endl;
        }
    }

    private:
    ProductRepository* pr_;
};