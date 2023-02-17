#include "../../include/util/adj_graph_override.tpp"

int main()
{
	Graph<int> graph;
	graph.AddVertex(1);
	graph.AddVertex(2);
	graph.AddVertex(3);
	graph.AddVertex(4);
	graph.AddVertex(5);
	graph.AddVertex(6);

	graph.AddEdge(0, 1);
	graph.AddEdge(0, 2);
	graph.AddEdge(0, 3);
	graph.AddEdge(1, 2);
	graph.AddEdge(1, 4);
	graph.AddEdge(2, 3);
	graph.AddEdge(2, 4);
	graph.AddEdge(2, 5);
	graph.AddEdge(3, 5);
	graph.AddEdge(4, 5);

	std::cout << graph.GetNeighbors(2) << std::endl;
	
	std::cout << graph << std::endl;
}