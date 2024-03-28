#include "numNegative.hh"
#include "utils.hh"

int calculate(BinTree<string> t, int& neg){
    if (t.empty())
    {
        return 0;
    }
    else if (isNumber(t.value()))
    {
        return mystoi(t.value());
    }
    else if (t.value()=="+")
    {
        int a = calculate(t.left(),neg) + calculate(t.right(),neg);
        if (a<0) neg++;
        return a;
    }
    else if (t.value()=="-")
    {
        int a = calculate(t.left(),neg) - calculate(t.right(),neg);
        if (a<0) neg++;
        return a;
    }
    else
    {    
        int a = calculate(t.left(),neg) * calculate(t.right(),neg);
        if (a<0) neg++;
        return a;
    }    
}

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre els naturals i els operadors +,-,*.
//       Les operacions no produeixen errors d'overflow.
// Post: Retorna el nombre de subexpressions de l'expressió representada per t
//       amb avaluació estrictament menor que 0.
int numNegative(BinTree<string> t){
    int neg=0;
    calculate(t, neg);
    return neg;
}