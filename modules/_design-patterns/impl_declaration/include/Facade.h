#pragma once

class Facade
{
public:
    Facade();
    ~Facade() = default;

public:
    void DoSomething(const std::string& data);

private:
    class Impl;
    std::shared_ptr<Impl> impl_;
};