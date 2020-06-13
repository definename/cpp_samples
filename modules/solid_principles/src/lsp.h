#include <iostream>

/*********************************
Interface definition
*********************************/

class IPrint {
    public:
    virtual void print() = 0;
    virtual void getPrintSpoolDetails() = 0;
};

class IScan {
    public:
    virtual void scan() = 0;
    virtual void scanPhoto() = 0;
};

class IFax {
    public:
    virtual void fax() = 0;
    virtual void internetFax() = 0;
};

/*********************************
Interface implementation
*********************************/

class XeroxWorkCentre: public IPrint, IScan, IFax {
    public:
    void print() override {
        std::cout << "print" << std::endl;
    }
    virtual void getPrintSpoolDetails() override {
        std::cout << "getPrintSpoolDetails" << std::endl;
    }

    virtual void scan() override {
        std::cout << "scan" << std::endl;
    }
    virtual void scanPhoto() override {
        std::cout << "scanPhoto" << std::endl;
    }

    virtual void fax() override {
        std::cout << "fax" << std::endl;
    }
    void internetFax() override {
        std::cout << "internetFax" << std::endl;
    }
};

class HPPrinterAndScaner: public IPrint, IScan {
    public:
    void print() override {
    }
    virtual void getPrintSpoolDetails() override {
    }

    virtual void scan() override {
    }
    virtual void scanPhoto() override{
    }
};

class CanonPrinter: public IPrint {
    public:
    void print() override {
    }
    virtual void getPrintSpoolDetails() override {
    }
};