#include "number_theory.h"

NumberTheory::NumberTheory(const char* _path) {
    path = _path;
}

std::vector<char> NumberTheory::readfile() {
    std::ifstream target(path);
    std::ifstream::pos_type pos = target.tellg();
    size_t size = pos;
    std::vector<char> result(size);
    target.seekg(0, std::ios::beg);
    target.read(&result[0], pos);
    target.close();

}

int NumberTheory::randint(int start, int end){
    std::srand(std::time(0));
    int randval = std::rand();
    return start + (randval % (int)(end - start + 1));
}

std::vector<Share> NumberTheory::Sharing() {
    auto filedata = readfile();
    int p = 257;
    std::vector<Share> result;
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
std::string Revealing(std::vector<Share> vecinp) {
    if(vecinp.size() != 2) {
        return std:: string("");
    }
    auto share1 = vecinp[0];
    auto share2 = vecinp[1];
    int len1 = share1.Len();
    int len2 = share2.Len();

    if(len1 != len2) {
        return std::string("");
    }

    const int p = 257;
    auto sh1 = share1.Result();
    auto sh2 = share2.Result();
    std::vector<char> vec(len1);
    for(auto i = 0;i < len1;++i) {
        int byte1 = sh1[i];
        int byte2 = sh2[i];
        if(byte1 == 0) {
            byte1 = 256;
        }

        if(byte2 == 0) {
            byte2 = 256;
        }

        int a = fmod((pow(byte1, 2) * (1/byte2)), p);

    }

    return std::string(vec.begin(), vec.end());

}
