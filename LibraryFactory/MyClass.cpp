#include "MyClass.h"

#ifdef ADD_SAFETY_USING_OPERATOR_DELETE
void MyClass::operator delete(void* ptr)
{
    ::operator delete(ptr);
}
#endif

#ifdef ADD_SAFETY_USING_CUSTOM_DELETER
namespace std
{
void default_delete< MyClass >::operator()(MyClass *iToDelete)
{
  delete iToDelete;
}
}
#endif
