#ifndef __ENGIMON_HPP__
#define __ENGIMON_HPP__

#include <vector>
#include <iostream>
#include "../Skill.hpp"
#include "EngimonBase.hpp"

using namespace std;

class Engimon : public EngimonBase {
    private:
        string species_name;
        vector<Skill> engimon_skills;

    public:
        //Constructor
        Engimon() : EngimonBase() {
            species_name = "-";
            engimon_skills.push_back("Tackle"); //ubah argumen string menjadi skill
        }

        Engimon(string name, string * parents, vector<string> elements, int _level, int _exp, int _cum_exp, string species, vector<Skill> skills) : EngimonBase(name, parents, elements, _level, _exp, _cum_exp) {
            species_name = species;
            engimon_skills = skills;
        }

        Engimon(const Engimon& other) : EngimonBase(other) {
            species_name = other.species_name;
            engimon_skills = other.engimon_skills;
        }

        //Destructor
        ~Engimon() : ~EngimonBase() {
            ~engimon_skills;
        }

        //Getter
        string get_species_name() { return species_name; }
        vector<Skill> get_engimon_skills() { return engimon_skills; }

        //Setter
        void set_species_name(string species) { species_name = species; }
        void set_engimon_skills(vector<Skill> skills) { engimon_skills = skills; }

        //Additional methods
        void add_skill(Skill skill) {
            if (engimon_skills.size < 4)
            {
                engimon_skills.push_back(skill);
            } else
            {
                throw "skill full"; //Mungkin penanganan catch-nya diarahkan ke prosedur change_skill
            }
        }

        //Prekondisi skill engimon sudah 4 (penuh)
        void change_skill(Skill skill, Skill * replaced) {
            for (int i = 0; i < 4; i++) {
                if (engimon_skills.at(i) == *replaced)
                {
                    engimon_skills.at(i) = skill;
                    return;
                }
            }

            throw "No such skill";
        }

};

#endif