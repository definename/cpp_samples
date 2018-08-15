#include "pch.h"
#include "Tree.h"

Tree::Tree()
	: DFSTimestamp_(0)
{ }

Tree::~Tree()
{ }

void Tree::BellmanFord()
{
	//! Sets arc weight.
	for (size_t i = 0; i != nodes_.size(); ++i)
	{
		TreeNode::TreeNodePtr nodePtr = nodes_[i];
		if (nodePtr->leftPtr_)
		{
			nodePtr->leftArcWeight_ = nodePtr->leftPtr_->value_;
			//! Logging.
			std::cout << nodePtr->value_ << " - " << nodePtr->leftPtr_->value_;
			std::cout << " arc weight: " <<  nodePtr->leftArcWeight_ << std::endl;
		}
		if (nodePtr->rightPtr_)
		{
			nodePtr->rightArcWeight_ = nodePtr->rightPtr_->value_;
			//! Logging.
			std::cout << nodePtr->value_ << " - " << nodePtr->rightPtr_->value_;
			std::cout << " arc weight: " << nodePtr->rightArcWeight_ << std::endl;
		}
	}

	//! Initialization.
	PrepareAlgorithm(BellmanFordPath);
	rootNode_->distance_ = 0;

	//! Main loop: We have nodes.size() - 1 iteration over all edges.
	for (size_t i = 0; i < nodes_.size() - 1; ++i)
	{
		for (size_t y = 0; y != nodes_.size(); ++y)
		{
			TreeNode::TreeNodePtr nodePtr = nodes_[y];
			if (nodePtr->leftPtr_)
				Relax(nodePtr->leftPtr_, nodePtr, nodePtr->leftArcWeight_);
			if (nodePtr->rightPtr_)
				Relax(nodePtr->rightPtr_, nodePtr, nodePtr->rightArcWeight_);
		}
	}

	//! Prints result.
	for (size_t i = 0; i != nodes_.size(); ++i)
	{
		TreeNode::TreeNodePtr nodePtr = nodes_[i];
		std::cout << "Node: " << nodePtr->value_;
		std::cout << " minimum distance to root: " << nodes_[i]->distance_ << " over:";

		while (nodePtr)
		{
			if (nodePtr->parentPtr_)
				std::cout << " " << nodePtr->parentPtr_->value_;
			nodePtr = nodePtr->parentPtr_;
		}
		std::cout << std::endl;
	}
}

void Tree::BFS()
{
	BFS(rootNode_);
}

void Tree::BFS(TreeNode::TreeNodePtr startNodePtr)
{
	PrepareAlgorithm(BreadthFirstSearch);

	startNodePtr->color_ = TreeNode::GRAY;
	startNodePtr->distance_ = 0;
	startNodePtr->parentPtr_ = nullptr;

	std::queue<TreeNode::TreeNodePtr> nodeQueue;
	nodeQueue.push(startNodePtr);
	while (!nodeQueue.empty())
	{
		TreeNode::TreeNodePtr nodeTemp = nodeQueue.front();

		// Logging.
		std::cout << "Node: " << nodeTemp->value_<< " was discovered" << std::endl;

		if (nodeTemp->leftPtr_ && nodeTemp->leftPtr_->color_ == TreeNode::WHITE)
		{
			nodeTemp->leftPtr_->color_ = TreeNode::GRAY;
			nodeTemp->leftPtr_->distance_ = nodeTemp->distance_ + 1;
			nodeTemp->leftPtr_->parentPtr_ = nodeTemp;
			nodeQueue.push(nodeTemp->leftPtr_);
		}

		if (nodeTemp->rightPtr_ && nodeTemp->rightPtr_->color_ == TreeNode::WHITE)
		{
			nodeTemp->rightPtr_->color_ = TreeNode::GRAY;
			nodeTemp->rightPtr_->distance_ = nodeTemp->distance_ + 1;
			nodeTemp->rightPtr_->parentPtr_ = nodeTemp;
			nodeQueue.push(nodeTemp->rightPtr_);
		}

		nodeTemp->color_ = TreeNode::BLACK;
		nodeQueue.pop();
	}
}

