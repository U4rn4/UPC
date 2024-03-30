#include "evaluate.hh"
#include "utils.hh"

// Pre:  t és un arbre no buit que representa una expressió correcta
//       sobre naturals i variables enteres, i els operadors +,-,*.
    //       Totes les variables que apareixen a t estan definides a variable2value.
    //       Les operacions no produeixen errors d'overflow.
// Post: Retorna l'avaluació de l'expressió representada per t.
int evaluate(map<string,int> &variable2value, BinTree<string> t){
    if (isNumber(t.value()))
    {
        return mystoi(t.value());
    }
    else if (isVariable(t.value()))
    {
        return variable2value[t.value()];
    }
    else if (t.value()=="+")
    {
        return evaluate(variable2value, t.left()) + evaluate(variable2value, t.right());
    }
    else if (t.value()=="-")
    {
        return evaluate(variable2value, t.left()) - evaluate(variable2value, t.right());
    }
    else if (t.value()=="*")
    {
        return evaluate(variable2value, t.left()) * evaluate(variable2value, t.right());
    }
    else return 0;
}