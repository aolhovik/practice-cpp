/*
 * missing_packets_test.h
 *
 *  Created on: Aug 19, 2020
 *      Author: andrii.olkhovyk
 */

#ifndef MISSING_PACKETS_MISSING_PACKETS_TEST_H_
#define MISSING_PACKETS_MISSING_PACKETS_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

class MissingPacketsTest : public CPPUNIT_NS::TestFixture
{
CPPUNIT_TEST_SUITE( MissingPacketsTest );
  CPPUNIT_TEST(test_missing_packets);CPPUNIT_TEST_SUITE_END()
  ;

public:
  void
  test_missing_packets ();
};

#endif /* MISSING_PACKETS_MISSING_PACKETS_TEST_H_ */
