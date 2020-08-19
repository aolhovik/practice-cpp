/*
 * missing_packets_test.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: andrii.olkhovyk
 */

#include "missing_packets_test.h"
#include "missing_packets.h"

#include <cppunit/config/SourcePrefix.h>
#include <iostream>

using namespace std;

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION(MissingPacketsTest);

void
MissingPacketsTest::test_missing_packets ()
{
    {
      tPacket packets[1] =
	{
	  { 0, 0 } };
      MissingPacketsCounter counter (reinterpret_cast<const char*> (packets),
				     sizeof(packets));
      CPPUNIT_ASSERT(0 == counter.getCount (0));
    }
    {
      tPacket packets[2] =
	{
	  { 0, 0 },
	  { 0, 1 } };
      MissingPacketsCounter counter (reinterpret_cast<const char*> (packets),
				     sizeof(packets));
      CPPUNIT_ASSERT(0 == counter.getCount (0));
    }
    {
      tPacket packets[2] =
	{
	  { 0, 0 },
	  { 0, 0 } };
      MissingPacketsCounter counter (reinterpret_cast<const char*> (packets),
				     sizeof(packets));
      CPPUNIT_ASSERT(15 == counter.getCount (0));
    }

    {
      tPacket packets[2] =
	{
	  { 0, 5 },
	  { 0, 7 } };
      MissingPacketsCounter counter (reinterpret_cast<const char*> (packets),
				     sizeof(packets));
      CPPUNIT_ASSERT(1 == counter.getCount (0));
    }

    {
      tPacket packets[4] =
	{
	  { 0, 5 },
	  { 1, 0 },
	  { 0, 7 },
	  { 1, 1 } };
      MissingPacketsCounter counter (reinterpret_cast<const char*> (packets),
				     sizeof(packets));
      CPPUNIT_ASSERT(1 == counter.getCount (0));
      CPPUNIT_ASSERT(0 == counter.getCount (1));
    }
}
