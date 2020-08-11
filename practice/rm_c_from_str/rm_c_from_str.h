/*
 * rm_c_from_str.h
 *
 *  Created on: Jul 17, 2020
 *      Author: aolhovik
 */

#ifndef RM_C_FROM_STR_H_
#define RM_C_FROM_STR_H_

#include <string>

/**
 * \brief Removes specified character from a given string
 *
 * \param c	character to remove
 * \param s	string to remove character from
 *
 */
std::string rm_c_from_str(const char c, const std::string &s);

#endif /* RM_C_FROM_STR_H_ */
