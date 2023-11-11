#include <iostream>
using namespace std;

struct Node 
{
    int data;
    Node* next;
};

class Graph 
{
public:
    int numVertices;          
    Node** adjList;         

   //default constructor
    Graph() 
    {
        numVertices = 0;
        adjList = new Node * [numVertices];
        for (int i = 0; i < numVertices; i++) 
        {
            adjList[i] = nullptr;
        }
    }

    //parameterized constructr
    Graph(int vertices) 
    {
        numVertices = vertices;
        adjList = new Node * [numVertices];
        for (int i = 0; i < numVertices; i++)
        {
            adjList[i] = nullptr;
        }
    }

    // Add an edge between two vertices
    void addEdge(int src, int dest) 
    {
        Node* newNode = new Node;
        newNode->data = dest;
        newNode->next = adjList[src];
        adjList[src] = newNode;

        newNode = new Node;
        newNode->data = src;
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }

   
    bool isValidPath(int* path, int length) 
    {
        for (int i = 0; i < length - 1; i++)
        {
            int src = path[i];
            int dest = path[i + 1];
            Node* currNode = adjList[src];
            bool found = false;
            while (currNode != nullptr) 
            {
                if (currNode->data == dest)
                {
                    found = true;
                    break;
                }
                currNode = currNode->next;
            }
            if (!found)
            {
                return false;
            }
        }
        return true;
    }
    
    void print()
    {
        for (int i = 0; i < numVertices; i++) 
        {
            Node* currNode = adjList[i];
            cout << i << " --> ";
            while (currNode != nullptr) 
            {
                cout << currNode->data << " ";
                currNode = currNode->next;
            }
            cout << endl;
        }
    }
};

int main() 
{
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 4);
    g.addEdge(1, 2);
    g.addEdge(1, 3);
    g.addEdge(1, 4);
    g.addEdge(2, 3);
    g.addEdge(3, 4);
    g.print();

    int path1[] = { 0, 1, 2, 3, 4 };
    int path2[] = { 0, 1, 4, 3, 6 };
    int path3[] = { 0, 4, 1, 2, 3 };

    cout << "Path 1 is " << (g.isValidPath(path1, 5) ? "valid" : "invalid") << endl;
    cout << "Path 2 is " << (g.isValidPath(path2, 5) ? "valid" : "invalid") << endl;
    cout << "Path 3 is " << (g.isValidPath(path3, 5) ? "valid" : "invalid") << endl;

    return 0;
}
