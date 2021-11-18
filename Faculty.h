//
// Created by pacle on 11/17/2021.
//

#ifndef UNTITLED_FACULTY_H
#define UNTITLED_FACULTY_H

#include <string>
#include <vector>
#include <map>
#include "Professor.h"
using namespace std;

class Faculty
{
public:
    map<string, Professor*> allProfessors;

    Faculty() = default;

    void addProfessor(Professor* p)
    {
        this->allProfessors.insert(pair<string, Professor*>(p->id, p));
    }

    bool contains(Professor prof);
    Faculty* unionSet(const Faculty& setB);
    Faculty* intersection(Faculty setB);
    Faculty* difference(Faculty setB) {};
    Faculty* createPartitionForDepartment(const vector<string>& departments) ;
    bool isASubsetOf(Faculty setB);
    Faculty complement(Faculty allFaculty) {};
    int cardinality() {};

    bool isEqualTo(Faculty setB)
    {
        return this->isASubsetOf(setB) && setB.isASubsetOf(*this);
    }
};


#endif //UNTITLED_FACULTY_H
