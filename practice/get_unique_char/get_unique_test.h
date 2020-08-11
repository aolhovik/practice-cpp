/*
 * get_unique_test.h
 *
 *  Created on: Jul 18, 2020
 *      Author: aolhovik
 */

#ifndef GET_UNIQUE_TEST_H_
#define GET_UNIQUE_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

class Test_get_unique : public CPPUNIT_NS::TestFixture
{
CPPUNIT_TEST_SUITE( Test_get_unique );

  CPPUNIT_TEST(test_get_unique);

  CPPUNIT_TEST_SUITE_END()
  ;

public:
  void
  test_get_unique ();

};

#endif /* GET_UNIQUE_TEST_H_ */
