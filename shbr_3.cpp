#include <iostream>
#include <vector>
#include <numeric>

using ull = unsigned long long;

// initial matrix
std::vector<std::vector<ull>> connections;

std::vector<std::tuple<ull, ull, ull>> requirements;

std::vector<std::tuple<ull, ull, ull, ull>> candidates;

bool satisfied(ull maxcost) {
  auto tmp = connections;

  // mark all appropriate candidats with their time
  for (auto [u, v, t, c] : candidates) {
    if (c <= maxcost) {
      tmp[u][v] = t;
    }
  }

  for (size_t k = 0; k < tmp.size(); k++) {
    for (size_t i = 0; i < tmp.size(); i++) {
      for (size_t j = 0; j < tmp.size(); j++) {
        tmp[i][j] = std::min(tmp[i][j], tmp[i][k] + tmp[k][j]);
      }
    }
  }

  // validate
  for (auto [a, b, t] : requirements) {
    if (tmp[a][b] > t) {
      return false;
    }
  }

  return true;
}

int main() {
  ull n, m;
  std::cin >> n >> m;

  connections = std::vector<std::vector<ull>>{n, std::vector<ull>(n, 0)};
  for (ull i = 0; i < m; i++) {
    ull u, v, t;
    std::cin >> u >> v >> t;
    connections[u - 1][v - 1] = t;
  }

  ull k;
  std::cin >> k;

  ull maxcost = 0;
  candidates = std::vector<std::tuple<ull, ull, ull, ull>>(k, {0, 0, 0, 0});
  for (ull i = 0; i < k; i++) {
    ull u, v, t, c;
    std::cin >> u >> v >> t >> c;
    candidates[i] = {u - 1, v - 1, t, c};
    maxcost = std::max(maxcost, c);
  }

  ull p;
  std::cin >> p;

  requirements = std::vector<std::tuple<ull, ull, ull>>(n, {0, 0, 0});
  for (ull i = 0; i < p; i++) {
    ull a, b, t;
    std::cin >> a >> b >> t;
    requirements.emplace_back(a - 1, b - 1, t);
  }

  ull beg = 1;
  ull end = maxcost + 1;
  while (beg < end) {
    ull mid = std::midpoint(beg, end);
    if (satisfied(mid)) {
      // go left
      end = mid;
    } else {
      beg = mid + 1;
    }
  }

  maxcost = beg;
  std::vector<ull> minimal;
  for (ull i = 0; i < candidates.size(); i++) {
    auto [u, v, t, c] = candidates[i];
    if (c <= maxcost) {
      minimal.push_back(i+1);
    }
  }
  std::cout << minimal.size() << std::endl;
  for (auto c : minimal) {
    std::cout << c << ' ';
  }
}
