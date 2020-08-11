/*
 * rm_c_from_str_test.cpp
 *
 *  Created on: Jul 17, 2020
 *      Author: aolhovik
 */

#include <cppunit/config/SourcePrefix.h>
#include "rm_c_from_str_test.h"
#include "rm_c_from_str.h"

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( RmCharFromStrTest );

void RmCharFromStrTest::test_rm_c_from_str()
{
  CPPUNIT_ASSERT( std::string("") == rm_c_from_str('a', ""));
  CPPUNIT_ASSERT( std::string("") == rm_c_from_str('a', "a"));
  CPPUNIT_ASSERT( std::string("") == rm_c_from_str('a', "aa"));
  CPPUNIT_ASSERT( std::string("bcbc") == rm_c_from_str('a', "abcabca"));
}
