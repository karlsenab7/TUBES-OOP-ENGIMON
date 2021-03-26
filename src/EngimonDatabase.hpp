#ifndef __ENGIMONDATABASE_HPP__
#define __ENGIMONDATABASE_HPP__

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Engimon.hpp"

using namespace std;

class EngimonDatabase {
    private:
        vector<Engimon> engimon_database;

    public:
        EngimonDatabase() {
            string spec_name;
            string elmt_temp;
            vector<Element> elmt_list;
            string skill_id;
            string skill_name;
            string skill_power;
            int power;
            string skill_elmt_str;
            vector<Element> skill_elmt; 
            string skill_desc;
            vector<Skill> skills_list;
            stringstream ss;

            string namafile = "Engimons.txt";
            ifstream ReadFile(namafile.c_str());
            int i = 1;
            while (getline(ReadFile, spec_name, ',') && !ReadFile.eof())
            {
                getline(ReadFile, elmt_temp, ',');
                ss << elmt_temp;
                while (getline(ss, elmt_temp, '/')) 
                {
                    elmt_list.push_back(Element(elmt_temp));
                }
                ss.clear();

                getline(ReadFile,skill_id, ',');
                getline(ReadFile,skill_name, ',');
                getline(ReadFile,skill_power, ',');
                ss << skill_power;
                ss >> power;
                getline(ReadFile,skill_elmt_str, ',');
                skill_elmt.push_back(Element(skill_elmt_str));
                getline(ReadFile,skill_desc, '\n');

                Skill skill = Skill(skill_id, skill_name, skill_elmt, power, skill_desc, true, spec_name);
                skills_list.push_back(skill);
                string parents[2] = {"None", "None"};
                
                Engimon engimon = Engimon("-", parents, elmt_list, 1, 0, 0, spec_name, parents, skills_list);
                engimon.set_id(i);
                engimon_database.push_back(engimon);
                skills_list.clear();
                elmt_list.clear();
                ss.clear();
                i++;
            }

            ReadFile.close();
        }

        Engimon get_engimon_by_idx(int idx)
        {
            Engimon a = Engimon(engimon_database[idx]);
            return a;
        }

        Engimon get_engimon_by_species(string species)
        {
            for (int i = 0; i < engimon_database.size(); i++) {
                if (species == engimon_database[i].get_species_name())
                {
                    Engimon a = Engimon(engimon_database[i]);
                    return a;
                }
            }
        }

        Engimon get_engimon_by_element(vector<Element> elements)
        {
            vector<Element> engimon_elmt;

            if (elements.size() == 2)
            {
                
                for (int i = 0; i < engimon_database.size(); i++) {
                    engimon_elmt = engimon_database[i].get_engimon_elements();
                    if (elements[0] == engimon_elmt[0] && elements[1] == engimon_elmt[1])
                    {
                        Engimon a = Engimon(engimon_database[i]);
                        return a;
                    }
                }
            }

            for (int i = 0; i < engimon_database.size(); i++) {
                engimon_elmt = engimon_database[i].get_engimon_elements();
                if (elements[0] == engimon_elmt[0] && engimon_elmt.size() == 1)
                {
                    Engimon a = Engimon(engimon_database[i]);
                    return a;
                }
            }

            throw "No engimon with that element";
        }

        int randomizer(int lower, int higher)
        {
            srand(time(NULL));
            return rand() % higher + lower;
        }
        Engimon get_random_engimon()
        {
            int random = randomizer(0, engimon_database.size()-1);
            Engimon ret = engimon_database[random];

            random = randomizer(100, 3200);
            ret.add_exp(random);

            return ret;
        }

        int get_idx_random_engimon_by_element(Element el)
        {
            Engimon e;
            bool found = false;
            while(!found)
            {
                Engimon e = get_random_engimon();

                if (e.get_engimon_elements()[0] == el)
                    found = true;
            }

            return e.get_engimon_id()-1;
        }
        
        int get_database_size()
        {
            return engimon_database.size();
        }

};

#endif
