/*  INF3105 - Structures de données et algorithmes
 *  UQAM / Département d'informatique / TP3
 *
 *  Vos noms + codes permanents :
 *   - Noah Lukaba Ndogosa (NDON17109603)
 *   - Imane AHMED ROBLEH (AHMI74560202)
 */

#pragma once
#include <cassert>
#include <istream>
#include <string>
#include "graphe.h"


#include <vector>
#include <queue>
#include "weightedEdge.h"

using namespace std;

class Carte{
  public:

  void addSiteToGraph(const std::string& site);
  Carte readFromFile(const std::string& filename, Carte& carte);
  void calculateMST() const; // Cette méthode retourne le coût total et affiche aussi l'ARM
                              // Utilise prim jarnik

  private:
  Graphe <string> graph;
  friend istream& operator >> (istream& is, Carte&);
};


