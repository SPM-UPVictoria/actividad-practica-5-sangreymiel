#include "graph.h"

graph loadGraph(std::string &path) {
	graph g;
	std::string line;
	std::ifstream file(path);
	if (!file.is_open()) {
		return std::vector<std::vector<int>>();
	}
	while (std::getline(file,line)) {
		std::stringstream ss(line);
		std::vector<int> vertices;
		int vertex;
		ss >> vertex; // skip
		while (ss >> vertex) {
			vertices.push_back(vertex);
		}
		g.push_back(vertices);
	}
	return g;
}
