/*
 * main.cpp
 *
 *  Created on: Aug 19, 2020
 *      Author: andrii.olkhovyk
 */
#include <cppunit/CompilerOutputter.h>
#include <cppunit/extensions/TestFactoryRegistry.h>
#include <cppunit/ui/text/TestRunner.h>

bool
run_tests ()
{
  // Get the top level suite from the registry
  CppUnit::Test *suite =
      CppUnit::TestFactoryRegistry::getRegistry ().makeTest ();

  // Adds the test to the list of test to run
  CppUnit::TextUi::TestRunner runner;
  runner.addTest (suite);

  // Change the default outputter to a compiler error format outputter
  runner.setOutputter (
      new CppUnit::CompilerOutputter (&runner.result (), std::cerr));
  return runner.run ();
}

int
main ()
{
  return run_tests ();
}
