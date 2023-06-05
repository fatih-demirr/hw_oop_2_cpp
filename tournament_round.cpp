#include "tournament_round.h"

// TournamentRound functions goes here

TournamentRound::TournamentRound() { }
TournamentRound::TournamentRound(std::list<MusicBand*>_bands) {
    for(std::list<MusicBand*>::iterator it = _bands.begin(); it != _bands.end(); ++it) {
        this -> bands.push_back(*it);
    }
}
TournamentRound::TournamentRound(std::vector<MusicBand*>_bands) {
    for(std::vector<MusicBand*>::iterator it = _bands.begin(); it != _bands.end(); ++it) {
        this -> bands.push_back(*it);
    }
}

std::size_t TournamentRound::size() {
    return this -> bands.size();
}
    
//TournamentRound::TournamentRound(TournamentRound& other) { }
//TournamentRound::TournamentRound(TournamentRound&& other) { }
TournamentRound& TournamentRound::operator=(TournamentRound&& other) {
    if(this != &other){
        this -> bands = std::move(other.bands);
    }
    return *this;
}
TournamentRound& TournamentRound::get_next_round() {
    std::list<MusicBand*> next;
    if(this -> size() % 2 == 0){
        int i = 0;
        int score1 = 0;
        int score2 = 0;
        int diff = 0;
        int siz = this -> bands.size();
        for(;i < (siz / 2) ;i++){
            MusicBand* beg = bands.front();
            MusicBand* end = bands.back();
            score1 = beg -> play(end);
            score2 = end -> play(beg);
            if(score1 >= score2){
                diff = score1 - score2;
                if(diff > end -> get_fan_count()){
                    int count = end -> get_fan_count();
                    int hold = beg -> get_fan_count();
                    end -> set_fan_count(0);
                    hold += count;
                    beg -> set_fan_count(hold);
                }
                else{
                    int count = end -> get_fan_count();
                    int hold = beg -> get_fan_count();
                    count -= diff;
                    end -> set_fan_count(count);
                    hold += diff;
                    beg -> set_fan_count(hold);
                }
                next.push_back(beg);
            }
            else{
                diff = score2 - score1;
                if(diff > beg -> get_fan_count()){
                    int count = beg -> get_fan_count();
                    int hold = end -> get_fan_count();
                    beg -> set_fan_count(0);
                    hold += count;
                    end -> set_fan_count(hold);
                }
                else{
                    int count = beg -> get_fan_count();
                    int hold = end -> get_fan_count();
                    count -= diff;
                    beg -> set_fan_count(count);
                    hold += diff;
                    end -> set_fan_count(hold);
                }
                next.push_back(end);
            }
            this -> bands.pop_front();
            this -> bands.pop_back();
        } 
    }
    else{
        int i = 0;
        int score1 = 0;
        int score2 = 0;
        int diff = 0;
        int siz = this -> bands.size();
        for(;i < ((siz -1) / 2) ;i++){
            MusicBand* beg = bands.front();
            MusicBand* end = bands.back();
            score1 = beg -> play(end);
            score2 = end -> play(beg);
            if(score1 >= score2){
                diff = score1 - score2;
                if(diff > end -> get_fan_count()){
                    int count = end -> get_fan_count();
                    int hold = beg -> get_fan_count();
                    end -> set_fan_count(0);
                    hold += count;
                    beg -> set_fan_count(hold);
                }
                else{
                    int count = end -> get_fan_count();
                    int hold = beg -> get_fan_count();
                    count -= diff;
                    end -> set_fan_count(count);
                    hold += diff;
                    beg -> set_fan_count(hold);
                }
                next.push_back(beg);
            }
            else{
                diff = score2 - score1;
                if(diff > beg -> get_fan_count()){
                    int count = beg -> get_fan_count();
                    int hold = end -> get_fan_count();
                    beg -> set_fan_count(0);
                    hold += count;
                    end -> set_fan_count(hold);
                }
                else{
                    int count = beg -> get_fan_count();
                    int hold = end -> get_fan_count();
                    count -= diff;
                    beg -> set_fan_count(count);
                    hold += diff;
                    end -> set_fan_count(hold);
                }
                next.push_back(end);
            }
            this -> bands.pop_front();
            this -> bands.pop_back();
        }
        next.push_back(this -> bands.front());
        this -> bands.pop_front();
    }
    this -> bands = next;
    return *this;
}

std::ostream& operator<< (std::ostream &os, TournamentRound &other) {
    int size = other.bands.size();
    int i = 0;
    if(other.bands.size() == 0){
        return os;
    }
    if(other.bands.size() == 1){
        std::list<MusicBand*>::iterator it = other.bands.begin();
        os << (*it) -> get_name();
        return os;
    }
    for(std::list<MusicBand*>::iterator it = other.bands.begin(); it != other.bands.end(); ++it) {
        if(i == size - 1){
            os << (*it) -> get_name();
            break;
        }
        i++;
        os << (*it) -> get_name() << '\t';
    }  
    return os;
}
























