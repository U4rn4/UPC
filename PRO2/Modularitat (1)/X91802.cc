#include "Estudiant.hh"
#include <vector>

using namespace std;

pair<int,int>  max_min_vest(const vector<Estudiant>& v){
    int imx=-1, imn=-1;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i].te_nota())
        {
            if (imx==-1){
                imx=imn=i;
            }
            else
            {
                v[i].consultar_nota();
                if(v[i].consultar_nota()>v[imx].consultar_nota()) {
                    imx=i;
                }
                else if (v[imx].consultar_nota()==v[i].consultar_nota())
                {
                    if(v[imx].consultar_DNI()>v[i].consultar_DNI()) imx = i;
                }

                if(v[i].consultar_nota()<v[imn].consultar_nota()) {
                    imn=i;
                }
                else if (v[imn].consultar_nota()==v[i].consultar_nota())
                {
                    if(v[imn].consultar_DNI()>v[i].consultar_DNI()) imn = i;
                }
            }
            
            
            
        } 
    }
    return make_pair(imx, imn);
}
 /* Pre: v no conte repeticions de dni  */
 /* Post: si existeix a v algun estudiant amb nota, la primera component del
    resultat es la posicio de l'estudiant de nota maxima de v i la segona
    component es la posicio de l'estudiant de nota minima de v (si hi ha
    empats, s'obte en cada cas la posicio de l'estudiant amb minim DNI); si no
    hi ha cap estudiant amb nota, totes dues components valen -1 */