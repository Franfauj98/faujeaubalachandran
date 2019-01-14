#ifndef __CommandDB_hpp__
#define __CommandDB_hpp__

#include <memory>
#include <map>

using std::unique_ptr;
using std::map;

#include "Command.hpp"
#include "CommandDB.h"
#include "PlayerDB.hpp"

// template<class T,typename ... Args>
// std::unique_ptr<T> make_unique(Args ... args) {
//     return std::unique_ptr<T>(new T(args ...));
// }

#endif
