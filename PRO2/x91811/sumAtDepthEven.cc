#include "sumAtDepthEven.hh"
#include <vector>


// Pre:
// Post: Retorna la suma dels valors de t a profunditat parell
int sumAtDepthEven(BinTree<int> t){
    
    if (t.empty())
    {
        return 0;
    }
    int sum = t.value();

    if (!t.left().empty())
    {
        sum += sumAtDepthEven(t.left().left()) + sumAtDepthEven(t.left().right());
    }
    if (!t.right().empty())
    {
        sum += sumAtDepthEven(t.right().left()) + sumAtDepthEven(t.right().right());

    }
    return sum;
}
