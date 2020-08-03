/*
 * count_unique_words_test.h
 *
 *  Created on: Aug 2, 2020
 *      Author: aolhovik
 */

#ifndef COUNT_UNIQUE_WORDS_TEST_H_
#define COUNT_UNIQUE_WORDS_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

class TestCountUniqueWords : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( TestCountUniqueWords );
  CPPUNIT_TEST( test_countUniqueWords );
  CPPUNIT_TEST_SUITE_END();

public:
  void test_countUniqueWords();
};

#endif /* COUNT_UNIQUE_WORDS_TEST_H_ */
