/*
 * rm_c_from_str_test.h
 *
 *  Created on: Jul 17, 2020
 *      Author: aolhovik
 */

#ifndef RM_C_FROM_STR_TEST_H_
#define RM_C_FROM_STR_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

class RmCharFromStrTest : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( RmCharFromStrTest );
  CPPUNIT_TEST( test_rm_c_from_str );
  CPPUNIT_TEST_SUITE_END();

public:
  void test_rm_c_from_str();

};

#endif /* RM_C_FROM_STR_TEST_H_ */
