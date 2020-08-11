/*
 * is_str_num_test.h
 *
 *  Created on: Jul 18, 2020
 *      Author: aolhovik
 */

#ifndef IS_STR_NUM_TEST_H_
#define IS_STR_NUM_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

class Test_is_str_num : public CPPUNIT_NS::TestFixture
{
CPPUNIT_TEST_SUITE( Test_is_str_num );

  CPPUNIT_TEST(test_isStrNumeric);

  CPPUNIT_TEST_SUITE_END()
  ;

public:
  void
  test_isStrNumeric ();

};

#endif /* IS_STR_NUM_TEST_H_ */
