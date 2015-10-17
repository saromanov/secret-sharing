#include "shares.h"

Share::Share(int sh, size_t len) {
    shares = sh;
    length = len;
    data = std::vector<char>(len);
    
}

std::vector<char> Share::Result() {
    return data;
}

size_t Share::Len() {
    return length;
}

int Share:: TotalShares()const {
    return shares;
}

