//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#include "HeatConductionOutflow.h"

registerMooseObject("DarcyThermoMechApp", HeatConductionOutflow);

InputParameters
HeatConductionOutflow::validParams()
{
  InputParameters params = ADIntegratedBC::validParams();
  params.addClassDescription("Compute the outflow boundary condition.");
	std::cout<<"INFO: Called "<<__FILE__<<"\n"<<__func__<<std::endl;
  return params;
}

HeatConductionOutflow::HeatConductionOutflow(const InputParameters & parameters)
  : ADIntegratedBC(parameters),
    _thermal_conductivity(getADMaterialProperty<Real>("thermal_conductivity"))
{
	std::cout<<"INFO: Called "<<__FILE__<<"\n"<<__func__<<std::endl;
}

ADReal
HeatConductionOutflow::computeQpResidual()
{
  return -_test[_i][_qp] * _thermal_conductivity[_qp] * _grad_u[_qp] * _normals[_qp];
}
