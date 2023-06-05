#include "jazz.h"
#include "metal.h"
#include "rock.h"
#include "kpop.h"

int RockBand::play(MusicBand *other){
    int score = (this -> get_fan_count() + ((0.1) * this -> get_talent() * this -> get_energy()));
    double c = 0;
    double k = 0;
    int old_energy = this -> get_energy();
    int new_energy = 0;
    if(dynamic_cast<KPopBand*>(other) != NULL){
        c = 0.5;
    }
    else if(dynamic_cast<MetalBand*>(other) != NULL){
        c = 1.4;
    }
    else if(dynamic_cast<RockBand*>(other) != NULL){
        c = 1.0;
    }
    else if(dynamic_cast<JazzBand*>(other) != NULL){
        c = 0.8;
    }
    score *= c;
    k = 0.1;
    new_energy = (old_energy - (k * old_energy)); 
    this -> set_energy(new_energy);
    return score;
}

void RockBand::rehearse(void) {
    int old_energy = this -> get_energy();
    int new_energy = 0;
    int old_talent = this -> get_talent();
    int new_talent = 0;
    double k = 0;
    int t = 0;
    k = 0.1;
    new_energy = (old_energy - ((0.5 * k * old_energy)));
    this -> set_energy(new_energy);
    t = 10;
    new_talent = (old_talent + t);
    this -> set_talent(new_talent);
}























