#pragma once

namespace emulator
{

class Test
{
public:
	static Test& GetInstance()
	{
		static Test test;
		return test;
	}

public:
	bool IsNG() const;
	void SetNG(const bool ng);

private:
	Test();
	Test(const Test&);
	void operator=(const Test&);

private:
	static bool isNG_;
};

} // namespace emulator