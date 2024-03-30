#include <vector>

 using namespace std;
 
 struct parint {int prim, seg;};

 parint max_min1(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
    el segundo componente del resultado es el valor minimo de v */
 {
     parint r;
     int max = v[0], min = v[0];
     for (int i = 1; i < v.size(); i++)
     {
         if (v[i] > max) max = v[i];
         else if (v[i] < min) min = v[i];
     }
     r.prim = max;
     r.seg = min;
     return r;
 }
 
 pair<int,int> max_min2(const vector<int>& v)
 /* Pre: v.size()>0 */
 /* Post: el primer componente del resultado es el valor maximo de v;
 el segundo componente del resultado es el valor minimo de v */
 {

     pair<int ,int> r;
     int max = v[0], min = v[0];
     for (int i = 1; i < v.size(); i++)
     {
         if (v[i] > max) max = v[i];
         else if (v[i] < min) min = v[i];
     }
     r.first = max;
     r.second = min;
     return r;
 }
 
 
 void max_min3(const vector<int>& v, int& x, int& y)
 /* Pre: v.size()>0 */
 /* Post: x es el valor maximo de v;  y es el valor minimo de v */
 {
     int max = v[0], min = v[0];
     for (int i = 1; i < v.size(); i++)
     {
         if (v[i] > max) max = v[i];
         else if (v[i] < min) min = v[i];
     }
     x=max;
     y=min;
 }


 