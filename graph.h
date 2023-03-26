#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

typedef std::vector<std::vector<int>> graph;

graph loadGraph(std::string &path);
void printGraph(graph g);
