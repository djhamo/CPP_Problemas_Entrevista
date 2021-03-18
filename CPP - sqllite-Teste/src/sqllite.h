#pragma once
#include <string>

namespace _SqlLite {
    class SqlLite {
        public:
            int sql();
            std::string encode(const std::string& word) const;
    };
}