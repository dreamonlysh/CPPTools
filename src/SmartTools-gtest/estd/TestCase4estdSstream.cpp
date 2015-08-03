#include <estd/ext_sstream.hpp>
#include "TestSuite4estd.hpp"

namespace gtest { namespace testd {
using namespace estd;

TEST(TestEstdSstream, StrObjInit)
{
    ASSERT_EQ("a", std::string(StrObj("a")));
}

TEST(TestEstdSstream, StrObjAddData)
{
    std::string str = StrObj("a") << "b" << "c";
    ASSERT_EQ("abc", str);
}

TEST(TestEstdSstream, StrObjAddDataOfMultiType)
{
    std::string str = StrObj("a") << 2 << "c" << std::string("d");
    ASSERT_EQ("a2cd", str);
}

}}
