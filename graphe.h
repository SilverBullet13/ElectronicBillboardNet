/*  INF3105 - Structures de données et algorithmes
    Lab 11 -- Graphes / Représentations et algorithmes de base
    http://ericbeaudry.uqam.ca/INF3105/lab11/
*/

#pragma once
#include <iostream>
#include <map>
#include <set>
#include <queue>
#include <assert.h>
#include "weightedEdge.h"
#include "iomanip"


// Le type S est le symbole pour identifier un sommet
template <class S>
class Graphe{
  public:
    // Interface public pour créer le graphe.
    void ajouterSommet(const S& s);
    void ajouterAreteOrientee(const S& s1, const S& s2);
    void ajouterAreteNonOrientee(const S& s1, const S& s2);

    // Interface public pour les requêtes de base.
    // Amélioration possible : retourner le résultat au lieu de faire l'affichage à l'interne.
    void parcoursRechercheProfondeurRec(const S& s);
    void parcoursRechercheProfondeur(const S& s);
    void parcoursRechercheLargueur(const S& s);
    void extraireComposantesConnexes() const;
    void printSommet() const;
    void printVoisin(const S&) const;
    void printAllVoisin() const;
    void addArc(const S&, S&, S&, int&);
    void printArcsForNode(const S& s) const;
    void printAllArcs() const;
    //auto primJarnik(const std::string& startNode) const;
    void minSpanningTree(const std::string& startNode) const;
    S getFistVertex() const;
    
    


  private:
    struct Sommet{
        // À compléter.
        Sommet() {};
        mutable bool visited;
        std::set<S> voisins; // ensemble des sommets accessibles via les arêtes sortantes du sommet.
                        // Cela est légèrement différent de la page 128 des notes de cours.
                        // C'est voulu, car ici les arêtes ne sont pas étiquetées par un poids (ex: distance).
                        // Pour attacher une étiquette, il suffirait de modifier pour : map<S, A> sortants;
        std::map<S, weightedEdge> arcs;
    };
    std::map<S, Sommet> sommets; // identification --> sommet a: {b,c}
    auto primJarnik(const std::string& startNode) const;
};

template <class S>
void Graphe<S>::ajouterSommet(const S& s){
    // À compléter
   //this->sommets[s] = Sommet{};
   //assert(!this->sommets.find(s));
   if (this->sommets.end() == this->sommets.find(s)) // dont include if object already exists
        this->sommets[s];
}

template <class S>
void Graphe<S>::ajouterAreteNonOrientee(const S& s1, const S& s2){
    // À compléter.
    // Doit ajouter les 2 arêtes orientées : s1->s2 et s2->s1;
    this->ajouterAreteOrientee(s1,s2);
    this->ajouterAreteOrientee(s2,s1);
}

template <class S>
void Graphe<S>::ajouterAreteOrientee(const S& s1, const S& s2){
    // À compléter.
    // Doit uniquement ajouter s1->s2.
    //std::cout << "add arc between : " << s1 << " and " <<  s2 << std::endl;
    assert(this->sommets.contains(s1));
    assert(this->sommets.contains(s2));
    this->sommets[s1].voisins.insert(s2);
}

template <class S>
void Graphe<S>::parcoursRechercheProfondeurRec(const S& s) {
    // À compléter.
    // Vous devrez implémenter des marqueurs «visité» sur les sommets.
    // voir le noued le plus loin avant 
    // Use Pile 
    assert(this->sommets.contains(s));
    this->sommets[s].visited = true;
    std::cout << s << " " << std::endl;
    for (const S &voisin : this->sommets[s].voisins) {
        if (!this->sommets[voisin].visited) {
            this->parcoursRechercheProfondeur(voisin);
            std::cout << voisin << std::endl;
        }
    }
    //clean up
    // for (auto &[nom, sommet] : this->sommets)
}

template <class S>
void Graphe<S>::parcoursRechercheProfondeur(const S& s) {
    this->parcoursRechercheProfondeurRec(s);
    
    //clean up
    std::cout << std::endl;
    for (auto &[nom, sommet] : this->sommets) 
        sommet.visited = false;
} 

template <class S>
void Graphe<S>::parcoursRechercheLargueur(const S& s) {
    // À compléter.
    // Vous devrez implémenter des marqueurs «visité» sur les sommets.
    // Il est recommendé d'utiliser la file std::queue de la bibliothèque standard de C++.
    // Voir : http://en.cppreference.com/w/cpp/container/queue
    // Use file 
    std::queue<S> q;
    //this->sommets[s].visited = true;
    std::set<S> visited { s } ; //says which one has been visited
    q.push(s);
    while (!q.empty()) {
        S current  = q.front();
        q.pop();

        for (const S& voisin : this->sommets[current].voisins) {
            if (!visited.contains(voisin)) {
                visited.insert(voisin);
                q.push(voisin);
            }
        }
    }
}
template <class S>
void Graphe<S>::extraireComposantesConnexes() const{
    // À compléter.
    // Ne faites que l'extraction simple en premier (plus simple que l'extraction de composantes *fortement* connexes).
}
template <class S>
void Graphe<S>::printSommet() const {
    for (const auto& key : this->sommets)
        std::cout << key.first << std::endl;
}

