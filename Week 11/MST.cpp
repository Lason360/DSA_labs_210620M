
#include <iostream>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
using namespace std;

int minKey(int key[], bool mstSet[])
{
	int min = INT_MAX, min_index;

	for(int v = 0; v < 6; v++){
		if (mstSet[v] == false && key[v] < min)
			min = key[v], min_index = v;
    }
    return min_index;
}

void printMST(int parent[], int map[6][6]){
	cout<<"Edge \tWeight\n";
	for (int i = 1; i < 6; i++){
		cout<<parent[i]<<" - "<< i <<"\t"<<map[i][parent[i]] <<"\n";
    }
}

void primMST(int map[6][6])
{

	int parent[6];
	int key[6];
	bool mstSet[6];
	for (int i = 0; i < 6; i++)
		key[i] = INT_MAX, mstSet[i] = false;
	key[0] = 0;
	parent[0] = -1;
	for (int count = 0; count < 5; count++) {
		int u = minKey(key, mstSet);
		mstSet[u] = true;
		for (int v = 0; v < 6; v++)	
			if (map[u][v] && mstSet[v] == false && map[u][v] < key[v]){
				parent[v] = u;
                key[v] = map[u][v];
            }
	}
	printMST(parent, map);
}

int main()
{
	int map[6][6] = { { 0, 3, 0, 0, 0, 1},
						{ 3, 0, 2, 1, 10, 0 },
						{ 0, 2, 0, 3, 0, 5 },
						{ 0, 1, 3, 0, 5, 0 },
						{ 0, 10, 0, 5, 0, 4 },
                        { 1, 0, 5, 0, 4, 0} };

	primMST(map);
}
