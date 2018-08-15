#include "pch.h"
#include "TreeNode.h"

TreeNode::TreeNode(const int& value)
	: value_(value)
	, color_(WHITE)
	, distance_(0)
	, discovered_(0)
	, finished_(0)
	, leftArcWeight_(std::numeric_limits<double>::infinity())
	, rightArcWeight_(std::numeric_limits<double>::infinity())
	, key_(std::numeric_limits<double>::infinity())
{ }

TreeNode::~TreeNode()
{ }