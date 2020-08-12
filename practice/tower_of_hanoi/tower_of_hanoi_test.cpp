/*
 * tower_of_hanoi_test.cpp
 *
 *  Created on: Aug 12, 2020
 *      Author: andrii.olkhovyk
 */

#include "tower_of_hanoi.h"
#include "tower_of_hanoi_test.h"

#include <cppunit/config/SourcePrefix.h>
#include <iostream>

using namespace std;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(TowerOfHanoiTest);

void
TowerOfHanoiTest::test_solve ()
{
  const TowerOfHanoi::tLane initial =
    {
      { 4 },
      { 3 },
      { 2 },
      { 1 } };
  TowerOfHanoi game (initial);
  game.solve ();
  CPPUNIT_ASSERT(game.validate (initial));

    {
      const TowerOfHanoi::tLane initial =
	{
	  { 4 },
	  { 4 },
	  { 4 },
	  { 4 } };
      TowerOfHanoi game (initial);
      game.solve ();
      CPPUNIT_ASSERT(game.validate (initial));
    }

    {
      const TowerOfHanoi::tLane initial =
	{
	  { 1 } };
      TowerOfHanoi game (initial);
      game.solve ();
      CPPUNIT_ASSERT(game.validate (initial));
    }

    {
      const TowerOfHanoi::tLane initial =
	{ };
      TowerOfHanoi game (initial);
      game.solve ();
      CPPUNIT_ASSERT(game.validate (initial));
    }
}

void
TowerOfHanoiTest::test_invalid_initial ()
{
  const TowerOfHanoi::tLane initial =
    {
      { 1 },
      { 2 } };
  bool bLogicError = false;
  try
    {
      TowerOfHanoi game (initial);
    }
  catch (std::logic_error&)
    {
      bLogicError = true;
    }

  CPPUNIT_ASSERT(true == bLogicError);
}
