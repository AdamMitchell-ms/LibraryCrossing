#pragma once

#include "DllSwitch.h"

#include <memory>

#undef ADD_SAFETY_USING_OPERATOR_DELETE
#undef ADD_SAFETY_USING_CUSTOM_DELETER

class LIBRARYFACTORY_API MyClass
{
#ifdef ADD_SAFETY_USING_OPERATOR_DELETE
public:
    static void operator delete(void* ptr);
#endif
};

#ifdef ADD_SAFETY_USING_CUSTOM_DELETER

namespace std
{

// The following is a partial specialization of default_delete used by unique_ptr
// for the class MyClass. You need this for all types that the factory can create.
template<>
class LIBRARYFACTORY_API default_delete< MyClass >
{
public:
  void operator()(MyClass *iToDelete);
};

}

#endif
