#include <iostream>
#include <fstream>
#include "shares.h"

Share::Share(int sh, size_t len) {
    shares = sh;
    length = len;
    result = std::vector<char>(len);
    
}

std::string Share::Result() {
    return result;
}

int Share::Len() {
    return length;
}

int Share:: TotalShares() {
    return shares;
}

