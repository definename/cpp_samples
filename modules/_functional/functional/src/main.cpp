#include <iostream>
#include <string>
#include <functional>

using Functor = std::function<void(const std::string&)>;

void FuncToCall(const std::string& data) {
    std::cout << data << std::endl;
}

int main(int argc, char* argv[])
{
    Functor func_(std::bind(&FuncToCall, std::placeholders::_1));
    Functor func1_ = func_;

    if (func_) {
        func_("0");
    }
    if (func1_) {
        func1_("1");
    }

    auto l = [](const std::string&d){ std::cout << d << " called" << std::endl;};
    Functor func_lambda(l);
    func_lambda("lambda");

    return EXIT_SUCCESS;
}