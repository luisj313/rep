
#include <iostream>
#include <vector>
using namespace std;

class Grid {
private:
  vector<vector<int>> backingVector;
  int size;

public:
  Grid(int s) {
    size = s;
    backingVector.resize(size);
    for (int i = 0; i < size; i++) {
      backingVector[i].resize(size);
    }
  }
  bool inBounds(int r, int c) { return r < size && c < size && r >= 0 && c >= 0; }
  vector<int> &operator[](int i) { return backingVector[i]; }

  void print() {
    for(int i = 0; i < size; i++) {
      for(int j = 0; j < size; j++) {
        cout << backingVector[i][j] << " ";
      }
      cout << endl;
    }
    cout << endl;
  }
};

void addCell(Grid &world, int row, int col) {
  if (!world.inBounds(row,col)) return;

  if (++world[row][col] == 4) {
    world[row][col] = 0;
    addCell(world, row+1,col);
    addCell(world, row-1,col);
    addCell(world, row,col+1);
    addCell(world, row,col-1);

  }
}

int main() {
    int w;
    cout << " What Grid Size you want ?";
    cin >> w;
  Grid g(w);
  int a;
  int b;
    cout << " INPUT A POINT WITHIN THE GIVEN GRAPH" << endl;
    cin >> a >> b ;

  g[3][2] = 3;
  g[1][2] = 3;
  g[2][2] = 3;
  g[2][3] = 3;
  g[2][1] = 3;

  g.print();
  addCell(g, a, b);

  g.print();
}