template <class S>
void Graphe<S>::printVoisin(const S& s) const {

    // add assert here to verify if the node exists before
    auto it = this->sommets.find(s);
    if (it != this->sommets.end()) {
        std::cout << s << " : {";
        const auto& voisins = it->second.voisins;
        for (auto it = voisins.begin(); it != voisins.end(); it++) {
            std::cout << *it;
            if (std::next(it) != voisins.end()) {
                std::cout << ",";
            }
        }
        std::cout << "}" << std::endl;
    }
}

template <class S>
void Graphe<S>::printAllVoisin() const {
    for (const auto& pair : this->sommets){
        const S& sommet = pair.first;
        printVoisin(sommet);    
    }
}

template <class S>
void Graphe<S>::addArc(const S& street, S& s1, S& s2, int& weight) {
    ajouterAreteNonOrientee(s1,s2);
    weightedEdge arc1(street, s1, s2, weight);
    weightedEdge arc2(street, s2, s1, weight);

    this->sommets.at(s1).arcs[s2] = arc1;
    this->sommets.at(s2).arcs[s1] = arc2;
}

template <class S>
void Graphe<S>::printArcsForNode(const S& s) const {
    auto itSommet = this->sommets.find(s);
    if (itSommet != this->sommets.end()) {
        const auto& arcs = itSommet->second.arcs;
        for (auto itArcs = arcs.begin(); itArcs != arcs.end(); itArcs++) {
            //std::cout << *itArcs << std::end;
            const weightedEdge& arc = itArcs->second; //get the current arc
            std::cout
            << arc.name << '\t'
            << arc.from << std::setw(6)
            << arc.to   << std::setw(6)
            << arc.weight
            << std::endl;
        }
    }
 }

template <class S>
void Graphe<S>::printAllArcs() const { 
    for (const auto& pair : this->sommets){
        const S& sommet = pair.first;
        printArcsForNode(sommet);
        
    }
}

template <class S> 
auto Graphe<S>::primJarnik(const std::string& startNode)const {
    //lambda function for comparisions
    auto compareWENames = [](const std::string& lhs, const std::string& rhs) {
        return lhs < rhs;
    };
    // Initialise minimum spanning tree with lambda function
    std::map<std::string, weightedEdge, decltype(compareWENames)> mst(compareWENames);
    
    // Initialise a minimum priority queue
    std::priority_queue<weightedEdge, std::vector<weightedEdge>, std::greater<weightedEdge>> pq;
    
    // Set to store visited nodes
    std::set<std::string> visited;

    // Add start node to visited set
    visited.insert(startNode);
    
    // Add arcs of the current vertex
    for (const auto& arc : this->sommets.at(startNode).arcs) {
        pq.push(arc.second);
    }

    // Main loop of Prim-Jarnik algorithm
    while (!pq.empty()) {
        // Extract the minimum weight edge from priority queue
        auto currentEdge = pq.top();
        pq.pop();

        // Get the destination vertex of the current edge
        const std::string& currentVertex = currentEdge.to;

        // Check if the destination vertex is already visited
        if (visited.find(currentVertex) != visited.end()) {
            continue; // Skip this edge if the vertex is already visited
        }

        // Add the edge to the minimum spanning tree
        mst[currentEdge.from+currentEdge.to] = currentEdge;

        // // Mark the current vertex as visited
        visited.insert(currentVertex);
      
        // // Add all edges from the current vertex to the priority queue
        for (const auto& arc : this->sommets.at(currentVertex).arcs) {
            if (visited.find(arc.second.to) == visited.end()) {
                pq.push(arc.second);
            }
        }
    }
    // Return the minimum spanning tree
    return mst;
}

template <class S> 
void  Graphe<S>::minSpanningTree(const std::string& startNode) const {
    auto minSpanningTree = primJarnik(startNode);

    for (const auto& [node, arc] : minSpanningTree) {
        std::cout << arc.name << '\t' << arc.from << '\t' << arc.to << '\t' << arc.weight << std::endl;
    }
    std::cout << "---" << std::endl;

    // Calculate and print the total weight of the minimum spanning tree
    int totalWeight = 0;
    for (const auto& [node, arc] : minSpanningTree) {
        totalWeight += arc.weight;
    }
    std::cout << totalWeight << std::endl;
}

template <class S>
S Graphe<S>::getFistVertex() const{ 
    auto it = this->sommets.begin();
    return it->first;
}