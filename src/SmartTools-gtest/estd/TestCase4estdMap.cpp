#include <estd/ext_map.hpp>
#include "TestSuite4estd.hpp"

namespace gtest { namespace testd {
using namespace estd;

TEST(TestEstdMap, getMapValTrue)
{
    StringMap sMap;
    sMap["a"] = "A";

    std::string val;
    bool res = getMapVal(sMap, std::string("a"), val);
    ASSERT_TRUE(res);
    ASSERT_EQ("A", val);
}

TEST(TestEstdMap, getMapValFalse)
{
    StringMap sMap;

    std::string val;
    bool res = getMapVal(sMap, std::string("a"), val);
    ASSERT_FALSE(res);
    ASSERT_EQ(STRING_COMMON_EMPTY, val);
}

TEST(TestEstdMap, toStringEmptyMap)
{
    StringMap sMap;
    ASSERT_EQ("{}", toString(sMap));
}

TEST(TestEstdMap, toStringMapWithVal)
{
    StringMap sMap;
    sMap["a"] = "A";
    ASSERT_EQ("{a:A}", toString(sMap));
}

TEST(TestEstdMap, toStringMapWithVals)
{
    StringMap sMap;
    sMap["a"] = "A";
    sMap["b"] = "B";
    ASSERT_EQ("{a:A, b:B}", toString(sMap));
}

}}
