#ifndef __ENGIMON_HPP__
#define __ENGIMON_HPP__

#include <vector>
#include <iostream>
#include "Skill.hpp"
//#include "Skill.cpp"
#include "folderEngimon/EngimonBase.hpp"
//#include "folderEngimon/EngimonBase.cpp"
//#include "Breed.hpp"

using namespace std;

class Engimon : public EngimonBase {
    private:
        string species_name;
        vector<Skill> engimon_skills;

    public:
        //Constructor
        Engimon() : EngimonBase() {
            species_name = "-";

            // Maksudnya masukin skill default, perubahan mengikuti Skill.hpp
            int learnableBy[1] = {1};
            Skill ember = Skill("1", "Ember", "Fire", learnableBy, 10, "Default Skill", false, "-");
            engimon_skills.push_back(ember);
        }

        Engimon(string name, string * parents, vector<Element> elements, int _level, int _exp, int _cum_exp, string species, vector<Skill> skills) : EngimonBase(name, parents, elements, _level, _exp, _cum_exp) {
            species_name = species;
            engimon_skills = skills;
        }

        Engimon(const Engimon& other) : EngimonBase(other) {
            species_name = other.species_name;
            engimon_skills = other.engimon_skills;
        }

        //Destructor (mungkin bisa menggunakan destructor dari EngimonBase)
        //~Engimon() : {
            //delete[] engimon_parents;
            //~engimon_elements;
            //~engimon_skills;
        //}

        //Getter
        string get_species_name() { return species_name; }
        vector<Skill> get_engimon_skills() { return engimon_skills; }

        //Setter
        void set_species_name(string species) { species_name = species; }
        void set_engimon_skills(vector<Skill> skills) { engimon_skills = skills; }

        //Additional methods
        void print_details() {
            cout << "Engimon ID: " << get_engimon_id() << endl;
            cout << "Name: " << get_engimon_name() << endl;
            cout << "Species: " << get_species_name() << endl;
            cout << "level: " << get_level() << endl;
            cout << "Exp: " << get_exp() << endl;
            cout << "Cummulative Exp: " << get_cum_exp() << endl;
            int i;
            for (i = 0; i < get_engimon_elements().size(); i++) { cout << get_engimon_elements()[i].get_element() << " "; }
            cout << endl;
            for (i = 0; i < 2; i++) { cout << get_engimon_parents()[i] << " "; }
            cout << endl;
            for (i = 0; i < get_engimon_skills().size(); i++) { cout << get_engimon_skills()[i].getName() << " "; }
            cout << endl;
            
        }
        void add_skill(Skill skill) {
            if (engimon_skills.size() < 4)
            {
                engimon_skills.push_back(skill);
            } else
            {
                throw "skill full"; //Mungkin penanganan catch-nya diarahkan ke prosedur change_skill
            }
        }

        //Prekondisi skill engimon sudah 4 (penuh)
        void change_skill(Skill skill, Skill replaced) {
            for (int i = 0; i < 4; i++) {
                if (engimon_skills.at(i).getID() == replaced.getID())
                {
                    engimon_skills.at(i) = skill;
                    return;
                }
            }

            cout << "No such skill" << endl;
            throw "No such skill";
        }

        //Menerima indeks dalam vector<Skill>, mengubah skill di idx tertentu
        void change_skill_alt(Skill skill, int idx) {
            if (idx == 0)
            {
                cout << "Cannot change unique skill" << endl;
                throw "Cannot change unique skill";
            } else
            {
                engimon_skills.at(idx) = skill;
            }
        }

        // Untuk testing dan contoh penggunaan; comment atau hapus saat header akan digunakan
        // Note, elemen di skill masih berupa string, belum class element
        int test_main() {
            Engimon misingno = Engimon();

            int learnableBy[1] = {1};
            Skill shock = Skill("1", "Shock", "Electric", learnableBy, 10, "Delivers mild shock", false, "-");
            vector<Skill> pikachuSkill = {shock};

            vector<Element> pikachuElement = {Element("Electric")};
            string parents[2] = {"-", "-"};
    
            Engimon pikachu = Engimon("-", parents, pikachuElement, 1, 1, 1, "Pikachu", pikachuSkill);
            Engimon pikachu2 = Engimon(pikachu);

            pikachu2.set_engimon_name("Pikapi");
            Skill charge = Skill("1", "Charge", "Electric", learnableBy, 5, "Delivers weak static charge", false, "-");
            pikachu2.add_skill(charge);

            misingno.print_details();
            pikachu.print_details();
            pikachu2.print_details();
            return 0;
        }

};

#endif


