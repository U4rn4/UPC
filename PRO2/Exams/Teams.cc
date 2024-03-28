#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Programador {
   string nombre;
   int skill;
};

void Read_mems(vector<Programador>& v, int l){
   for (int i = 0; i < l; ++i) {
      cin >> v[i].nombre >> v[i].skill;
   }
}

bool orden_l(Programador a, Programador b) {
   return a.nombre < b.nombre;
}

bool btr_prog(Programador a, Programador b, int a_counter, int b_counter) {
   if (a.skill != b.skill) return a.skill > b.skill;
   else if (a_counter != b_counter) return a_counter < b_counter; 
   else return a.nombre < b.nombre;
}

int main() {
   int k;
   while (cin >> k) {

      int n_i, n_p;
      
      cin >> n_i; 
      vector<Programador> i_list(n_i);
      Read_mems(i_list, n_i);
      
      cin >> n_p; 
      vector<Programador> p_list(n_p);
      Read_mems(p_list, n_p);

      vector <vector<Programador> > teams((n_i+n_p)/k, vector<Programador>(k));
      int i_index = 0, p_index = 0;
      for (int i = 0; i < (n_i+n_p)/k; ++i) {
         int i_mem = 0, p_mem = 0;
         for (int j = 0; j < k; ++j) {
            if (not(p_index < n_p) or (i_index < n_i and btr_prog(i_list[i_index], p_list[p_index], i_mem, p_mem))) {
               teams[i][j] = i_list[i_index];
               ++i_index;
               ++i_mem;
            } else {
               teams[i][j] = p_list[p_index];
               ++p_index;
               ++p_mem;
            }
         }
      }

      for (int i = 0; i < (n_i+n_p)/k; ++i) {
         sort(teams[i].begin(), teams[i].end(), orden_l);
         for (int j = 0; j < k; ++j) {
            cout << teams[i][j].nombre;
            if (j < k - 1) cout << ' ';
         }
         cout << endl;
      }
      cout << endl;
   }
}