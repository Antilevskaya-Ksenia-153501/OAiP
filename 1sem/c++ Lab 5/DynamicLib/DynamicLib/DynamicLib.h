#pragma once
#ifdef DYNAMICLIB_EXPORTS
#define DYNAMICLIB_API __declspec(dllexport)
#else
#define DYNAMICLIB_API __declspec(dllimport)
#endif


extern "C" DYNAMICLIB_API void transformation(double* matrix, int n);
extern "C" DYNAMICLIB_API double sum(double* matrix, int n, int i);
