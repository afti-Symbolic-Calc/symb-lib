﻿#include "Prod.h"
#include "Const.h"
#include "Sum.h"

namespace symb
{
//------------------------------------------------------------------------------
Prod::Prod(Expression&& left, Expression&& right)
	:BinaryExpressionBase(std::move(left), std::move(right))
{
}
//------------------------------------------------------------------------------
Prod::Prod(const Expression& left, const Expression& right)
	: Prod(left->Copy(), right->Copy())
{
}
//------------------------------------------------------------------------------
Expression Prod::RowExpression() const
{
	return std::unique_ptr<Prod>();
}
//------------------------------------------------------------------------------
Real Prod::ComputeImpl(Real left, Real right) const
{
	return left * right;
}
//------------------------------------------------------------------------------
Expression Prod::ExecuteImpl()
{
	return Copy();
}
//------------------------------------------------------------------------------
Expression Prod::DerivateImpl(Expression&& left, Expression&& right) const
{
	auto leftProd = std::make_unique<Prod>(std::move(left), GetRightArg()->Copy());
	auto rightProd = std::make_unique<Prod>(GetLeftArg()->Copy(), std::move(right));

	auto derivative = std::make_unique<Sum>(std::move(leftProd), std::move(rightProd));

	return derivative->Execute();
}
//------------------------------------------------------------------------------
Expression Prod::CopyImpl(Expression&& left, Expression&& right) const
{
	return std::make_unique<Prod>(std::move(left), std::move(right));
}
//------------------------------------------------------------------------------	
}
