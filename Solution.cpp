#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100000

// Inverte os dígitos de um número
int reverseDigits(int number){
   int reversed = 0, remainder;

   while (number != 0){
       remainder = number % 10;
       reversed = reversed * 10 + remainder;
       number /= 10;
   }
   
   return reversed;
}

// Busca em largura
vector<int> breadthFirstSearch(int start, int end){
    int node, button;
    vector<bool> visited(MAX);
    vector<int> parents(MAX);
    queue<int> queue;

    queue.push(start);

    fill_n(visited.begin(), MAX, false);
    visited[start] = true;

    fill_n(parents.begin(), MAX, 0);

    while (!queue.empty()){
        node = queue.front();
        queue.pop();

		button = node + 1; // Botão 1: adiciona uma unidade
		for (int i = 0; i < 2; i++){

			if (!visited[button]){
				queue.push(button);
				visited[button] = true;
				parents[button] = node;
				if (button == end) return parents;
			}

			button = reverseDigits(node); // Botão 2: inverte os dígitos
		}

    }

    return parents;
}

// Retorna o tamanho de um caminho
int getPathSize(int start, int end, vector<int> parents){
    int size = 0;
    for (int i = end; i != 0; i = parents[i])
        size++;
    return size - 1;
}

int main(){
    vector<int> bfs(MAX);
    int qtt_cases, start, end;

    cin >> qtt_cases;

    while (qtt_cases--){
        cin >> start >> end;
        bfs = breadthFirstSearch(start, end);
        cout << getPathSize(start, end, bfs) << endl;
    }

    return 0;
}
