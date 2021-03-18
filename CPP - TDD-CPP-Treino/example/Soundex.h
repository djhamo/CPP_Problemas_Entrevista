#pragma once
#include <string>

namespace _Soundex {
    class Soundex {
        public:
            std::string encode(const std::string& word) const;
    };
}