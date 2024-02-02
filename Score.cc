#include "Score.h"

#include <iostream>
#include <fstream>
#include <sstream>

float Score::load_best_score(std::string level){
    std::ostringstream path;
    path << "../score/" << level << ".txt";
    std::ifstream s(path.str());
    std::string line;
    if (s.is_open()){
        getline(s,line);
        s.close();
        return std::stof(line);
    }
    return 0.0;
}

void Score::store_best_score(float score, std::string level){
    std::ostringstream path;
    path << "../score/" << level << ".txt";
    std::ofstream s(path.str());
    if (s.is_open()){
        s << score;
        s.close();
    }
}