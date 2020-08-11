/*
 * get_unique_test.cpp
 *
 *  Created on: Jul 18, 2020
 *      Author: aolhovik
 */

#include <cppunit/config/SourcePrefix.h>
#include "get_unique.h"
#include "get_unique_test.h"

using namespace std;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(Test_get_unique);

void
Test_get_unique::test_get_unique ()
{
  CPPUNIT_ASSERT('\0' == get_unique (""));
  CPPUNIT_ASSERT('a' == get_unique ("abbcd"));
  CPPUNIT_ASSERT('c' == get_unique ("aabbbcddef"));
  CPPUNIT_ASSERT('c' == get_unique ("aabbbcddef"));
  CPPUNIT_ASSERT('\0' == get_unique ("aabbbccddeeff"));
}

