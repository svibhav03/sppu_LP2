#include <iostream>
using namespace std;
#define INT_MAX 2147483647

class Graph
{
    int adjMatrix[20][20];
    int Nodes;
    int Edges;
    int weight;

public:
    void add_edge(int source, int destination, int weight)
    {
        adjMatrix[source][destination] = weight;
    }

    Graph(int Nodes, int Edges)
    {
        this->Nodes = Nodes;
        this->Edges = Edges;
        for (int i = 0; i < Nodes; i++)
        {
            for (int j = 0; j < Nodes; j++)
            {
                adjMatrix[i][j] = 0;
            }
        }
        weight = 0;
    }
    void Display()
    {
        for (int i = 0; i < Nodes; i++)
        {
            for (int j = 0; j < Nodes; j++)
            {
                if (adjMatrix[i][j] != 0)
                {
                    cout << i << " --> " << j << " :  (" << adjMatrix[i][j] << ") " << endl;
                }
            }
        }
    }
    void Create()
    {
        int source;
        int destination;
        int weight;
        for (int i = 0; i < Edges; i++)
        {
            cout << "Enter Source: ";
            cin >> source;
            cout << "Enter Destination: ";
            cin >> destination;
            cout << "Enter Weight: ";
            cin >> weight;
            add_edge(source, destination, weight);
            add_edge(destination, source, weight);
        }
    }
    int heuristic(int source, int destination)
    {
        return abs(source - destination);
    }

    void Prims()
    {
        int edges_no = 0;
        int selected[Nodes];

        for (int i = 0; i < Nodes; i++)
        {
            selected[i] = false;
        }
        selected[0] = true;
        int min = INT_MAX;
        int x = 0;
        int y = 0;

        while (edges_no < Nodes - 1)
        {
            min = INT_MAX; 
            x = 0;         
            y = 0;

            for (int i = 0; i < Nodes; i++)
            {
                if (selected[i])
                {
                    for (int j = 0; j < Nodes; j++)
                    {
                        if (!selected[j] && adjMatrix[i][j])
                        {
                            int total = adjMatrix[i][j] + heuristic(i, j);
                            if (min > total)
                            {
                                min = total;
                                x = i;
                                y = j;
                            }
                        }
                    }
                }
            }

            cout << x << " - " << y << " :  " << adjMatrix[x][y];
            weight += adjMatrix[x][y];
            cout << endl;

            selected[y] = true;

            edges_no++;
        }
        cout << "Weight of minimum spanning tree: " << weight << endl;
    }
};

int main()
{
    int edges, vertices;
	cout<<"Enter number of edges: ";
	cin>>edges;
	cout<<"Enter number of vertices: ";
	cin>>vertices;
    Graph graph(vertices, edges);

	int a, b, c;
	for(int i=0; i<edges; i++){
		cout<<"Enter start edge: ";
		cin>>a;
		cout<<"Enter end edge: ";
		cin>>b;
		cout<<"Enter weight: ";
		cin>>c;
		graph.add_edge(a, b, c);
		cout<<"Edge added!!\n"<<endl;
	}

    cout << "Graph Edges:" << endl;
    graph.Display();
    cout << endl;

    cout << "Minimum Spanning Tree Edges (Prim's algorithm):" << endl;
    graph.Prims();
}
