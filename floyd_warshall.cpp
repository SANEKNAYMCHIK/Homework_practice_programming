#include <iostream>
#include <vector>
#include <math.h>

 
int main() {
    int n, m, q, a, b;
    long long c;
    std::cin >> n >> m >> q;
    std::vector<std::vector<double>> graph = {};
    std::vector<double> temp = {};
    for (int i = 0; i < n; ++i) {
        temp.clear();
        for (int j = 0; j < n; ++j) {
            temp.push_back(INFINITY);
        }
        graph.push_back(temp);
    }
    for (int i = 0; i < m; ++i) {
        std::cin >> a >> b >> c;
        graph[a - 1][b - 1] = std::min(graph[a - 1][b - 1], (double) c);
        graph[b - 1][a - 1] = std::min(graph[a - 1][b - 1], (double) c);
    }
    //floyd
    for (int i = 0; i < n; ++i) {
        graph[i][i] = 0;
    }
    for (int k = 0; k < n; ++k) {
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (graph[i][j] > graph[i][k] + graph[k][j]) {
                    graph[i][j] = graph[i][k] + graph[k][j];
                }
            }   
        }    
    }
    for (int i = 0; i < q; ++i) {
        std::cin >> a >> b;
        if (graph[a - 1][b - 1] == INFINITY) {
            std::cout << -1 << '\n';
        } else {
            std::cout << (long long)graph[a - 1][b - 1] << '\n';
        }
    }    
    return 0;
}