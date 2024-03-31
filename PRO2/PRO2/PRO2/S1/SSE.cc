#include <iostream>

using namespace std;

int main()
{
    int n, x, v, s=0;
    string a;
    cin >> n >> x;
    for (int i = 1; i <= n; i++)
    {
        while (cin >> v)
        {
            if (v == x)
            {
                getline(cin,a);
                break;
            }
            else s += v;
        }
        cout << "La suma de la secuencia " << i << " es " << s << endl;
        s = 0;
    }
    
}
