/*  INF3105 - Structures de données et algorithmes
 *  UQAM / Département d'informatique / TP3
 *
 *  Vos noms + codes permanents :
 *   - Noah Lukaba Ndogosa (NDON17109603)
 *   - Imane AHMED ROBLEH (AHMI74560202)
 */

#include <cstdio>
#include <iostream>
#include <limits>
#include <math.h>
#include <queue>
#include <sstream>
#include "carte.h"
#include <tuple>

#include <fstream>
#include <algorithm>
#include <map>
#include <string>
#include <cctype>

using namespace std;

istream& operator >> (istream& is, Carte& carte) {return is;}


void Carte::addSiteToGraph(const std::string& site) {
    graph.ajouterSommet(site);

}


Carte Carte::readFromFile(const std::string& filename, Carte& carte) { // O(n)
    std::ifstream file(filename);
    string site, from, to, street, separator;
    int cost;

    if (!file.is_open()) {
        cerr << "Error opening file!" << endl;
        exit(EXIT_FAILURE);
    }
    
    while (file) {
        file >> site;
        if (site == "---")
            break;

        carte.addSiteToGraph(site);
    }
    carte.graph.printSommet();

    while (file) {
        file >> street;
        if (street == "---") 
            break;
        file 
        >> separator
        >> from
        >> to
        >> cost
        >> separator;

        carte.graph.addArc(street, from, to, cost);
    }
    file.close();
    return carte;
}

void Carte::calculateMST() const {
    this->graph.minSpanningTree(this->graph.getFistVertex());
}

