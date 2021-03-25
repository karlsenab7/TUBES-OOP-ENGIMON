#ifndef __ENGIMON_HPP__
#define __ENGIMON_HPP__

#include <vector>
#include <iostream>
#include "Skill.hpp"
//#include "Skill.cpp"
#include "folderEngimon/EngimonBase.hpp"
//#include "folderEngimon/EngimonBase.cpp"

using namespace std;

class Engimon : public EngimonBase {
    private:
        string species_name;
        string * parents_species;
        vector<Skill> engimon_skills;

    public:
        //Constructor
        Engimon() : EngimonBase() {
            species_name = "-";
            parents_species = new string [2];
            for (int i = 0; i < 2; i++) {parents_species[i] = "-";}

            // Maksudnya masukin skill default, perubahan mengikuti Skill.hpp
            int learnableBy[1] = {1};
            Skill ember = Skill("1", "Ember", "Fire", learnableBy, 10, "Default Skill", false, "-");
            engimon_skills.push_back(ember);
        }

        Engimon(string name, string * parents_names, vector<Element> elements, int _level, int _exp, int _cum_exp, string species, string * p_species, vector<Skill> skills) : EngimonBase(name, parents_names, elements, _level, _exp, _cum_exp) {
            species_name = species;
            engimon_skills = skills;
            parents_species = new string [2];
            for (int i = 0; i < 2; i++) {parents_species[i] = p_species[i];}
        }

        Engimon(const Engimon& other) : EngimonBase(other) {
            species_name = other.species_name;
            engimon_skills = other.engimon_skills;
            parents_species = new string [2];
            for (int i = 0; i < 2; i++) {parents_species[i] = other.parents_species[i];}
        }

        //Destructor (mungkin bisa menggunakan destructor dari EngimonBase)
        //~Engimon() : {
            //delete[] engimon_parents;
            //~engimon_elements;
            //~engimon_skills;
        //}

        //Operator
        Engimon& operator=(const Engimon& other) {
            *this = other;
            this->species_name = other.species_name;
            this->engimon_skills = other.engimon_skills;
            this->parents_species = new string [2];
            for (int i = 0; i < 2; i++) {this->parents_species[i] = other.parents_species[i];}

            return *this;
        }

        //Getter
        string get_species_name() { return species_name; }
        string * get_parents_species() { return parents_species; }
        vector<Skill> get_engimon_skills() { return engimon_skills; }

        //Setter
        void set_species_name(string species) { species_name = species; }
        void set_parents_species(string * parents) {
            for(int i = 0; i < 2; i++) { parents_species[i] = parents[i]; }
        }
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
            for (i = 0; i < get_engimon_elements().size(); i++) { cout << get_engimon_elements()[i].get_element() << ". "; }
            cout << endl;
            for (i = 0; i < 2; i++) { cout << get_engimon_parents_names()[i] << " = " << get_parents_species()[i] << ". "; }
            cout << endl;
            for (i = 0; i < get_engimon_skills().size(); i++) { cout << get_engimon_skills()[i].getName() << ". "; }
            cout << endl;
            
        }

        bool is_skill_already_learned(Skill skill) {
            bool learned = false;
            for (int i = 0; i < get_engimon_skills().size(); i++) {
                if (get_engimon_skills()[i].getID() == skill.getID()) {
                    learned = true;
                    break;
                }
            }
            return learned;
        }

        void add_skill(Skill skill) {
            if (is_skill_already_learned(skill))
            {
                cout << "This Engimon already know this skill!" << endl;
            }
            else if (engimon_skills.size() < 4)
            {
                engimon_skills.push_back(skill);
            } else
            {
                throw "skill full"; //Mungkin penanganan catch-nya diarahkan ke prosedur change_skill
            }
        }

        //Prekondisi skill engimon sudah 4 (penuh)
        void change_skill(Skill skill, Skill replaced) {
            bool learned = false;
            if (is_skill_already_learned(skill))
            {
                cout << "This Engimon already know this skill!" << endl;
                learned = true;
            }
            else
            {
                for (int i = 0; i < 4; i++) {
                    if (engimon_skills.at(i).getID() == replaced.getID())
                    {
                        engimon_skills.at(i) = skill;
                        learned = true;
                        break;
                    }
                }
            }
            
            if (!learned) {
                cout << "No such skill" << endl;
            }
            
        }

        //Menerima indeks dalam vector<Skill>, mengubah skill di idx tertentu
        void change_skill_alt(Skill skill, int idx) {
            if (idx == 0)
            {
                cout << "Cannot change unique skill!" << endl;
            }
            else if (is_skill_already_learned(skill))
            {
                cout << "This Engimon already know this skill!" << endl;
            }
            else
            {
                engimon_skills.at(idx) = skill;
            }
        }

        // Untuk testing dan contoh penggunaan; comment atau hapus saat header akan digunakan
        // Note: elemen di skill masih berupa string, belum class element
        // Note: belum ada batasan skill yang bisa dipelajari
        int test_main() {
            Engimon missingno = Engimon();

            int learnableBy[1] = {1};
            Skill pikavolt = Skill("1", "Pikavolt", "Electric", learnableBy, 80, "Delivers high voltage electricity", true, "Pikachu");
            Skill thundershock = Skill("2", "Thundershock", "Electric", learnableBy, 40, "Delivers mild shock", false, "-");
            Skill discharge = Skill("3", "Discharge", "Electric", learnableBy, 60, "Discharges build-up electricity", false, "-");
            Skill nuzzle = Skill("4", "Nuzzle", "Electric", learnableBy, 20, "Delivers weak static through contact", false, "-");
            Skill thunderbolt = Skill("5", "Thunderbolt", "Electric", learnableBy, 70, "Delivers strong electric bolt", false, "-");

            vector<Skill> pikachuSkill = {pikavolt};
            vector<Element> pikachuElement = {Element("Electric")};
            string parents[2] = {missingno.get_engimon_name(), missingno.get_species_name()};
    
            Engimon pikachu = Engimon("-", parents, pikachuElement, 1, 1, 1, "Pikachu", parents, pikachuSkill);
            Engimon pikachu2 = pikachu;

            pikachu2.set_engimon_name("Pikapi");
            
            pikachu2.add_skill(discharge);
            pikachu2.add_skill(thundershock);
            pikachu2.add_skill(nuzzle);
            
            Engimon pikachu3 = Engimon(pikachu2);

            pikachu3.change_skill(thunderbolt, thundershock);
            pikachu3.change_skill_alt(thundershock, 3);


            missingno.print_details();
            pikachu.print_details();
            pikachu2.print_details();

            pikachu3.change_skill(thunderbolt, thundershock);
            pikachu3.change_skill_alt(thundershock, 0);
            pikachu3.print_details();
            return 0;
        }

};

#endif


