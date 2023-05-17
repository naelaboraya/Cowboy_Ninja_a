#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include "Point.hpp"
#include "Character.hpp"
#include "Cowboy.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include <vector>

using namespace std;

namespace ariel {}

class Team {

private:
Character* _captain; //the leader if the team
std::vector<Character*> _soilders; //team members


public:

//constructor
Team(Character* captain);

//destructor
~Team();

//-----------------------------Rule of five---------------------------------------
// Copy constructor
    Team(const Team& other);

    // Copy assignment operator
    Team& operator=(const Team& other);

    // Move constructor
    Team(Team&& other) noexcept;

    // Move assignment operator
    Team& operator=(Team&& other) noexcept;
//--------------------------------------------------------------------------------

//getters and setters : 

Character* getCaptain(){
    return this->_captain;
}

void setCaptain(Character* new_captain){
    this->_captain=new_captain;
}

//functions:

void add(Character* new_soilder);

void attack(Team* enemy_team);

int stillAlive();

std::string print();

};





#endif
