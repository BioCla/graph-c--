#ifndef ADJ_GRAPH_OVERRIDE
#define ADJ_GRAPH_OVERRIDE

#include "list_override.tpp"

template <typename T>
class Graph
{
protected:
	std::unordered_map<int, T> vertices;
	std::unordered_map<int, List<int>> adjacency_lists;
	int next_vertex_index = 0;

public:
	Graph() {}
	int AddVertex(const T &data);
	void RemoveVertex(int index);
	void AddEdge(int u, int v);
	void RemoveEdge(int u, int v);
	bool HasEdge(int u, int v) const;
	const T &GetVertex(int index) const;
	void SetVertex(int index, const T &data);
	int NumVertices() const;
	int NumEdges() const;
	List<int> GetNeighbors(int index) const;

	friend std::ostream &operator<<(std::ostream &out, const Graph<T> &graph)
	{
		out << "Vertices: " << graph.vertices.size() << std::endl;
		for (auto &vertex : graph.vertices)
			out << vertex.first << ": " << vertex.second << std::endl;
		out << "Edges: " << graph.NumEdges() << std::endl;
		for (auto &adjacency_list : graph.adjacency_lists)
			out << adjacency_list.first << ": " << adjacency_list.second << std::endl;
		return out;
	}

	const T &operator[](int index) const
	{
		return GetVertex(index);
	}

	T &operator[](int index)
	{
		return vertices[index];
	}
};

template <typename T, typename K>
class WeightedGraph : public Graph<T>
{
protected:
	std::unordered_map<int, std::unordered_map<int, K>> weights;

public:
	WeightedGraph() {}
	void AddEdge(int u, int v, K weight);
	void RemoveEdge(int u, int v);
	K GetWeight(int u, int v) const;
	void SetWeight(int u, int v, K weight);

	friend std::ostream &operator<<(std::ostream &out, const WeightedGraph<T, K> &graph)
	{
		out << "Vertices: " << graph.vertices.size() << std::endl;
		for (auto &vertex : graph.vertices)
			out << vertex.first << ": " << vertex.second << std::endl;
		out << "Edges: " << graph.NumEdges() << std::endl;
		for (auto &adjacency_list : graph.adjacency_lists)
			out << adjacency_list.first << ": " << adjacency_list.second << std::endl;
		out << "Weights: " << std::endl;
		for (auto &weight : graph.weights)
			for (auto &w : weight.second)
				out << weight.first << " - " << w.first << ": " << w.second << std::endl;
		return out;
	}

	const K &operator()(int u, int v) const
	{
		return GetWeight(u, v);
	}

	K &operator()(int u, int v)
	{
		return weights[u][v];
	}
};

#include "../../src/util/adj_graph_override.ipp"

#endif