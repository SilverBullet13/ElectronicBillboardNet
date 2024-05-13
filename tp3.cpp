/*  INF3105 - Structures de données et algorithmes
    UQAM / Département d'informatique, TP3
*/

#include <fstream>
#include <iostream>
#include <string>
#include <math.h>
#include "carte.h"

using namespace std;

void tp3(Carte& carte){
}

int main(int argc, const char** argv)
{
  
    if(argc!=2){
        cout << "Syntaxe: ./tp3 exemple.txt" << endl;
        return 1;
    }

    Carte carte;
    carte = carte.readFromFile(argv[1], carte);
    carte.calculateMST();



    return 0;
}
