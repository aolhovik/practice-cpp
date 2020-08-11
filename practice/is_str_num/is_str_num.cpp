/*
 * is_str_num.cpp
 *
 *  Created on: Jul 18, 2020
 *      Author: aolhovik
 */

#include "is_str_num.h"

#include <array>

using namespace std;

bool
isDigit (char c)
{
  static const array<char, 10> Digits =
    { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

  for (auto digit : Digits)
    {
      if (digit == c)
	return true;
    }
  return false;
}

bool
isStrNumeric (const string &s)
{
  if (s.empty ())
    {
      return false;
    }

  for (auto c : s)
    {
      if (!isDigit (c))
	{
	  return false;
	}
    }

  return true;
}
