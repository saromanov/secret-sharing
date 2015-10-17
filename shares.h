#include <iostream>
#include <fstream>
#include <string>
#include <vector>

//Every secret sharing method returns list of this class objects

class Share {
    long id;

    //total number of shares from session
    int shares;

    //total size of the data from share
    size_t length;
    std::vector<char> data;

    public:
        Share(int sh, size_t len);
        void Add();

        //Return result of the share
        std::vector<char> Result();

        long id_share();

        //Return total number of shares
        int TotalShares() const;

        size_t Len();

};
