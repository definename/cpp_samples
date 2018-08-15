#include "pch.h"

int Func(std::shared_ptr<int> ptr)
{
	if (!ptr)
		return 0;

	return 1 + *ptr;
}

template<typename FuncT, typename MutexT, typename PtrT>
// C++ 14 decltype(auto) LockAndCall(FuncT func, MutexT& mutex, PtrT ptr)
auto LockAndCall(FuncT func, MutexT& mutex, PtrT ptr) -> decltype(func(ptr))
{
	std::lock_guard<MutexT> l(mutex);
	return func(ptr);
}

int main(int argc, char* argv[])
{
	// Checks types just for test purpose.
	std::cout << typeid(decltype(Func)).name() << std::endl;
	std::cout << typeid(decltype(Func(nullptr))).name() << std::endl;

	// Test.
	std::mutex mutex;
	std::cout << LockAndCall(Func, mutex, nullptr) << std::endl;
	std::cout << LockAndCall(Func, mutex, std::make_shared<int>(10)) << std::endl;

	return EXIT_SUCCESS;
}