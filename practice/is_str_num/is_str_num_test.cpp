/*
 * is_str_num_test.cpp
 *
 *  Created on: Jul 18, 2020
 *      Author: aolhovik
 */

#include <cppunit/config/SourcePrefix.h>
#include "is_str_num.h"
#include "is_str_num_test.h"

using namespace std;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(Test_is_str_num);

void Test_is_str_num::test_isStrNumeric()
{
  CPPUNIT_ASSERT( false == isStrNumeric("") );
  CPPUNIT_ASSERT( true == isStrNumeric("1") );
  CPPUNIT_ASSERT( true == isStrNumeric("0123456789") );
  CPPUNIT_ASSERT( false == isStrNumeric("0123456789a") );
  CPPUNIT_ASSERT( false == isStrNumeric("a0123456789") );
  CPPUNIT_ASSERT( false == isStrNumeric("0123a456789") );
  CPPUNIT_ASSERT( false == isStrNumeric("a") );
}
