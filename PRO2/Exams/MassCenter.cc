#include<iostream>
#include<vector>
using namespace std;

void printDouble(double d)
{
    if (d < 1e-7 and d > -1e-7)
        cout << 0.0;
    else
        cout << d;
}

struct Point {
    double x, y, z;
};

struct Particle {
    Point p,v;
    double m;
};

typedef vector<Particle> Vec;

Point sum(Point p1, Point p2)
{
    Point result;
    result.x = p1.x + p2.x;
    result.y = p1.y + p2.y;
    result.z = p1.z + p2.z;
    return result;
}

Point mul(double a, Point p)
{
    Point result;
    result.x = a*p.x;
    result.y = a*p.y;
    result.z = a*p.z;
    return result;
}

Particle CalcCofM(Vec& particles, int n)
{
    Particle CofM;
    Point position;
    Point velocity;
    position.x = position.y = position.z = 0.0;
    velocity.x = velocity.y = velocity.z = 0.0;
    double TMass = 0.0;
    
    for(int i = 0; i < n; ++i)
    {
        TMass += particles[i].m;

        position = sum(mul(particles[i].m, particles[i].p), position);
        velocity = sum(mul(particles[i].m, particles[i].v), velocity);
    }
    TMass = 1/TMass;
    position = mul(TMass, position);
    velocity = mul(TMass, velocity);

    
    CofM.p = position;
    CofM.v = velocity;
    CofM.m = 0.0; 
    return CofM;
}

void moveCofMAndPr(Particle& part, double t)
{
    part.p = sum(mul(t, part.v), part.p);

    printDouble(part.p.x);
    cout << ' ';
    printDouble(part.p.y);
    cout << ' ';
    printDouble(part.p.z);
    cout << '\n';
}


void moveAllParticlesAndPrint(Vec& particles, int n, double t)
{
    for(int i = 0; i < n; ++i)
    {
        particles[i].p = sum(mul(t, particles[i].v), particles[i].p); 

        printDouble(particles[i].p.x);
        cout << ' ';
        printDouble(particles[i].p.y);
        cout << ' ';
        printDouble(particles[i].p.z);
        cout << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);    
    cout.setf(ios::fixed);
    cout.precision(5);

    int n, k;
    while(cin >> n >> k)
    {
        Vec particles(n);
        for(int i = 0; i < n; ++i)
        {
            Particle load;
            cin >> load.p.x >> load.p.y >> load.p.z >> load.v.x >> load.v.y >> load.v.z >> load.m;
            particles[i] = load;
        }
        
        Particle CofM = CalcCofM(particles, n); 
        int total_time = 0;
        for(int i = 0; i < k; ++i)
        {
            int t;
            cin >> t;
            total_time += t;
            moveCofMAndPr(CofM, t);
        }
        
        moveAllParticlesAndPrint(particles, n, total_time);

        cout << '\n';
    }
}