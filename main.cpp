#include <iostream>
#include "Professor.h"
#include "Faculty.h"

int main() {
    // Establish set of all faculty
    Faculty allFaculty;
    allFaculty.addProfessor(new Professor("123", "Christian Ayala", "CS"));
    allFaculty.addProfessor(new Professor("456", "Mark Fontenot", "CS"));
    allFaculty.addProfessor(new Professor("789", "Theodore Manikas", "CS"));
    allFaculty.addProfessor(new Professor("135", "Jennifer Dworak", "ECE"));
    allFaculty.addProfessor(new Professor("246", "Joseph Camp", "ECE"));
    allFaculty.addProfessor(new Professor("357", "Bruce Gnade", "ECE"));
    allFaculty.addProfessor(new Professor("468", "Elena Borzova", "ME"));
    allFaculty.addProfessor(new Professor("579", "Sheila Williams", "ME"));
    allFaculty.addProfessor(new Professor("680", "David Willis", "ME"));
    allFaculty.addProfessor(new Professor("987", "Joel Meyers", "PHYS"));
    allFaculty.addProfessor(new Professor("876", "Pavel Nadolsky", "PHYS"));
    allFaculty.addProfessor(new Professor("765", "Randall Scalise", "PHYS"));
    allFaculty.addProfessor(new Professor("654", "Andrew Quicksall", "ENGR"));
    allFaculty.addProfessor(new Professor("543", "Anna Puterbaugh", "ENGR"));
    allFaculty.addProfessor(new Professor("432", "John Fattaruso", "ENGR"));
    allFaculty.addProfessor(new Professor("321", "John Easton", "CEE"));
    allFaculty.addProfessor(new Professor("210", "Paul Krueger", "CEE"));
    allFaculty.addProfessor(new Professor("975", "Brett Story", "CEE"));
    allFaculty.addProfessor(new Professor("864", "Michael Hahsler", "EMIS"));
    allFaculty.addProfessor(new Professor("753", "Richard Barr", "EMIS"));
    allFaculty.addProfessor(new Professor("642", "Stephen Szygenda", "EMIS"));
    allFaculty.addProfessor(new Professor("531", "Andrea Adams", "CHEM"));
    allFaculty.addProfessor(new Professor("420", "Patty Wisian-Neilson", "CHEM"));
    allFaculty.addProfessor(new Professor("150", "Brian Zoltowski", "CHEM"));

    // Establish set A
    Faculty setA;
    vector<string> deptA;
    deptA.emplace_back("CS");
    deptA.emplace_back("ECE");
    deptA.emplace_back("PHYS");
    deptA.emplace_back("ENGR");
    setA = *allFaculty.createPartitionForDepartment(deptA);

    // Establish set B
    Faculty setB;
    vector<string> deptB;
    deptB.emplace_back("ME");
    deptB.emplace_back("ECE");
    deptB.emplace_back("CEE");
    deptB.emplace_back("ENGR");
    setB = *allFaculty.createPartitionForDepartment(deptB);

    // Establish set C
    Faculty setC;
    vector<string> deptC;
    deptC.emplace_back("EMIS");
    deptC.emplace_back("CEE");
    deptC.emplace_back("PHYS");
    deptC.emplace_back("ENGR");
    setC = *allFaculty.createPartitionForDepartment(deptC);

    /// A is a subset of A union B
    Faculty AuB;
    AuB = *setA.unionSet(setB);
    cout << "A is a subset of A union B: ";
    if (setA.isASubsetOf(AuB))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    /// A union B equals B union A
    Faculty BuA;
    BuA = *setB.unionSet(setA);
    cout << "A union B equals B union A: ";
    if (BuA.isASubsetOf(AuB))
    { if (AuB.isASubsetOf(BuA))
        {
            cout << "true" << endl;
        }
    }
    else
    {
        cout << "false" << endl;
    }

    /// Union of A and B intersect C equals intersect of A union B and A union C
    // LHS of equation
    Faculty BnC;
    Faculty AuBnC;
    BnC = *setB.intersection(setC);
    AuBnC = *setA.intersection(BnC);

    // RHS of equation
    Faculty AuC;
    Faculty AuCnAuB;
    AuC = *setA.unionSet(setC);
    AuCnAuB = *AuC.intersection(AuB);

    cout << "Union of A and B intersect C equals intersect of A union B and A union C: ";
    if (AuBnC.isASubsetOf(AuCnAuB))
    { if (AuCnAuB.isASubsetOf(AuBnC))
        {
            cout << "true" << endl;
        }
    }
    else
    {
        cout << "false" << endl;
    }
    return 0;
}