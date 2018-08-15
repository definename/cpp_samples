#include "pch.h"
#include "Facade.h"

class Facade::Impl
{
public:
    Impl();
    ~Impl() = default;

public:
    void DoSomething(const std::string& data);

private:
    std::string sql_;
};

Facade::Impl::Impl()
    : sql_("sql") {
}

void Facade::Impl::DoSomething(const std::string& data) {
    std::cout << sql_ << "data is: " << data << std::endl;
}

Facade::Facade()
    : impl_(new Impl()) {
}

void Facade::DoSomething(const std::string& data) {
    impl_->DoSomething(data);
}