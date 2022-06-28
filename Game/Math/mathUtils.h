#pragma once
//#ifndef __MATH_UTILS_H__
//#define __MATH_UTILS_H__

namespace math 
{
	int sqr(int i);
	// inline is a workaround for defining functions in a header
	inline int half(int i) { return i / 2; } // it doenst actualy call it, it repaces the call with the definition

}
//#endif // __MATH_UTILS_H__