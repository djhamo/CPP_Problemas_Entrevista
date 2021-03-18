#include "src/sqllite.h"

using namespace _SqlLite;

int main(int argc, char** argv) {
    SqlLite tt;
    tt.encode("A");
    tt.sql();
    
    return 0;
}