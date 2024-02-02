#include <string>

#ifndef SCORE_H_
#define SCORE_H_

class Score {

private:

public:
    static float load_best_score(std::string level);
    static void store_best_score(float score, std::string level);
};

#endif /* !SCORE_H_ */
