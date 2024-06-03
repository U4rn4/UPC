#include <iostream>
#include <string>
#include <cstdlib>
//...
#include <vector>

using namespace std;


#include "BinTree.hh"

int getIdVar(string s)
{
 return atoi(s.substr(1).c_str());
}

int siz(BinTree<int> bin){
    if (bin.empty())
    {
        return 0;
    }

    return 1 + siz(bin.left()) + siz(bin.right());
}

int suma(const BinTree<int> bin){
    if (bin.empty())
    {
        return 0;
    }
    else return suma(bin.left()) + suma(bin.right()) + bin.value();
    
}

typedef struct t
{
    int sitot=0;
    int sutot=0;
    int sil=0;
    int sir=0;
    int sul=0;
    int sur=0;
};


int main()
{
 //...
 string s1, s2, s3, s4, s5, s6, s7;
 int numvars;
 cin >> s1 >> numvars >> s2;
 vector<BinTree<int>> v(numvars, BinTree<int>());
 vector<t> v2(numvars);
 while (cin >> s1 >> s2) {
  if (s1[0] == 't') {
   int idvar = getIdVar(s1);
   if (s2 == "=BinTree(") {
    int value;
    cin >> value >> s3 >> s4 >> s5 >> s6 >> s7;
    int idvar1 = getIdVar(s4);
    int idvar2 = getIdVar(s6);
    v[idvar] = BinTree<int>(value,v[idvar1],v[idvar2]);

    v2[idvar].sil = v2[idvar1].sitot;
    v2[idvar].sir = v2[idvar2].sitot;
    v2[idvar].sitot = v2[idvar1].sitot + v2[idvar2].sitot + 1;


    v2[idvar].sul = v2[idvar1].sutot;
    v2[idvar].sur = v2[idvar2].sutot;
    v2[idvar].sutot = v2[idvar1].sutot + v2[idvar2].sutot + value;

   } else if (s2 == "=") {
    cin >> s3 >> s4;
    int idvar1 = getIdVar(s3);
    if (s4 == ".left();") {
     v[idvar] = v[idvar1].left();
     v2[idvar].sitot = v2[idvar1].sil +1;
    } else {
     v[idvar] = v[idvar1].right();
    }
   }
  } else if (s1 == "cout<<") {
   int idvar = getIdVar(s2);
   cin >> s3;
   v[idvar].setOutputFormat(BinTree<int>::INLINEFORMAT);
   cout << v[idvar] << endl;

  } else if (s1 == "cout<<size(") {
   int idvar = getIdVar(s2);
   cin >> s3;
   cout << siz(v[idvar]) << endl;
  } else if (s1 == "cout<<sum(") {
   int idvar = getIdVar(s2);
   cin >> s3;
   cout << suma(v[idvar]) << endl;
  }
 }
}
