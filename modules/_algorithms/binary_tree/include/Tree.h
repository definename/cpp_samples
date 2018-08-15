#pragma once

#include "TreeNode.h"

class Tree
{
	//
	// Construction and destruction.
	//
public:
	//! Constructor.
	Tree();
	//! Destructor.
	~Tree();

	//
	// Public types.
	//
public:
	//! TreeNode::TreeNodePtr vector type.
	typedef std::vector<TreeNode::TreeNodePtr> NodeVector;
	//! Row type.
	typedef std::vector<double> Row;
	//! Type of weight matrix.
	typedef std::vector<Row> Matrix;
	//! Type of algorithm.
	enum Algorithm
	{
		BellmanFordPath,
		BreadthFirstSearch,
		DepthFirstSearch,
		DijkstraPath,
		FloydWarshallPath,
		PrimTree
	};
	//! Edge type.
	struct Edge
	{
		TreeNode::TreeNodePtr u_, v_;
		double weight_;
	};
	//! Edge vector type.
	typedef std::vector<Edge> EdgeVector;

	//
	// Public interface.
	//
public:
	//! Bellman-Ford algorithm.
	void BellmanFord();
	//! Search all tree nodes with BFS.
	void BFS();
	//! Deletes node.
	void Delete(const int& value);
	//! Dijkstra algorithm.
	void Dijkstra();
	//! Search all tree nodes with DFS.
	void DFS();
	//! Finds node with given value.
	TreeNode::TreeNodePtr Find(const int& value);
	//! FloydWarshall algorithm.
	void FloydWarshall();
	// Returns maximum height.
	int GetMaxHeight();
	//! Inserts node.
	void Insert(const int& value);
	//! Kruskal algorithm.
	void Kruskal();
	//! Prim algorithm.
	void Prim();
	//! Prints tree.
	void Print();

	//
	// Private interface.
	//
private:
	//! Implementation of BFS algorithm.
	void BFS(TreeNode::TreeNodePtr startNodePtr);
	//! Deletes node.
	void Delete(TreeNode::TreeNodePtr nodePtr);
	//! DFS support method.
	void DFSVisit(TreeNode::TreeNodePtr nodePtr);
	//! Finds node with given value.
	TreeNode::TreeNodePtr Find(TreeNode::TreeNodePtr nodePtr, const int& value);
	//! Returns height.
	int GetHeight(TreeNode::TreeNodePtr node);
	//! Inserts into tree.
	bool InsertIntoTree(TreeNode::TreeNodePtr node);
	//! Prepares algorithm.
	void PrepareAlgorithm(const Algorithm type);
	//! Prints tree.
	void Print(const TreeNode::TreeNodePtr nodePtr, std::string& str);
	//! Attention: Sort nodes before printing.
	void PrintMaxtrix(const Matrix& m);
	//! Relax.
	void Relax(TreeNode::TreeNodePtr nodeFrom, TreeNode::TreeNodePtr nodeTo, const double& weight);
	//! Transplants.
	void Transplant(TreeNode::TreeNodePtr destinationNode, TreeNode::TreeNodePtr sourceNode);
	//! Returns pointer to minimum node.
	TreeNode::TreeNodePtr TreeMinimum(TreeNode::TreeNodePtr nodePtr);

	//
	// Private data members.
	//
private:
	//! Root node.
	TreeNode::TreeNodePtr rootNode_;
	//! DFS time.
	int DFSTimestamp_;
	//! TreeNode::TreeNodePtr container.
	NodeVector nodes_;
};

//! Tree smart pointer type.
typedef boost::shared_ptr<Tree> TreePtr;