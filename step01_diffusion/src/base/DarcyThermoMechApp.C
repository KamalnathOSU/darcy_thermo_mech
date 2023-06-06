//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

// Tutorial Includes
#include "DarcyThermoMechApp.h"

// MOOSE Includes
#include "AppFactory.h"
#include "MooseSyntax.h"
#include "ModulesApp.h"

InputParameters
DarcyThermoMechApp::validParams()
{
  InputParameters params = MooseApp::validParams();

  params.set<bool>("automatic_automatic_scaling") = false;
  params.set<bool>("use_legacy_material_output") = false;
	std::cout<<"INFO: Called "<<__FILE__<<"\n"<<__func__<<std::endl;

  return params;
}

DarcyThermoMechApp::DarcyThermoMechApp(InputParameters parameters) : MooseApp(parameters)
{
	std::cout<<"INFO: Called "<<__FILE__<<"\n"<<__func__<<std::endl;
  DarcyThermoMechApp::registerAll(_factory, _action_factory, _syntax);
}

void
DarcyThermoMechApp::registerApps()
{
	std::cout<<"INFO: Called "<<__FILE__<<"\n"<<__func__<<std::endl;
  registerApp(DarcyThermoMechApp);
}

void
DarcyThermoMechApp::registerAll(Factory & factory, ActionFactory & action_factory, Syntax & syntax)
{
	std::cout<<"INFO: Called "<<__FILE__<<"\n"<<__func__<<std::endl;
		
  Registry::registerObjectsTo(factory, {"DarcyThermoMechApp"});
  Registry::registerActionsTo(action_factory, {"DarcyThermoMechApp"});
  ModulesApp::registerAll(factory, action_factory, syntax);
}
