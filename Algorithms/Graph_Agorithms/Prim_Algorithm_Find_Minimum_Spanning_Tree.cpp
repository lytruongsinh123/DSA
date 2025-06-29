#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>

#define MAX 1001
using namespace std;
//         6
//    2----------4
// 9 /|\         |\ 10
//  / |  \       | \
// 1  |1   \ 3  3|  6
//  \ |      \   | /
// 4 \|        \ |/ 8
//    3----------5
//         2

// Bước 1 : Khởi tạo
// Khởi tạo tập V : [1,2,3,4,5,6];
// Khởi tạo tập Vmst : []
// Khỏi tạo tập cây khung nhỏ nhất MST : []

// Bước 2 : Chọn đỉnh bất kỳ trong V, thêm vào Vmst, xóa đỉnh đó khỏi tập V
// Lấy 1 đẩy 1 vào Vmst : [1]
// Xóa 1 trong trong tập V : [2,3,4,5,6]

// Bước 3 : Tìm cảnh có trọng số nhỏ nhất Trong tất cả các cạnh xuất phát từ các đỉnh trong Vmst
// Vmst : [1]
// từ 1 có thể nối với 2 và 3
// cạnh (1 , 2) : 9
// cạnh (1 , 3) : 4
// Lấy cạnh (1,4) thêm vào cây khung nhỏ nhất MST: [(1,3)]
// Xóa 3 trong V : [2,4,5,6]
// Thêm 3 vào Vmst : [1,3]

// Lặp lại bước 3 cho đến khi tập V rỗng
// Vmst : [1,3]
// Đỉnh 1 có thể đến 2 trong tập  V  được cạnh (1,2) : 9
// Đỉnh 3 có thể đến 2 và 5 trong tập V  được cạnh (3,2) : 1
// Chọn cạnh (3,2) thêm vào cây khung nhỏ nhất MST: [(1,3),(3,2)]
// Xóa 2 trong V : [4,5,6]
// Thêm 2 vào Vmst : [1,3,2]

// Lặp lại bước 3 cho đến khi tập V rỗng
// Vmst : [1,3,2]
// Đỉnh 1 ko thể đến đỉnh nào trong V
// Đỉnh 3 có thể đến 5 trong tập V  được cạnh (3,5) : 2
// Đỉnh 2 có thể đến 4 trong tập V  được cạnh (2,4) : 6
// Đỉnh 2 có thể đến 5 trong tập V  được cạnh (2,5) : 3
// Chọn cảnh (3,5) thêm vào cây khung nhỏ nhất MST:[(1,3),(3,2),(3,5)]
// Xóa 5 trong V : [4,6]
// Thêm 5 vào Vmst : [1,3,2,5]

//...
struct Edge
{
    int dinhdau;
    int dinhcuoi;
    int trongso;
};
class Graph
{
  public:
    Graph();
    void InputGraph();
    void Prim1(int u);
  private:
    int sodinh;
    int socanh;
    vector<pair<int, int>> adj[MAX]; // lưu danh sách kề có trọng số
    bool used[MAX]; // đánh dấu đỉnh đó thuộc V hay Vmst if(used[i] == true) thì đỉnh i thuộc Vmst ngược lại
};
Graph::Graph()
{
    sodinh = 0;
    socanh = 0;
}
void Graph::InputGraph()
{
    ifstream fin("input.txt");
    cout << "Nhap so dinh: ";
    fin >> sodinh;
    cout << "Nhap so canh: ";
    fin >> socanh;
    for (int i = 0; i < socanh; i++)
    {
        int u, v, w;
        fin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }
    fin.close();
    memset(used, false, sizeof(used)); // khởi tạo tất cả các đỉnh đều thuộc V
}
void Graph::Prim1(int u)
{
    vector<Edge> MST;               // Lưu các cạnh của cây khung nhỏ nhất
    int d = 0;                      // Tổng trọng số của cây khung nhỏ nhất
    used[u] = true;                 // Đưa đỉnh u vào tập Vmst
    while (MST.size() < sodinh - 1) // Điều kiện dừng khi có n-1 cạnh tương đương với tập V rỗng
    {
        // chọn cạnh có trọng số nhỏ nhất có x thuộc tập V và y thuộc tập Vmst
        int minWeight = INT_MAX;
        int X, Y; // Lưu hai đỉnh của cạnh
        for (int i = 1; i <= sodinh; i++)
        {
            if (used[i]) // Nếu đỉnh i thuộc Vmst
            {
                for(auto x : adj[i]) // Duyệt tất cả các đỉnh kề với i và trọng số của cạnh bắt đầu từ đỉnh i
                {
                    int v = x.first; // Đỉnh kề
                    int w = x.second; // Trọng số cạnh
                    if(!used[v] && w < minWeight) // Nếu đỉnh kề v không thuộc Vmst và thuộc V
                    {
                        minWeight = w; // Cập nhật trọng số nhỏ nhất
                        X = v; // Lưu đỉnh kề của i
                        Y = i; // Lưu đỉnh i
                    }
                    
                }
            }
        }
        MST.push_back({Y, X, minWeight}); // Thêm cạnh vào cây khung nhỏ nhất
        d += minWeight; // Cộng trọng số vào tổng trọng số
        used[X] = true; // Đưa đỉnh X vào tập Vmst Xóa đinh X trong V
    }
    ofstream fout("output.txt");
    fout << "Cay khung nho nhat la: " << endl;
    for (int i = 0; i < MST.size(); i++)
    {
        fout << "(" << MST[i].dinhdau << "," << MST[i].dinhcuoi << ") : " << MST[i].trongso << endl;
    }
    fout << "Tong trong so: " << d << endl;
    fout.close();
}
int main()
{
    Graph g;
    g.InputGraph();
    g.Prim1(1); // Bắt đầu từ đỉnh 1
    return 0;
}
