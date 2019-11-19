#include <iostream>

using namespace std;

struct Node
{
    int v1, v2, weight;

    Node() {};

    Node(int v1, int v2, int weight)
    {
        this->v1 = v1;

        this->v2 = v2;

        this->weight = weight;
    }
};


ostream& operator<< (ostream& out, Node& node)
{
    out << "weight = " << node.v1 << "  v1 = " << node.v2 << " v2 =  " << node.weight;

    return out;
}


void Swap(Node& a, Node& b)
{
    Node c = a;
    a = b;
    b = c;
}


void sort(Node* arr, int size)
{
    bool ok = true;

    while (ok)
    {
        ok = false;

        for (int i = 0; i < size - 1; i++)
        {
            if (arr[i + 1].weight < arr[i].weight)
            {
                Swap(arr[i + 1], arr[i]);

                ok = true;
            }
        }
    }
}


int Kruskal_algorithm(Node* arr, int num_of_edges, int verticies)
{
    int min_sp_tree = 0;

    int* parent = new int[verticies];

    int v1, v2, weight;

    int to_change, changed;

    for (int i = 0; i < verticies; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < num_of_edges; i++)
    {
        v1 = arr[i].v1;

        v2 = arr[i].v2;

        weight = arr[i].weight;


        if (parent[v2] != parent[v1])
        {
            cout << arr[i] << endl;

            min_sp_tree += weight;

            to_change = parent[v1];

            changed = parent[v2];

            for (int j = 0; j < verticies; j++)
            {
                if (parent[j] == changed)
                {
                    parent[j] = to_change;
                }
            }
        }
    }


    delete[] parent;

    return min_sp_tree;
}

int main()
{
    int edges = 0;

    const int verticies = 12;

    const int& n = verticies;

    int G[12][12] = { { 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 , 0 } ,
                      { 0 , 0,  2,  5,  7,  0,  0,  0,  0,  0,  0,  0 },
                      { 0,	0,  0,  0,  0,  7,  0,  7,  0,  0,  0,  0 },
                      { 0,	5,  0,  0,  0,  5,  4,  0,  0,  0,  0,  0 },
                      { 0,	7,  0,  0,  0,  0,  3,  1,  0,  0,  0,  0 },
                      { 0,	0,  0,  5,  0,  0,  0,  0,  4,  1,  0,  0 },
                      { 0,	0,  0,  4,  3,  0,  0,  0,  4,  0,  2,  0 },
                      { 0,	0,  7,  0,  1,  0,  0,  0,  0,  3,  2,  0 },
                      { 0,	0,  0,  0,  0,  0,  4,  0,  0,  0,  0,  3 },
                      { 0,	0,  0,  0,  0,  1,  0,  3,  0,  0,  0,  6 },
                      { 0,	0,  0,  0,  0,  0,  2,  2,  0,  0,  0,  4 },
                      { 0,	0,  0,  0,  0,  0,  0,  0,  0,  6,  4,  0 },
    };


    Node arr[50];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (G[i][j] != 0)
            {
                arr[edges] = Node(i, j, G[i][j]);

                edges++;
            }
        }
    }

    sort(arr, edges);

    int min_sp_tree = Kruskal_algorithm(arr, edges, n);

    cout << " MST =  " << min_sp_tree;

}