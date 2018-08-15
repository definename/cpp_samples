#pragma once

class TreeNode
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	explicit TreeNode(const int& value);
	//! Destructor.
	~TreeNode();

	//
	// Public types.
	//
public:
	//! TreeNode smart pointer type.
	typedef boost::shared_ptr<TreeNode> TreeNodePtr;
	//! Color of node type.
	enum Color
	{
		WHITE,
		GRAY,
		BLACK
	};

	//
	// Public data members.
	//
public:
	//! Node left pointer.
	TreeNodePtr leftPtr_;
	//! Parent node pointer;
	TreeNodePtr parentPtr_;
	//! Node right pointer.
	TreeNodePtr rightPtr_;
	//! Node value.
	int value_;
	//! Color of node.
	Color color_;
	//! Distance.
	double distance_;
	//! Started work with node.
	int discovered_;
	//! Stopped work with node.
	int finished_;
	//! Left arc weight.
	double leftArcWeight_;
	//! Right arc weight.
	double rightArcWeight_;
	//! Key.
	double key_;
};