#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

class DisJoint {
private:
	std::unordered_map<char, char> parent;
	std::unordered_map<char, int> rank;
public:
	/*DisJoint() {
		char universe[] = { 'a','b','c','d','e'};
		for (char x : universe) {
			parent[x] = x;
		}
	}*/

	char Find(char item) {
		if (parent[item] == item) {
			return item;
		}
		else{
			return Find(parent[item]);
		}
	}

	void Union(char set_1, char set_2) {
		if (rank[set_1] > rank[set_2]) {
			parent[set_2] = set_1;
		}
		else if (rank[set_2] > rank[set_1]) {
			parent[set_1] = set_2;
		}
		else{
			parent[set_1] = set_2;
			parent[set_2]++;
		}
	}

	void MakeSet(char set_) {
		parent[set_] = set_;
		rank[set_] = 0;
	}
};

struct Edge
{
	char vertex1;
	char vertex2;
	int weight;

	Edge(char v1, char v2, int w) :vertex1(v1), vertex2(v2), weight(w) {}
};

struct Graph {
	std::vector<char> vertices;
	std::vector<Edge> edges;
};


void Kruskal(Graph& g) {
	DisJoint d;
	std::vector<Edge> A; //Holder for edges
	for (auto c : g.vertices) {
		d.MakeSet(c);
	}
	std::sort(g.edges.begin(), g.edges.end(), [](Edge x, Edge y) {return x.weight < y.weight; });
	for (Edge e: g.edges)
	{
		char root1 = d.Find(e.vertex1);
		char root2 = d.Find(e.vertex2);
		if (root1 != root2) {
			A.push_back(e);
			d.Union(root1, root2);
		}
	}

	for (Edge e : A) {
		std::cout << e.vertex1 << "--> " << e.vertex2 << " " << e.weight << std::endl;
	}
}

double myPow(double x, int n) {

	double val = 1;
	double val1 = 1;

	
	while (std::abs(n) > 0) {
		if (n > 0) {
			val = val * x;
			n -= 1;
		}
		else if (n < 0) {
			val1 = val1 * x;
			val = 1 / val1;
			n += 1;
		}
	}

	return val;
}



int main() {
	char t[] = {'a','b','c','d','e','f'};

	Graph g1;
	g1.vertices = std::vector<char>(t, t + sizeof(t) / sizeof(t[0]));
	
	g1.edges.push_back(Edge('a', 'b', 4));
	g1.edges.push_back(Edge('a', 'f', 2));
	g1.edges.push_back(Edge('b', 'f', 5));
	g1.edges.push_back(Edge('b', 'c', 6));
	g1.edges.push_back(Edge('f', 'c', 1));
	g1.edges.push_back(Edge('f', 'e', 4));
	g1.edges.push_back(Edge('c', 'd', 3));
	g1.edges.push_back(Edge('d', 'e', 2));

	Kruskal(g1);
}