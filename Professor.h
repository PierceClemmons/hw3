//
// Created by pacle on 11/17/2021.
//

#ifndef UNTITLED_PROFESSOR_H
#define UNTITLED_PROFESSOR_H

#include <string>
using namespace std;

class Professor {
public:
    Professor() = default;
    Professor(string setID, string setName, string setDept);

    string id;
    string name;
    string department;
};


#endif //UNTITLED_PROFESSOR_H
