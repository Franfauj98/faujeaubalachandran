/** 
 * @file PlayerDB.hpp
 * @author Philippe-Henri Gosselin
 * @date 9 décembre 2015
 * @copyright CNRS
 */

#ifndef __PlayerDB_hpp__
#define __PlayerDB_hpp__

#include <memory>
#include <map>

using std::unique_ptr;
using std::map;

#include "Player.hpp"
#include "PlayerDB.h"

template<class T,typename ... Args>
std::unique_ptr<T> make_unique(Args ... args) {
    return std::unique_ptr<T>(new T(args ...));
}

#endif
