#ifndef __EXT_OSTRINGSTRING_HPP_150723__
#define __EXT_OSTRINGSTRING_HPP_150723__
#include <string>
#include <sstream>

namespace CommTool {

class StrObj
{
public:
    template <typename T>
    StrObj(const T& inStr)
    {
        oss << T;
    }

    template <typename T>
    StrObj& operator << (const T& inStr)
    {
        oss << T;
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
