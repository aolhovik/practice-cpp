/*
 * tower_of_hanoi_test.h
 *
 *  Created on: Aug 12, 2020
 *      Author: andrii.olkhovyk
 */

#ifndef TOWER_OF_HANOI_TEST_H_
#define TOWER_OF_HANOI_TEST_H_

#include <cppunit/extensions/HelperMacros.h>

class TowerOfHanoiTest : public CPPUNIT_NS::TestFixture
{
CPPUNIT_TEST_SUITE( TowerOfHanoiTest );
  CPPUNIT_TEST(test_solve);
  CPPUNIT_TEST(test_invalid_initial);CPPUNIT_TEST_SUITE_END()
  ;

public:
  void
  test_solve ();

  void
  test_invalid_initial ();
};

#endif /* TOWER_OF_HANOI_TEST_H_ */
