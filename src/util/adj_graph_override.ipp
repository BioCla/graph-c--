template<typename T>
int Graph<T>::AddVertex(const T& data) {
	vertices[next_vertex_index] = data;
	adjacency_lists[next_vertex_index] = List<int>();
	next_vertex_index++;
	return next_vertex_index - 1;
}

template<typename T>
void Graph<T>::RemoveVertex(int index) {
	vertices.erase(index);
	adjacency_lists.erase(index);
	for (auto& adjacency_list : adjacency_lists)
		adjacency_list.second.remove(index);
}

template<typename T>
void Graph<T>::AddEdge(int u, int v) {
	if (HasEdge(u, v)) return;
	if (adjacency_lists.find(u) == adjacency_lists.end())
		return;
	adjacency_lists[u].push_back(v);
}

template<typename T>
void Graph<T>::RemoveEdge(int u, int v) {
	if (adjacency_lists.find(u) == adjacency_lists.end())
		return;
	adjacency_lists[u].remove(v);
}

template<typename T>
bool Graph<T>::HasEdge(int u, int v) const {
	if (adjacency_lists.find(u) == adjacency_lists.end())
		return false;
	return adjacency_lists.at(u).contains(v);
}

template<typename T>
const T& Graph<T>::GetVertex(int index) const {
	return vertices.at(index);
}

template<typename T>
void Graph<T>::SetVertex(int index, const T& data) {
	vertices[index] = data;
}

template<typename T>
int Graph<T>::NumVertices() const {
	return vertices.size();
}

template<typename T>
int Graph<T>::NumEdges() const {
	int num_edges = 0;
	for (auto& adjacency_list : adjacency_lists)
		num_edges += adjacency_list.second.size();
	return num_edges / 2;
}

template<typename T>
List<int> Graph<T>::GetNeighbors(int index) const {
	return adjacency_lists.at(index);
}

template<typename T, typename K>
void WeightedGraph<T, K>::AddEdge(int u, int v, K weight) {
	if (Graph<T>::HasEdge(u, v)) return;
	if (Graph<T>::adjacency_lists.find(u) == Graph<T>::adjacency_lists.end())
		return;
	Graph<T>::adjacency_lists[u].push_back(v);
	weights[u][v] = weight;
}

template<typename T, typename K>
void WeightedGraph<T, K>::RemoveEdge(int u, int v) {
	if (Graph<T>::adjacency_lists.find(u) == Graph<T>::adjacency_lists.end())
		return;
	Graph<T>::adjacency_lists[u].remove(v);
	weights[u].erase(v);
}

template<typename T, typename K>
K WeightedGraph<T, K>::GetWeight(int u, int v) const {
	if (weights.find(u) == weights.end() || weights[u].find(v) == weights[u].end())
		return K();
	return weights.at(u).at(v);
}

template<typename T, typename K>
void WeightedGraph<T, K>::SetWeight(int u, int v, K weight) {
	if (weights.find(u) == weights.end() || weights[u].find(v) == weights[u].end())
		return;
	weights[u][v] = weight;
	weights[v][u] = weight;
}
