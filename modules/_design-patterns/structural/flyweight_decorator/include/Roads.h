#pragma once

class Roads
{
public:
	Roads();
	~Roads() = default;

public:
	using Graph = std::vector<std::vector<int>>;

private:
	Graph graph_;
};