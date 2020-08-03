/*
 * count_unique_words_test.cpp
 *
 *  Created on: Aug 2, 2020
 *      Author: aolhovik
 */

#include "count_unique_words_test.h"
#include "count_unique_words.h"

using namespace cuw;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( TestCountUniqueWords );

void
TestCountUniqueWords::test_countUniqueWords()
{
  CPPUNIT_ASSERT( 0 == countUniqueWords(""));
  CPPUNIT_ASSERT( 0 == countUniqueWords(" "));
  CPPUNIT_ASSERT( 1 == countUniqueWords("singleword"));
  CPPUNIT_ASSERT( 4 == countUniqueWords("wild cats wear NO hats."));
  CPPUNIT_ASSERT( 3 == countUniqueWords("Wild cats     hAts.   "));
  CPPUNIT_ASSERT( 4 == countUniqueWords("a horse and a dog a a a"));
}


