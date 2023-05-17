#include "Team.hpp"
#include <algorithm>

//constructor
Team::Team(Character* captain) : _captain(captain){
     this->_soilders.reserve(10);
     this->_soilders.push_back(captain);
}

//destructor
Team::~Team(){
    for(Character* soilder : this->_soilders){
        delete soilder;
    }
}

//-----------------------------------------Rule of five-----------------------------------
// Copy constructor
Team::Team(const Team& other)
    : _captain(nullptr), _soilders(other._soilders.size()) {
    // Deep copy the captain
    if (other._captain != nullptr) {
        _captain = new Character(*other._captain);
    }

    // Deep copy the soilders
    for (size_t i = 0; i < other._soilders.size(); i++) {
        _soilders[i] = new Character(*other._soilders[i]);
    }
}

// Copy assignment operator
Team& Team::operator=(const Team& other) {
    if (this != &other) {
        // Delete existing captain and soilders
        delete _captain;
        for (Character* soilder : _soilders) {
            delete soilder;
        }

        // Deep copy the captain
        _captain = nullptr;
        if (other._captain != nullptr) {
            _captain = new Character(*other._captain);
        }

        // Deep copy the soilders
        _soilders.resize(other._soilders.size());
        for (size_t i = 0; i < other._soilders.size(); i++) {
            _soilders[i] = new Character(*other._soilders[i]);
        }
    }
    return *this;
}

// Move constructor
Team::Team(Team&& other) noexcept
    : _captain(std::move(other._captain)), _soilders(std::move(other._soilders)) {
    // Set 'other' to a valid state
    other._captain = nullptr;
    other._soilders.clear();
}

// Move assignment operator
Team& Team::operator=(Team&& other) noexcept {
    if (this != &other) {
        // Delete existing captain and soilders
        delete _captain;
        for (Character* soilder : _soilders) {
            delete soilder;
        }

        // Move the captain and soilders from 'other'
        _captain = std::move(other._captain);
        _soilders = std::move(other._soilders);

        // Set 'other' to a valid state
        other._captain = nullptr;
        other._soilders.clear();
    }
    return *this;
}
//----------------------------------------------------------------------------------------



//functions:

void Team::add(Character* new_soilder){
    if(this->_soilders.size() == 10){
        throw std::runtime_error("the team is full!");
    }
    
    for (Character* soldier : this->_soilders) {
        if (soldier == new_soilder) {
            throw std::runtime_error("The soldier already exists in the team!");
        }
    }

    this->_soilders.push_back(new_soilder);
}

int Team::stillAlive(){
    int counter = 0;
	for(Character* soilder : this->_soilders){
        if(soilder->isAlive()){
            counter++;
        }
    }
    return counter;
}

void Team::attack(Team* enemy_team){
    if(enemy_team==nullptr){
        throw std::invalid_argument("cannot attack null!");
    }
    for(Character* enemy : enemy_team->_soilders){
        enemy->hit_points=0;
    }
    return;
}

std::string Team::print(){
    std::string result;

    // Iterate through Cowboys
    for (Character* character : _soilders) {
        if (Cowboy* cowboy = dynamic_cast<Cowboy*>(character)) {
            result += cowboy->print() + "\n";
        }
    }

    // Iterate through OldNinjas
    for (Character* character : _soilders) {
        if (OldNinja* oldNinja = dynamic_cast<OldNinja*>(character)) {
            result += oldNinja->print() + "\n";
        }
    }

    // Iterate through TrainedNinjas
    for (Character* character : _soilders) {
        if (TrainedNinja* trainedNinja = dynamic_cast<TrainedNinja*>(character)) {
            result += trainedNinja->print() + "\n";
        }
    }

    // Iterate through YoungNinjas
    for (Character* character : _soilders) {
        if (YoungNinja* youngNinja = dynamic_cast<YoungNinja*>(character)) {
            result += youngNinja->print() + "\n";
        }
    }

    return result;
}