void Tree::Delete(const int& value)
{
	TreeNode::TreeNodePtr node = Find(rootNode_, value);
	if (node)
	{
		Delete(node);
		nodes_.erase(
			std::remove_if(
			nodes_.begin(),
			nodes_.end(),
			[value](const TreeNode::TreeNodePtr& node) { return node->value_ == value;}));
	}
	else
		throw std::runtime_error("There is no node with given value");
}

void Tree::Delete(TreeNode::TreeNodePtr nodePtr)
{
	if (!nodePtr->leftPtr_)
		Transplant(nodePtr, nodePtr->rightPtr_);
	else if (!nodePtr->rightPtr_)
		Transplant(nodePtr, nodePtr->leftPtr_);
	else
	{
		TreeNode::TreeNodePtr minNode = TreeMinimum(nodePtr->rightPtr_);
		if (minNode->parentPtr_ != nodePtr)
		{
			Transplant(minNode, minNode->rightPtr_);
			minNode->rightPtr_ = nodePtr->rightPtr_;
			minNode->rightPtr_->parentPtr_ = minNode;
		}
		Transplant(nodePtr, minNode);
		minNode->leftPtr_ = nodePtr->leftPtr_;
		minNode->leftPtr_->parentPtr_ = minNode;
	}
}

void Tree::Dijkstra()
{
	NodeVector q;
	//! Sets arc weight.
	for (size_t i = 0; i != nodes_.size(); ++i)
	{
		TreeNode::TreeNodePtr nodePtr = nodes_[i];
		if (nodePtr->leftPtr_)
		{
			nodePtr->leftArcWeight_ = nodePtr->leftPtr_->value_;
			//! Logging.
			std::cout << nodePtr->value_ << " - " << nodePtr->leftPtr_->value_;
			std::cout << " arc weight: " <<  nodePtr->leftArcWeight_ << std::endl;
		}
		if (nodePtr->rightPtr_)
		{
			nodePtr->rightArcWeight_ = nodePtr->rightPtr_->value_;
			//! Logging.
			std::cout << nodePtr->value_ << " - " << nodePtr->rightPtr_->value_;
			std::cout << " arc weight: " << nodePtr->rightArcWeight_ << std::endl;
		}
		q.push_back(nodePtr);
	}

	//! Initialization.
	PrepareAlgorithm(DijkstraPath);
	rootNode_->distance_ = 0;

	//! Main loop.
	while (!q.empty())
	{
		std::sort(
			q.begin(),
			q.end(),
			[] (const TreeNode::TreeNodePtr& f, const TreeNode::TreeNodePtr& s)
			-> bool { return f->distance_ < s->distance_ ;});

		TreeNode::TreeNodePtr nodePtr = q.front();
		//! Checks all edge.
		if (nodePtr->leftPtr_)
			Relax(nodePtr->leftPtr_, nodePtr, nodePtr->leftArcWeight_);
		if (nodePtr->rightPtr_)
			Relax(nodePtr->rightPtr_, nodePtr, nodePtr->rightArcWeight_);

		q.erase(q.begin());
	}

	//! Prints result.
	for (size_t i = 0; i != nodes_.size(); ++i)
	{
		TreeNode::TreeNodePtr nodePtr = nodes_[i];
		std::cout << "Node: " << nodePtr->value_;
		std::cout << " minimum distance to root: " << nodes_[i]->distance_ << " over:";

		while (nodePtr)
		{
			if (nodePtr->parentPtr_)
				std::cout << " " << nodePtr->parentPtr_->value_;
			nodePtr = nodePtr->parentPtr_;
		}
		std::cout << std::endl;
	}
}

