#include "pch.h"

using Functor = std::function<void(const std::string& data)>;

void Func(const std::string& data);

int main(int argc, char* argv[])
{
    Functor func_(std::bind(&Func, std::placeholders::_1));

    Functor func1_, func2_, func3_;
    func1_ = func_;
    func2_ = func_;
    func3_ = func_;

    if (func_)
        func_("0");
    if (func1_)
        func1_("1");
    if (func2_)
        func2_("2");
    if (func3_)
        func3_("3");

    return 0;
}

void Func(const std::string& data)
{
    std::cout << data << std::endl;
}