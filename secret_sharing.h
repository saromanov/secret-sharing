#include <vector>
#include <string>

//Abstract class for secret sharing methods
template<typename T>
class SecretSharing {
    public:

        //Sharing function which returns vector of shares
        virtual std::vector<T> Sharing();

        virtual std::string Revealing(std::vector<T>);
};
