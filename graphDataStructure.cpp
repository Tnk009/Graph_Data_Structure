#include <iostream>
#include <vector>
#include <stack>

class Graph {
private:
    int numVertices;
    std::vector<std::vector<int>> adjacencyList;

public:
    Graph(int vertices) {
        numVertices = vertices;
        adjacencyList.resize(vertices);
    }

    void addEdge(int src, int dest) {
        adjacencyList[src].push_back(dest);
    }

    void DFS(int startVertex) {
        std::vector<bool> visited(numVertices, false);
        std::stack<int> stack;
        stack.push(startVertex);

        while (!stack.empty()) {
            int currentVertex = stack.top();
            stack.pop();

            if (!visited[currentVertex]) {
                visited[currentVertex] = true;
                std::cout << currentVertex << " ";

                for (int neighbor : adjacencyList[currentVertex]) {
                    if (!visited[neighbor]) {
                        stack.push(neighbor);
                    }
                }
            }
        }
    }
};

int main() {
    Graph graph(6);
    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);

    std::cout << "Depth-First Search (DFS) Traversal: ";
    graph.DFS(0);

    return 0;
}
