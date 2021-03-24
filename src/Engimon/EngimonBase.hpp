#ifndef __ENGIMONBASE_HPP__
#define __ENGIMONBASE_HPP__

#include <vector>
#include <iostream>
#include "../Element.hpp"

using namespace std;

class EngimonBase {
    private:
        static int numOfCreated;
        const int engimon_id;
        string engimon_name;

        string * engimon_parents;   // always either 2 parents or 0, aman jika menggunakan array statik
        vector<Element> engimon_elements;

        int level, exp, cum_exp;
    
    public:
        //Constructors
        EngimonBase();
        EngimonBase(string name, string * parents, vector<Element> elements, int _level, int _exp, int _cum_exp);
        EngimonBase(const EngimonBase&);

        //Destructor
        ~EngimonBase();

        //Getter
        int get_engimon_id();
        string get_engimon_name();
        string * get_engimon_parents();
        vector<Element> get_engimon_elements();

        int get_level();
        int get_exp();
        int get_cum_exp();

        //Setter
        void set_engimon_name(string);
        void set_engimon_parents(string *);
        void set_engimon_elements(vector<Element>);
        void set_level(int);
        void set_exp(int);
        void set_cum_exp(int);

        //Additional Methods
        void add_exp(int);
};

#endif