void Tree::DFS()
{
	PrepareAlgorithm(DepthFirstSearch);
	DFSTimestamp_ = 0;
	for (size_t i = 0; i != nodes_.size(); ++i)
	{
		if (nodes_[i]->color_ == TreeNode::WHITE)
		{
			std::cout << "DFS algorithm is going to scan node with value: "<< nodes_[i]->value_ << std::endl;
			DFSVisit(nodes_[i]);
		}
	}
}

void Tree::DFSVisit(TreeNode::TreeNodePtr nodePtr)
{
	DFSTimestamp_ = DFSTimestamp_ + 1;
	nodePtr->discovered_ = DFSTimestamp_;
	nodePtr->color_ = TreeNode::GRAY;
	
	// Logging.
	std::cout << "Node: " << nodePtr->value_;
	std::cout << " scanning was started at: " << nodePtr->discovered_ << std::endl;

	if (nodePtr->leftPtr_ && nodePtr->leftPtr_->color_ == TreeNode::WHITE)
	{
		nodePtr->leftPtr_->parentPtr_ = nodePtr;
		DFSVisit(nodePtr->leftPtr_);
	}

	if (nodePtr->rightPtr_ && nodePtr->rightPtr_->color_ == TreeNode::WHITE)
	{
		nodePtr->rightPtr_->parentPtr_ = nodePtr;
		DFSVisit(nodePtr->rightPtr_);
	}

	DFSTimestamp_ = DFSTimestamp_ + 1;
	nodePtr->finished_ = DFSTimestamp_;
	nodePtr->color_ = TreeNode::BLACK;

	//Logging.
	std::cout << "Node: " << nodePtr->value_;
	std::cout << " scanning was finished at: " << nodePtr->finished_ << std::endl;
}

TreeNode::TreeNodePtr Tree::Find(const int& value)
{
	return Find(rootNode_, value);
}

TreeNode::TreeNodePtr Tree::Find(TreeNode::TreeNodePtr nodePtr, const int& value)
{
	if (!nodePtr || nodePtr->value_ == value)
		return nodePtr;
	else if (value < nodePtr->value_)
		return Find(nodePtr->leftPtr_, value);
	else
		return Find(nodePtr->rightPtr_, value);
}

