// Copyright 2014 Yu Jing<yujing5b5d@gmail.com>
#ifndef INCLUDE_ARGCV_UTIL_H_
#define INCLUDE_ARGCV_UTIL_H_

#include <cmath>
#include <ctime>
#include <cstdint>  // uint64_t

#include <sstream>
#include <string>
#include <vector>

#include "leveldb/db.h"
#include "leveldb/cache.h"
#include "leveldb/options.h"

namespace argcv {
namespace util {

// for hash
void crypt_init();  // for hash key generator
uint64_t hash(const char * k, uint64_t offset);
uint64_t hash(const std::string & k, uint64_t offset);

// tf-idf
// assume : k in document D
// stid : size of term k in  D
// atsid :  all term size in D
// ads : all document size
// dscct : document size contains current term
inline double tf_idf(size_t stid, size_t atsid, size_t ads, size_t dscct) {
    // #define MATH_LG_10 2.302585
    // tf * idf
    if (ads == 0 || atsid == 0 || dscct == 0) return 0;
    return (static_cast<double>(stid) / atsid)
        * log(static_cast<double>(ads) / (dscct))/2.302585;
}

inline static std::string random_str(const int len) {
    static const char alphanum[] =
        "0123456789"
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz";

    std::stringstream ss;
    for (int i = 0; i < len; ++i) {
        ss << alphanum[rand() % (sizeof(alphanum) - 1)];
    }
    return ss.str();
}


std::vector<std::string> &split(const std::string &s, const std::string &delim,
    std::vector<std::string> *_elems);

std::vector<std::string> split(const std::string &s, const std::string &delim);


}  // namespace util
}  // namespace argcv

#endif  // INCLUDE_ARGCV_UTIL_H_
