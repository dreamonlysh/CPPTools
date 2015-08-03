#include <estd/ext_vector.hpp>
#include "TestSuite4estd.hpp"

namespace gtest { namespace testd {
using namespace estd;

TEST(TestEstdVector, joinEmpty)
{
    StringList sList;
    ASSERT_EQ(STRING_COMMON_EMPTY, join(sList));
}

TEST(TestEstdVector, joinWithComma)
{
    StringList sList;
    sList.push_back("a");
    sList.push_back("b");
    ASSERT_EQ("a,b", join(sList));
}

TEST(TestEstdVector, joinWithDot)
{
    StringList sList;
    sList.push_back("a");
    sList.push_back("b");
    ASSERT_EQ("a.b", join(sList, STRING_INTERPUNCTION_DOT));
}

TEST(TestEstdVector, toStringStringList)
{
    StringList sList;
    sList.push_back("a");
    sList.push_back("b");
    ASSERT_EQ("a,b", toString(sList));
}

}}