void Tree::FloydWarshall()
{
	//! Sets arc weight.
	for (size_t i = 0; i != nodes_.size(); ++i)
	{
		TreeNode::TreeNodePtr nodePtr = nodes_[i];
		if (nodePtr->leftPtr_)
		{
			nodePtr->leftArcWeight_ = nodePtr->leftPtr_->value_;
			//! Logging.
			std::cout << nodePtr->value_ << " - " << nodePtr->leftPtr_->value_;
			std::cout << " arc weight: " <<  nodePtr->leftArcWeight_ << std::endl;
		}
		if (nodePtr->rightPtr_)
		{
			nodePtr->rightArcWeight_ = nodePtr->rightPtr_->value_;
			//! Logging.
			std::cout << nodePtr->value_ << " - " << nodePtr->rightPtr_->value_;
			std::cout << " arc weight: " << nodePtr->rightArcWeight_ << std::endl;
		}
	}

	Matrix w(nodes_.size());

	std::sort(nodes_.begin(), nodes_.end(), [] (const TreeNode::TreeNodePtr& f, const TreeNode::TreeNodePtr& s)
	{ return f->value_ < s->value_; });

	//! Creates weight matrix;
	for (size_t i = 0; i != nodes_.size(); ++i)
	{
		Row row(nodes_.size(), std::numeric_limits<double>::infinity());
		TreeNode::TreeNodePtr nodePtr = nodes_.at(i);
		if (nodePtr->leftPtr_)
		{
			int value = nodePtr->leftPtr_->value_;
			NodeVector::const_iterator it;
			it = std::find_if(nodes_.begin(), nodes_.end(), [value] (const TreeNode::TreeNodePtr& n)
			{ return n->value_ == value; });
			row[it - nodes_.begin()] = nodePtr->leftArcWeight_;
		}

		if (nodePtr->rightPtr_)
		{
			int value = nodePtr->rightPtr_->value_;
			NodeVector::const_iterator it;
			it = std::find_if(nodes_.begin(), nodes_.end(), [value] (const TreeNode::TreeNodePtr& n)
			{ return n->value_ == value; });
			row[it - nodes_.begin()] = nodePtr->rightArcWeight_;
		}
		w[i] = row;
	}

	std::cout << "\nWeight matrix:" << std::endl;
	PrintMaxtrix(w);
	Matrix d;
	d = w;
	//! Main loop.
	for (size_t k = 0; k != nodes_.size(); ++k)
	{
		for (size_t i = 0; i != nodes_.size(); ++i)
		{
			for (size_t j = 0; j != nodes_.size(); ++j)
			{
				d[i][j] = std::min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	std::cout << "\nResult matrix:" << std::endl;
	PrintMaxtrix(d);
}

int Tree::GetHeight(TreeNode::TreeNodePtr nodePtr)
{
	int leftHeight(0);
	int rightHeight(0);

	if (!nodePtr)
		return 0;
	if (nodePtr->leftPtr_)
		leftHeight = GetHeight(nodePtr->leftPtr_);
	if (nodePtr->rightPtr_)
		rightHeight = GetHeight(nodePtr->rightPtr_);

	return (std::max(leftHeight, rightHeight) + 1);
}

int Tree::GetMaxHeight()
{
	return GetHeight(rootNode_);
}

void Tree::Insert(const int& value)
{
	TreeNode::TreeNodePtr node(new TreeNode(value));
	if (InsertIntoTree(node))
	{
		std::cout << "Node: " << value << " have been inserted" << std::endl;
		nodes_.push_back(node);
	}
	else
	{
		std::cout << "Unable to insert node with value: " << value << std::endl;
	}
}

void Tree::Kruskal()
{
	NodeVector v;
	//! Sets edge weight, set key color.
	for (size_t i = 0; i != nodes_.size(); ++i)
	{
		TreeNode::TreeNodePtr nodePtr = nodes_[i];
		if (nodePtr->leftPtr_)
		{
			nodePtr->leftArcWeight_ = nodePtr->leftPtr_->value_;
			//! Logging.
			std::cout << nodePtr->value_ << " - " << nodePtr->leftPtr_->value_;
			std::cout << " arc weight: " <<  nodePtr->leftArcWeight_ << std::endl;
		}
		if (nodePtr->rightPtr_)
		{
			nodePtr->rightArcWeight_ = nodePtr->rightPtr_->value_;
			//! Logging.
			std::cout << nodePtr->value_ << " - " << nodePtr->rightPtr_->value_;
			std::cout << " arc weight: " << nodePtr->rightArcWeight_ << std::endl;
		}
		v.push_back(nodePtr);
		nodePtr->key_ = i;
	}

	//! Create edges vector.
	EdgeVector edges;
	for (size_t n = 0; n != v.size(); ++n)
	{
		TreeNode::TreeNodePtr nodePtr = v[n];
		if (nodePtr->leftPtr_)
		{
			Edge e;
			e.u_ = nodePtr;
			e.v_ = nodePtr->leftPtr_;
			e.weight_ = nodePtr->leftArcWeight_;
			edges.push_back(e);
		}
		if (nodePtr->rightPtr_)
		{
			Edge e;
			e.u_ = nodePtr;
			e.v_ = nodePtr->rightPtr_;
			e.weight_ = nodePtr->rightArcWeight_;
			edges.push_back(e);
		}
	}

	std::sort(
		edges.begin(),
		edges.end(),
		[] (const Edge& f, const Edge& s) -> bool { return f.weight_ < s.weight_ ;});

	//! Main loop.
	EdgeVector a;
	for (size_t e = 0; e != edges.size(); ++e)
	{
		Edge edge = edges[e];
		if (edge.u_->key_ != edge.v_->key_)
		{
			double oldKey = edge.u_->key_;
			double newKey = edge.v_->key_;
			for (size_t k = 0; k != v.size(); ++k)
			{
				if (v[k]->key_ == oldKey)
					v[k]->key_ = newKey;
			}
			a.push_back(edge);
		}
	}

	//! Prints result.
	std::cout << "Kruskal result graph contains edges: " << std::endl;
	for (size_t j = 0; j != a.size(); ++j)
	{
		std::cout << a[j].u_->value_ << "(" << a[j].u_->key_ << ") - " << a[j].v_->value_ << "(" << a[j].u_->key_ << ")" << std::endl;
	}
}

bool Tree::InsertIntoTree(TreeNode::TreeNodePtr node)
{
	TreeNode::TreeNodePtr parentNode;
	TreeNode::TreeNodePtr destinationNode = rootNode_;
	while (destinationNode)
	{
		parentNode = destinationNode;
		if (node->value_ < destinationNode->value_)
			destinationNode = destinationNode->leftPtr_;
		else if (node->value_ > destinationNode->value_)
			destinationNode = destinationNode->rightPtr_;
		else
			return false; //! Duplicate.
	}

	node->parentPtr_ = parentNode;
	if (!parentNode)
		rootNode_ = node;
	else if (node->value_ < parentNode->value_)
		parentNode->leftPtr_ = node;
	else
		parentNode->rightPtr_ = node;

	return true;
}

void Tree::PrepareAlgorithm(const Algorithm type)
{
	for (size_t i = 0; i != nodes_.size(); ++i)
	{
		if (type == BreadthFirstSearch)
		{
			nodes_[i]->color_ = TreeNode::WHITE;
			nodes_[i]->parentPtr_.reset();
			nodes_[i]->distance_ = 0;
		}
		else if (type == DepthFirstSearch)
		{
			nodes_[i]->color_ = TreeNode::WHITE;
			nodes_[i]->parentPtr_.reset();
			nodes_[i]->discovered_ = 0;
			nodes_[i]->finished_ = 0;

		}
		else if (type == DijkstraPath || type == BellmanFordPath)
		{
			// Sets distance to infinity.
			nodes_[i]->distance_ = std::numeric_limits<double>::infinity();
			nodes_[i]->parentPtr_.reset();
		}
		else if (type == PrimTree)
		{
			nodes_[i]->key_ = std::numeric_limits<double>::infinity();
			nodes_[i]->parentPtr_.reset();
		}
	}
}

void Tree::Prim()
{
	NodeVector q;
	//! Sets arc weight.
	for (size_t i = 0; i != nodes_.size(); ++i)
	{
		TreeNode::TreeNodePtr nodePtr = nodes_[i];
		if (nodePtr->leftPtr_)
		{
			nodePtr->leftArcWeight_ = nodePtr->leftPtr_->value_;
			//! Logging.
			std::cout << nodePtr->value_ << " - " << nodePtr->leftPtr_->value_;
			std::cout << " arc weight: " <<  nodePtr->leftArcWeight_ << std::endl;
		}
		if (nodePtr->rightPtr_)
		{
			nodePtr->rightArcWeight_ = nodePtr->rightPtr_->value_;
			//! Logging.
			std::cout << nodePtr->value_ << " - " << nodePtr->rightPtr_->value_;
			std::cout << " arc weight: " << nodePtr->rightArcWeight_ << std::endl;
		}
		q.push_back(nodePtr);
	}

	PrepareAlgorithm(PrimTree);
	rootNode_->key_ = 0;

	//! Main loop.
	while (!q.empty())
	{
		std::sort(
			q.begin(),
			q.end(),
			[] (const TreeNode::TreeNodePtr& f, const TreeNode::TreeNodePtr& s)
			-> bool { return f->key_ < s->key_ ;});

		TreeNode::TreeNodePtr nodePtr = q.front();
		//! Checks all edges.
		if (nodePtr->leftPtr_)
		{
			int value = nodePtr->leftPtr_->value_;
			NodeVector::const_iterator it;
			it = std::find_if(q.begin(), q.end(), [value] (const TreeNode::TreeNodePtr& n)
			-> bool { return n->value_ == value; });

			if (it != q.end() && nodePtr->leftArcWeight_ < nodePtr->leftPtr_->key_)
			{
				nodePtr->leftPtr_->parentPtr_ = nodePtr;
				nodePtr->leftPtr_->key_ = nodePtr->leftArcWeight_;
			}
		}
		if (nodePtr->rightPtr_)
		{
			int value = nodePtr->rightPtr_->value_;
			NodeVector::const_iterator it;
			it = std::find_if(q.begin(), q.end(), [value] (const TreeNode::TreeNodePtr& n)
			{ return n->value_ == value; });

			if (it != q.end() && nodePtr->rightArcWeight_ < nodePtr->rightPtr_->key_)
			{
				nodePtr->rightPtr_->parentPtr_ = nodePtr;
				nodePtr->rightPtr_->key_ = nodePtr->rightArcWeight_;
			}
		}

		q.erase(q.begin());
	}

	//! Checks Prim result.
	std::cout << "Prim result graph contains edges: " << std::endl;
	for (size_t i = 0; i != nodes_.size(); ++i)
	{
		TreeNode::TreeNodePtr nodePtr = nodes_[i];
		if (nodePtr->parentPtr_)
			std::cout << nodePtr->value_ << " - " << nodePtr->parentPtr_->value_ << std::endl;
	}
}

void Tree::Print()
{
	Print(rootNode_, std::string(""));
}

void Tree::Print(const TreeNode::TreeNodePtr nodePtr, std::string& str)
{
	if (nodePtr)
	{
		Print(nodePtr->rightPtr_, str + "   ");
		std::cout << str << nodePtr->value_ << std::endl;
		Print(nodePtr->leftPtr_, str + "   ");
	}
}

void Tree::PrintMaxtrix(const Matrix& m)
{
	for (size_t y = 0; y != nodes_.size(); ++y)
	{
		int offset = 4;
		if (y == 0)
			offset = 8;

		std::cout << std::setw(offset) << std::right << nodes_[y]->value_;
	}
	std::cout << std::endl;
	for (size_t row = 0; row != nodes_.size(); ++row)
	{
		std::cout << std::setw(4) << std::right << nodes_[row]->value_;
		for (size_t col = 0; col != nodes_.size(); ++col)
		{
			if (m[row][col] == std::numeric_limits<double>::infinity())
				std::cout << std::setw(4) << std::right << "nil";
			else
				std::cout << std::setw(4) << std::right << m[row][col];
		}
		std::cout << std::endl;
	}
}

void Tree::Relax(TreeNode::TreeNodePtr nodeFrom, TreeNode::TreeNodePtr nodeTo, const double& weight)
{
	if (nodeFrom->distance_ > nodeTo->distance_ + weight)
	{
		nodeFrom->distance_ = nodeTo->distance_ + weight;
		nodeFrom->parentPtr_ = nodeTo;
	}
}

void Tree::Transplant(TreeNode::TreeNodePtr destinationNode, TreeNode::TreeNodePtr sourceNode)
{
	if (!destinationNode->parentPtr_)
		rootNode_ = sourceNode;
	else if (destinationNode == destinationNode->parentPtr_->leftPtr_)
		destinationNode->parentPtr_->leftPtr_ = sourceNode;
	else if (destinationNode == destinationNode->parentPtr_->rightPtr_)
		destinationNode->parentPtr_->rightPtr_ = sourceNode;

	if (sourceNode)
		sourceNode->parentPtr_ = destinationNode->parentPtr_;
}

TreeNode::TreeNodePtr Tree::TreeMinimum(TreeNode::TreeNodePtr nodePtr)
{
	while (nodePtr->leftPtr_)
	{
		nodePtr = nodePtr->leftPtr_;
	}
	return nodePtr;
}
