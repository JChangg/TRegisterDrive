#include "person.h"

using namespace std;

Person::Person() : loaded(false)
{

}

Person::Person(int id, string f_name, string l_name, string type, int card_id)
    : id(id), f_name(f_name), l_name(l_name), type(type), card_id(card_id), loaded(true)
{

}

Person Person::load(int card_id)
{
    ifstream infile(__DATABASE_PATH__);
    if (!infile.is_open()) {
        cout << "unable to open file" << endl;
        exit(EXIT_FAILURE);
    }
    // fields listed in the same order as csv
    string f_name_str, l_name_str, type_str, card_id_str, id_str;
    while (infile.good())
    {
        getline(infile, f_name_str, ',');
        getline(infile, l_name_str, ',');
        getline(infile, type_str, ',');
        getline(infile, card_id_str, ',');
        getline(infile, id_str);
        cout << f_name_str << ", " << l_name_str << ", " << type_str << ", " << card_id_str << ", " << id_str << endl;
        if (to_string(card_id) == card_id_str)
        {
            infile.close();
            return Person(stoi(id_str), f_name_str, l_name_str, type_str, card_id);
        }
    }
    return Person();
}
