#include <bits/stdc++.h>

using namespace std;

#define oo 1e5

// Đây là code tìm cây khung nhỏ nhất trong đồ thị liên thông, chú ý là đồ thị phải liên thông nhé

int n, m, x, y, value;
vector<pair<int, pair<int, int> > > edge; // lưu các cạnh
vector<pair<int, pair<int, int> > > MST;    // lưu cây khung
vector<int> P, R;       // mảng lưu nút cha và rank

bool cmp(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
        return a.second.second < b.second.second;
}

void input() {
        cin >> n >> m;       // nhập số lượng đỉnh và số lượng cạnh
        R.resize(n);
        P.resize(n);
        for(int i = 0; i < m; i++) {
                cin >> x >> y >> value;
                edge.push_back(make_pair(x - 1, make_pair(y - 1, value)));
        }
}

void init() {   // khởi tạo giá trị ban đầu cho 2 mảng Parent và Rank
        for(int i = 0; i < n; i++) {
                P[i] = i;
                R[i] = 1;
        }
}

int findx(int x) {     // Tìm cha của x
        return x == P[x] ? x : P[x] = findx(P[x]);
}

bool join(int a, int b) {       // Kết hợp 2 đỉnh lại với nhau
        int x = findx(a), y = findx(b);
        if(x != y) {  //  Nếu 2 đỉnh khác parent thì ta sẽ thao tác
                if(R[x] > R[y])
                        P[y] = P[x];
                else if(R[x] < R[y])
                        P[x] = P[y];
                else {
                        P[x] = P[y];
                        R[y]++;
                }
                return true;
        }
        return false;
}

void kruskal() {
        sort(edge.begin(), edge.end(), cmp);  //  Sắp xếp các cạnh theo thứ tự tăng dần
        for(int i = 0; i < m; i++) {
                int p = edge[i].first;
                int q = edge[i].second.first;
                if(join(p, q)) {
                        MST.push_back(make_pair(p, make_pair(q, edge[i].second.second)));
                }
        }
}

void proceesed() {
        input();
        init();
        kruskal();
        for(int i = 0; i < MST.size(); i++) {
                cout << "Canh: " <<  MST[i].first + 1 << " " << MST[i].second.first + 1 << " Trong so: " << MST[i].second.second << endl;
        }
}

int main() {
        proceesed();
        return 0;
}
