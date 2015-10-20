#include "shares.cpp"
#include "secret_sharing.h"
#include <iostream>
#include <vector>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <cmath>

const int shares_number = 3;

//Implementation from the paper
//"Simple and Efficient Secret Sharing Schemes for Sharing Data and Image"
//http://arxiv.org/abs/1502.07475
//Each file splits on the three shares
class NumberTheory: public SecretSharing<Share> {
    const char* path;
    std::vector<char> readfile();
    int randint(int start, int end);
    public:
        NumberTheory(const char*);
        std::vector<Share> Sharing();
        std::string Revealing(std::vector<Share>);

};
