#include "sqllite.h"
#include <gmock/gmock.h>

using namespace _SqlLite;
using namespace testing;

/*
class SqlLiteEncoding: public Test {
public:
   SqlLite soundex;
};

TEST_F(SqlLiteEncoding, RetainsSoleLetterOfOneLetterWord) {
   ASSERT_THAT(soundex.encode("A"), Eq("A000")); 
}

TEST_F(SqlLiteEncoding, PadsWithZerosToEnsureThreeDigits) {
   ASSERT_THAT(soundex.encode("I"), Eq("I000"));
}

TEST_F(SqlLiteEncoding, ReplacesConsonantsWithAppropriateDigits) {
   ASSERT_THAT(soundex.encode("Ax"), Eq("A200"));
}

TEST_F(SqlLiteEncoding, IgnoresNonAlphabetics) {
   ASSERT_THAT(soundex.encode("A#"), Eq("A000"));
}

TEST_F(SqlLiteEncoding, ReplacesMultipleConsonantsWithDigits) {
   ASSERT_THAT(soundex.encode("Acdl"), Eq("A234"));
}

TEST_F(SqlLiteEncoding, LimitsLengthToFourCharacters) {
   ASSERT_THAT(soundex.encode("Dcdlb").length(), Eq(4u)); 
}

TEST_F(SqlLiteEncoding, IgnoresVowelLikeLetters) {
   ASSERT_THAT(soundex.encode("BaAeEiIoOuUhHyYcdl"), Eq("B234"));
}

TEST_F(SqlLiteEncoding, CombinesDuplicateEncodings) {
   //ASSERT_THAT(soundex.encodedDigit('b'), Eq(soundex.encodedDigit('f')));
   //ASSERT_THAT(soundex.encodedDigit('c'), Eq(soundex.encodedDigit('g')));
   //ASSERT_THAT(soundex.encodedDigit('d'), Eq(soundex.encodedDigit('t')));

   ASSERT_THAT(soundex.encode("Abfcgdt"), Eq("A123"));
}

TEST_F(SqlLiteEncoding, UppercasesFirstLetter) {
   ASSERT_THAT(soundex.encode("abcd"), StartsWith("A"));
}

TEST_F(SqlLiteEncoding, IgnoresCaseWhenEncodingConsonants) {
   ASSERT_THAT(soundex.encode("BCDL"), Eq(soundex.encode("Bcdl")));
}

TEST_F(SqlLiteEncoding, CombinesDuplicateCodesWhen2ndLetterDuplicates1st) {
   ASSERT_THAT(soundex.encode("Bbcd"), Eq("B230"));
}

TEST_F(SqlLiteEncoding, DoesNotCombineDuplicateEncodingsSeparatedByVowels) {
   ASSERT_THAT(soundex.encode("Jbob"), Eq("J110"));
}
*/

TEST(SqlLiteEncoding, RetainsSoleLetterOfOneLetterWord) {
    SqlLite soundex;
    auto encoded = soundex.encode("A");

    ASSERT_THAT(encoded, testing::Eq("A"));
}

TEST(SqlLiteEncoding, PadsWithZerosToEnsureThreeDigits) {
    SqlLite soundex;
    auto encoded = soundex.encode("I");

    ASSERT_THAT(encoded, testing::Eq("I000"));
}

int main(int argc, char** argv) {
    testing::InitGoogleMock(&argc, argv);
    return RUN_ALL_TESTS();
}