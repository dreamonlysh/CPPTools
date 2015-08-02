#ifndef __EXT_VECTOR_HP_20150801__
#define __EXT_VECTOR_HP_20150801__
#include <vector>
#include <string>
#include <sstream>
#include "ConstDefination.hpp"

namespace estd {

typedef std::vector<std::string> StringList;

struct Func
{
    template <typename T>
    const T& operator ()(const T& inVal)
    {
        return inVal;
    }
};

template <typename T, typename F>
std::string join(const std::vector<T>& tVec, 
    const std::string& sep = STRING_INTERPUNCTION_COMMA,
    const F& func = Func())
{
    std::ostringstream oss;
    std::vector<T>::const_iterator iter = tVec.begin();
    while (!tVec.empty())
    {
        oss << func(*iter);
        if (++iter == tVec.end()) break;
        oss << sep;
    }
    return oss.str();
}

template <typename T>
std::string toString(const std::vector<T>& tVec)
{
    return join(tVec);
}

}

#endif
