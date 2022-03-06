#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

#define MAX 100000

int reverseDigits(int number);

vector<int> breadthFirstSearch(int start, int end);

int getPathSize(int index, vector<int> parents);

int main(){
    vector<int> bfs(MAX);
    int qtt_cases, start, end;

    cin >> qtt_cases;

    while (qtt_cases--){
        cin >> start >> end;
        bfs = breadthFirstSearch(start, end);
        cout << getPathSize(end, bfs) << endl;
    }

    return 0;
}

int reverseDigits(int number){
   int reversed = 0, remainder;

   while (number != 0){
       remainder = number % 10;
       reversed = reversed * 10 + remainder;
       number /= 10;
   }
   
   return reversed;
}

vector<int> breadthFirstSearch(int start, int end){
    int node, button;
    vector<bool> visited(MAX);
    vector<int> parents(MAX);
    queue<int> queue;

    fill_n(visited.begin(), MAX, false);
    fill_n(parents.begin(), MAX, 0);

    queue.push(start);
    visited[start] = true;

    while (!queue.empty()){
        node = queue.front();
        queue.pop();
        
        button = node + 1;
        for (int i = 0; i < 2; i++){

            if (!visited[button]){
            	queue.push(button);
            	visited[button] = true;
            	parents[button] = node;
            	if (button == end) return parents;
            }
            
            button = reverseDigits(node);
        }

    }

    return parents;
}

int getPathSize(int index, vector<int> parents){
    int size = 0;
	
    for (int i = index; i != 0; i = parents[i])
        size++;
	
    return size - 1;
}
