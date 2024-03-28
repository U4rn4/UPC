#include<vector>
#include<cmath>
#include<iostream>
using namespace std;
void PrDoubl(double d) {
    if (abs(d) < 1e-7)
        cout << 0.0;
    else
        cout << d;
}

struct Point{
    double x, y, z;
};

struct Particle {
    Point p,v;
    double m;
};

void PrPart(Point c) {
    PrDoubl(c.x);
    cout << " ";
    PrDoubl(c.y);
    cout << " ";
    PrDoubl(c.z);
    cout << "\n";
}

Point sum(Point p1, Point p2) {
Point res;
res.x = p1.x + p2.x;
res.y = p1.y + p2.y;
res.z = p1.z + p2.z;
return res;
};

Point mul(double a, Point p) {
Point res;
res.x = a*p.x;
res.y = a*p.y;
res.z = a*p.z;
return res;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.setf(ios::fixed);
    cout.precision(5);
    int n, k;
    while (cin >> n >> k) {
        ++k;
        vector< vector<Particle> > Particula(n, vector<Particle>(k));
        int sumaMasa = 0;
        for (int i = 0; i < n; i++) {
            cin >> Particula[i][0].p.x >> Particula[i][0].p.y >> Particula[i][0].p.z;
            cin >> Particula[i][0].v.x >> Particula[i][0].v.y >> Particula[i][0].v.z;
            cin >> Particula[i][0].m;
            sumaMasa += Particula[i][0].m;
        }
        double t = 0;
        for (int j = 1; j < k; ++j) {
            cin >> t;
            Point CofM;
            CofM.x = 0;
            CofM.y = 0;
            CofM.z = 0;
            for (int i = 0; i < n; ++i) {
                Particula[i][j].p = sum(Particula[i][j-1].p, mul(t, Particula[i][0].v));
                CofM = sum(CofM, (mul(Particula[i][0].m, Particula[i][j].p)));
            }
            CofM = mul((1.0/sumaMasa), CofM);
            PrPart(CofM);
        } --k;
        for (int i = 0; i < n; ++i) PrPart(Particula[i][k].p);
        cout << "\n";
    }
}
