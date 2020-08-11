/*
 * test_palindrom.h
 *
 *  Created on: Jul 17, 2020
 *      Author: aolhovik
 */

#ifndef PALINDROME_TEST_H_
#define PALINDROME_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

class PalindromTest : public CPPUNIT_NS::TestFixture
{
CPPUNIT_TEST_SUITE( PalindromTest );
  CPPUNIT_TEST(test_isPalindrom);
  CPPUNIT_TEST(test_getLongestPalindrome);CPPUNIT_TEST_SUITE_END()
  ;

public:
  void
  test_isPalindrom ();
  void
  test_getLongestPalindrome ();

};

#endif /* PALINDROME_TEST_H_ */
