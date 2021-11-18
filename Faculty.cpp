//
// Created by pacle on 11/17/2021.
//

#include "Faculty.h"

// Create a new set of profs for a vector containing department ID's
Faculty *Faculty::createPartitionForDepartment(const vector<string>& departments)
{
    auto newFaculty = new Faculty;

    for(auto & department : departments)
    {   for (auto & allProfessor : allProfessors)
        {   if (allProfessor.second->department == department)
            {
                newFaculty->addProfessor(allProfessor.second);
            }
        }
    }

    return newFaculty;
}

// Union two sets into a new set
Faculty *Faculty::unionSet(const Faculty& setB)
{
    auto newFaculty = new Faculty;

    for (auto & y : setB.allProfessors)
    {
        newFaculty->addProfessor(y.second);
    }

    for (auto & x : allProfessors)
    {   for (auto & y : setB.allProfessors)
        {   if (x.first != y.first)
            {
                newFaculty->addProfessor(y.second);
            }
        }
    }
    return newFaculty;
}

// Check if this Faculty is a subset of target faculty
bool Faculty::isASubsetOf(Faculty setB)
{
    for (auto & x : allProfessors)
    {   if (!setB.contains(*x.second))
        {
            return false;
        }
    }
    return true;
}

bool Faculty::contains(Professor prof)
{
    for (auto & x : allProfessors)
    {
        if (x.second->department == prof.department)
        {   if (x.second->id == prof.id)
            {   if (x.second->name == prof.name)
                {
                    return true;
                }
            }
        }
    }
    return false;
}

Faculty *Faculty::intersection(Faculty setB) {
    auto newFaculty = new Faculty;

    for (auto & x : allProfessors)
    {   if (!setB.contains(*x.second))
        {
            newFaculty->addProfessor(x.second);
        }
    }

    return newFaculty;
}
