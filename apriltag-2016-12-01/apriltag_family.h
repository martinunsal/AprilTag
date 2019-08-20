#ifndef _TAGFACTORY
#define _TAGFACTORY

#include "zarray.h"

struct apriltag_family;

#ifdef __cplusplus
extern "C" {
#endif

__declspec(dllexport) zarray_t* apriltag_family_list();
__declspec(dllexport) void apriltag_family_list_destroy(zarray_t* za);

__declspec(dllexport) struct apriltag_family* apriltag_family_create(const char* family_name);
__declspec(dllexport) void apriltag_family_destroy(struct apriltag_family*);

#ifdef __cplusplus
}
#endif

#endif
