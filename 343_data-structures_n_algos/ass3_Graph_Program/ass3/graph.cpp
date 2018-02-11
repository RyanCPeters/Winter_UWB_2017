#include <queue>
#include <climits>
#include <set>
#include <iostream>
#include <fstream>
#include <sstream>

#include "graph.h"

/**
* A graph is made up of vertices and edges
* A vertex can be connected to other vertices via weighted, directed edge
*/


////////////////////////////////////////////////////////////////////////////////
// This is 80 characters - Keep all lines under 80 characters                 //
////////////////////////////////////////////////////////////////////////////////


/** constructor, empty graph */
Graph::Graph(): numberOfVertices(0), numberOfEdges(0),vertices() {}

/** destructor, delete all vertices and edges
only vertices stored in map
no pointers to edges created by graph */
Graph::~Graph() {
    vertices.clear();
}

/** return number of vertices */
int Graph::getNumVertices() const 
{ return numberOfVertices; }

/** return number of vertices */
int Graph::getNumEdges() const 
{ return numberOfEdges; }

/** add a new edge between start and end vertex
if the vertices do not exist, create them
calls Vertex::connect
a vertex cannot connect to itself
nor have multiple edges connecting to another singular vertex */
bool Graph::add(const std::string& start, const std::string& end,
                const int& edgeWeight)
{
    auto iter1 = vertices.find(start);
    auto iter2 = vertices.find(end);
    if(iter1 == vertices.end()){
        vertices.emplace(start,new Vertex(start));
        iter1 = vertices.find(start);
    }
    if(iter2 == vertices.end()){
        vertices.emplace(end, new Vertex(end));
    }
    return iter1->second->connect(end, edgeWeight);

}

/** return weight of the edge between start and end
returns INT_MAX if not connected or vertices don't exist */
int Graph::getEdgeWeight(const std::string& start,const std::string& end)const
{
    auto iter = vertices.find(start);
    if(iter == vertices.end())return INT_MAX;
    int ret = iter->second->getEdgeWeight(end);
    return (ret >= 0)? ret : INT_MAX;
}

/** read edges from file
the first line of the file is an integer, indicating number of edges
each edge line is in the form of "string string int"
fromVertex  toVertex    edgeWeight */
void Graph::readFile(std::string filename) 
{
    std::ifstream ifile(filename);
    int len = 0;
    ifile >> len;
    for(int i = 0; i < len; ++i){
        std::string start, end;
        int weight = 0;
        ifile >> start;
        ifile >> end;
        ifile >> weight;
        add(start,end,weight);
    }
}

/** depth-first traversal starting from startLabel
call the function visit on each vertex label */
void Graph::depthFirstTraversal(std::string startLabel,
								void visit(const std::string&)) 
{
    auto iter = vertices.find(startLabel);
    visit(iter->first);
}

/** breadth-first traversal starting from startLabel
call the function visit on each vertex label */
void Graph::breadthFirstTraversal(std::string startLabel,
								  void visit(const std::string&)) 
{}

/** find the lowest cost from startLabel to all vertices that can be reached
using Djikstra's shortest-path algorithm
record costs in the given map weight
weight["F"] = 10 indicates the cost to get to "F" is 10
record the shortest path to each vertex using given map previous
previous["F"] = "C" indicates get to "F" via "C"

cpplint gives warning to use pointer instead of a non-const map
which I am ignoring for readability */
void Graph::djikstraCostToAllVertices(
	std::string startLabel,
	std::map<std::string, int>& weight,
	std::map<std::string, std::string>& previous) {}

/** helper for depthFirstTraversal */
void Graph::depthFirstTraversalHelper(Vertex* startVertex,
									  void visit(const std::string&)) 
{}

/** helper for breadthFirstTraversal */
void Graph::breadthFirstTraversalHelper(Vertex*startVertex,
										void visit(const std::string&)) 
{}

/** mark all verticies as unvisited */
void Graph::unvisitVertices() {}

/** find a vertex, if it does not exist return nullptr */
Vertex* Graph::findVertex(const std::string& vertexLabel) const 
{ return nullptr; }

/** find a vertex, if it does not exist create it and return it */
Vertex* Graph::findOrCreateVertex(const std::string& vertexLabel) 
{ return nullptr; }