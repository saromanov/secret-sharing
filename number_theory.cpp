#include "number_theory.h"

std::vector<char> NumberTheory::readfile() {
    ifstream target(path);
    ifstream::pos_type pos = ifs.tellg();
    size_t size = pos;
    std::vector<char> result(size);
    ifs.sekg(0, ios::beg);
    ifs.read(&result[0], pos);
    target.close();

}

int NumberTheory::randint(int start, int end){
    std::srand(std::time(0));
    int randval = std::rand();
    return start + (randval % (int)(end - start + 1));
}

Shares[] NumberTheory::Sharing() {
    auto filedata = readfile();
    int p = 257;
    Shares[] result;
    for(const char &i: filedata) {
        int byte = i;
        if(byte == 0) {
            byte = 256;
        }
        int a = std::cbrt(byte);
        int rnd = randint(0, 257);
        auto s1 = rnd * a % p;
        if(s1 == 256) {
            s1 = 0;
        }

        auto s2 = rnd * rnd * a % p;
        if(s2 == 256) {
            s2 = 0;
        }

        auto s3 = rnd * rnd * rnd * rnd * a % p;
        if(s3 == 256) {
            s3 = 0;
        }
    }

    return result;
}

//For revealing you need to put two shares
std::string Revealing(Share share1, Share share2) {
    if(shares.length == 0 ) {
        return std::string("");
    }

    int len1 = share1.Len();
    int len2 = share2.Len();

    if(len1 != len2) {
        return std::string("");
    }

    const int p = 257;
    std::vector<char> vec(len1);
    for(auto i = 0;i < len1;++i) {
        int byte1 = share1[i];
        int byte2 = share2[i];
        if(byte1 == 0) {
            byte1 = 256;
        }

        if(byte2 == 0) {
            byte2 = 256;
        }

        int a = pow(byte1, 2) * 1/byte2 % p;

    }

    return std::string(vec.begin(), vec.end());

}
