#pragma once
#include <iostream>

struct weightedEdge {
    weightedEdge () {};
    weightedEdge(const std::string& n,  //
                const std::string& f,   //
                const std::string& t,   //
                const int& w) : name(n), from(f), to(t), weight(w) {}
    std::string name;
    std::string from;
    std::string to;
    int weight;

    weightedEdge operator= (const weightedEdge& other) {
        // no verification done if this == other in which would return null;
        this->name = other.name;
        this->from = other.from;
        this->to = other.to;
        this->weight = other.weight;

        return *this;
    }

    // Define comparison operator <
    bool operator<(const weightedEdge& other) const {
        // Compare weights
        if (this->weight != other.weight) {
            return this->weight < other.weight;
        }
        
        // If weights are equal, compare starting nodes
        if (this->from != other.from) {
            return this->from < other.from;
        }

        return this->to < other.to;
    }

    bool operator>(const weightedEdge& other) const {
        if (this->weight != other.weight) {
            return this->weight > other.weight;
        }
        if (from != other.from) {
            return this->from > other.from;
        }
        return this->to > other.to;
    }
};