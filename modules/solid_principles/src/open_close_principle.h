class CustomerProfile {
    public:
    virtual bool isLoyalCustomer() const = 0;
};

class DiscountCalculator {
    public:
    /*
    Open close principle is implemented here using CustomerProfile interface.
    We don't need to create separate calculateDiscountPercent method for each type of customer.
    New type of customer can be easily added without modifying DiscountCalculator class.
    */
    static int calculateDiscountPercent(CustomerProfile* cp) {
        if (cp->isLoyalCustomer()) {
            return 30;
        }
        return 0;
    }
};

class VehicleInsuranceCustomerProfile: public CustomerProfile {
    public:
    virtual bool isLoyalCustomer() const override {
        return true;
    }
};

class HomeInsuranceCustomerProfile: public CustomerProfile {
    public:
    virtual bool isLoyalCustomer() const override {
        return false;
    }
};

class HealthInsuranceCustomerProfile: public CustomerProfile {
    public:
    virtual bool isLoyalCustomer() const override {
        return true;
    }
};