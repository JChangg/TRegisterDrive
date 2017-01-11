#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <fstream>
#include <iostream>
#include "settings.h"

using namespace std;

class Person
{
public:
    int id;
    int card_id;
    string f_name;
    string l_name;
    string type;
    bool loaded;
    Person();
    Person(int id, string f_name, string l_name, string type, int card_id);
    static Person load(int card_id);
};
#endif // PERSON_H
