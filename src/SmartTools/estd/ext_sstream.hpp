#ifndef __EXT_SSTREAM_HPP_150723__
#define __EXT_SSTREAM_HPP_150723__
#include <sstream>
#include <string>

namespace estd {

class StrObj
{
public:
    template <typename T>
    StrObj(const T& inStr)
    {
        oss << inStr;
    }

    template <typename T>
    StrObj& operator << (const T& inStr)
    {
        oss << inStr;
        return *this;
    }
    
    operator std::string()
    {
        return oss.str();
    }

private:
    std::ostringstream oss;
};

}

#endif
