class Product {
    public:
    Product()
    : discount_(30) {
    }
    virtual double getDiscount() {
        return discount_;
    }
    protected:
    double discount_;
};

class InHouseProduct: public Product {
    public:
    /*
    Overriding getDiscount method allows to use it as subtype of Product but wih custom implemntation of getDiscount method
    */
    double getDiscount() override {
        applyExtraDiscount();
        return discount_;
    }
    private:
    void applyExtraDiscount() {
        discount_ = discount_ * 1.5;
    }
};