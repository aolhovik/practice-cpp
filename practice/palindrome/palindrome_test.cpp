/*
 * test_palindrom.cpp
 *
 *  Created on: Jul 17, 2020
 *      Author: aolhovik
 */

#include "../palindrome/palindrome.h"
#include "../palindrome/palindrome_test.h"

#include <cppunit/config/SourcePrefix.h>

using namespace std;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(PalindromTest);

void
PalindromTest::test_isPalindrom ()
{

  CPPUNIT_ASSERT(true == isPalindrome (""));
  CPPUNIT_ASSERT(true == isPalindrome ("a"));
  CPPUNIT_ASSERT(true == isPalindrome ("abccba"));
}

void
PalindromTest::test_getLongestPalindrome ()
{
  CPPUNIT_ASSERT(getLongestPalindrome ("") == "");
  CPPUNIT_ASSERT(getLongestPalindrome ("a") == "a");
  CPPUNIT_ASSERT(getLongestPalindrome ("aa") == "aa");
  CPPUNIT_ASSERT(getLongestPalindrome ("abc") == "a");
  CPPUNIT_ASSERT(getLongestPalindrome ("abbcd") == "bb");
}
