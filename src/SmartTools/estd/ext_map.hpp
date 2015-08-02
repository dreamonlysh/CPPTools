#ifndef __EXT_MAP_HPP_20150801__
#define __EXT_MAP_HPP_20150801__
#include <map>
#include <string>
#include <sstream>
#include "ConstDefination.hpp"

namespace estd {

typedef std::map<std::string, std::string> StringMap;

template <typename K, typename V>
bool getMapVal(const std::map<K, V>& k2vMap, const K& k, V& v)
{
    std::map<K, V>::iterator iter = k2vMap.find(k);
    if (iter == k2vMap.end()) return false;
    v = iter->second;
    return true;
}

template <typename K, typename V>
std::string toString(const std::map<K, V>& k2vMap)
{
    std::ostringstream oss;
    oss << STRING_INTERPUNCTION_LBRACE;
    std::map<K, V>::const_iterator iter = k2vMap.begin();
    while (!k2vMap.empty())
    {
        oss << iter->first << STRING_INTERPUNCTION_COLON 
            << STRING_COMMON_SPACE << iter->second;
        if (++iter == k2vMap.end()) break;
        oss << STRING_INTERPUNCTION_COMMA << STRING_COMMON_SPACE;
    }
    oss << STRING_INTERPUNCTION_RBRACE;
    return oss.str();
}

}

#endif
