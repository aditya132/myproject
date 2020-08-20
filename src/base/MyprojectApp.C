#include "MyprojectApp.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

InputParameters
MyprojectApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  // Do not use legacy DirichletBC, that is, set DirichletBC default for preset = true
  params.set<bool>("use_legacy_dirichlet_bc") = false;

  return params;
}

MyprojectApp::MyprojectApp(InputParameters parameters) : MooseApp(parameters)
{
  MyprojectApp::registerAll(_factory, _action_factory, _syntax);
}

MyprojectApp::~MyprojectApp() {}

void
MyprojectApp::registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  ModulesApp::registerAll(f, af, s);
  Registry::registerObjectsTo(f, {"MyprojectApp"});
  Registry::registerActionsTo(af, {"MyprojectApp"});

  /* register custom execute flags, action syntax, etc. here */
}

void
MyprojectApp::registerApps()
{
  registerApp(MyprojectApp);
}

/***************************************************************************************************
 *********************** Dynamic Library Entry Points - DO NOT MODIFY ******************************
 **************************************************************************************************/
extern "C" void
MyprojectApp__registerAll(Factory & f, ActionFactory & af, Syntax & s)
{
  MyprojectApp::registerAll(f, af, s);
}
extern "C" void
MyprojectApp__registerApps()
{
  MyprojectApp::registerApps();
}
