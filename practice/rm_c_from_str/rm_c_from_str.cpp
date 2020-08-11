/*
 * rm_c_from_str.cpp
 *
 *  Created on: Jul 17, 2020
 *      Author: aolhovik
 */

#include "rm_c_from_str.h"

#include <algorithm>
#include <iterator>

std::string rm_c_from_str(const char cRm, const std::string &str)
{
	std::string strResult;
	std::copy_if(str.begin(), str.end(), std::inserter(strResult, strResult.begin()), [=](char c) { return c != cRm; } );

	return strResult;
}
