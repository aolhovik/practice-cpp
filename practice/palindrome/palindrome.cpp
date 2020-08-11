/*
 * palindrom.cpp
 *
 *  Created on: Jul 17, 2020
 *      Author: aolhovik
 */

#include "../palindrome/palindrome.h"

#include <iostream>

using namespace std;

bool
isPalindrome (const std::string &s) noexcept
{
  bool isPalindrom = true;

  auto iForward = s.cbegin ();
  auto iBackwards = s.crbegin ();
  while (iForward != s.end ())
    {
      if (*iForward != *iBackwards)
	{
	  isPalindrom = false;
	}
      ;

      ++iForward;
      ++iBackwards;
    }

  return isPalindrom;
}

string
getLongestPalindrome (const string &sIn)
{
  // trivial case - single character or empty
  if (sIn.size () <= 1)
    {
      return sIn;
    }

  // trivial case - sIn is a palindrome
  if (isPalindrome (sIn))
    {
      return sIn;
    }

  // split sIn and check recursively
  string::size_type iSizeIn = sIn.size ();
  string::size_type iLargest = 0; // length of the largest palindrome found
  string s; // largest palindrome;
  for (int iPosSplit = 0; iPosSplit < sIn.size () - 1; ++iPosSplit)
    {
      string sHead = sIn.substr (0, iPosSplit + 1);
      string sTail = sIn.substr (iPosSplit + 1, iSizeIn - (iPosSplit + 1));

      string sHeadPal = getLongestPalindrome (sHead);
      string::size_type iTest = sHeadPal.size ();
      if (iTest > iLargest)
	{
	  iLargest = iTest;
	  s = sHeadPal;
	}

      string sTailPal = getLongestPalindrome (sTail);
      iTest = sTailPal.size ();
      if (iTest > iLargest)
	{
	  iLargest = iTest;
	  s = sHeadPal;
	}
    }

  return s;
}
