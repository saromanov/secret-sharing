#include <iostream>
#include <fstream>
#include <string>

//Every secret sharing method returns list of this class objects

class Share {
    long id;

    //total number of shares from session
    int shares;

    //total size of the data from share
    size_t length;
    std::vector<char> result;

    public:
        Share(int sh, size_t len);
        void Add();

        //Return result of the share
        std::string Result();

        long id_share();

        //Return total number of shares
        int shares();

        size_t Len();

};
