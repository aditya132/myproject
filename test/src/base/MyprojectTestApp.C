//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html
#include "MyprojectTestApp.h"
#include "MyprojectApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
MyprojectTestApp::validParams()
{
  InputParameters params = MyprojectApp::validParams();
  return params;
}

MyprojectTestApp::MyprojectTestApp(InputParameters parameters) : MooseApp(parameters)
{
  MyprojectTestApp::registerAll(
      _factory, _action_factory, _syntax, getParam<bool>("allow_test_objects"));
}

MyprojectTestApp::~MyprojectTestApp() {}

void
MyprojectTestApp::registerAll(Factory & f, ActionFactory & af, Syntax & s, bool use_test_objs)
{
  MyprojectApp::registerAll(f, af, s);
  if (use_test_objs)
  {
    Registry::registerObjectsTo(f, {"MyprojectTestApp"});
    Registry::registerActionsTo(af, {"MyprojectTestApp"});
  }
}

void
MyprojectTestApp::registerApps()
{
  registerApp(MyprojectApp);
  registerApp(MyprojectTestApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
// External entry point for dynamic application loading
extern "C" void
MyprojectTestApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MyprojectTestApp::registerAll(f, af, s);
}
extern "C" void
MyprojectTestApp__registerApps()
{
  MyprojectTestApp::registerApps();
}
