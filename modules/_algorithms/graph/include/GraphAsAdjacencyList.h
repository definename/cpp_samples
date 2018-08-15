#pragma once

//////////////////////////////////////////////////////////////////////////
// Interface of the GraphAsAdjacencyList class.
//

class GraphAsAdjacencyList
{
	//
	//! Construction and destruction.
	//
public:
	//! Constructor.
	GraphAsAdjacencyList();
	//! Destructor.
	~GraphAsAdjacencyList();

	//
	// Public types.
	//
public:
	//! Color type.
	enum Color
	{
		WHITE,
		GRAY,
		BLACK
	};
	//! Node type.
	struct Node
	{
		int num; /* Vertex number */
		bool last; /* Is the last vertex */
	};
	//! List type.
	typedef std::vector<Node> List;
	//! Main list type.
	typedef std::vector<List> MainList;
	//! Color container type.
	typedef std::vector<Color> Colors;

	//
	// Public interface.
	//
public:
	//! Scans graph. Mетод поиска "в глубину".
	void Scan(int vertexNum /* номер вершины */);

	//
	// Private data members.
	//
private:
	//! Main list.
	MainList list_;
	//! Colors of the vertex.
	Colors colors_;
};