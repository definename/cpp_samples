#pragma once

//////////////////////////////////////////////////////////////////////////
// Interface of the GraphAsAdjacencyMatrix class.
//

class GraphAsAdjacencyMatrix
{
	//
	//! Construction and destruction.
	//
public:
	//! Constructor.
	GraphAsAdjacencyMatrix();
	//! Destructor.
	~GraphAsAdjacencyMatrix();

	//
	// Public interface.
	//
public:
	//! Scans graph. M���� ������ "� �������".
	void Scan(
		int vertex, /* ����� ������� ������� */
		int vertexNumber /* ����� ����� ������ */
		);

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
	//! Node type
	typedef int Node;
	//! Row type.
	typedef std::vector<Node> Row;
	//! Matrix type.
	typedef std::vector<Row> Matrix;
	//! Color container type.
	typedef std::vector<Color> Colors;

	//
	// Private interface.
	//
private:
	//! Matrix.
	Matrix matrix_;
	//! Colors of the vertex.
	Colors colors_;
};