#include <vector>
#include <string>
#include "shares.h"

//Abstract class for secret sharing methods
class SecretSharing {
    public:

        //Sharing function which returns vector of shares
        virtual std::vector<Share> Sharing();

        virtual std::string Revealing(std::vector<Share>);
};
