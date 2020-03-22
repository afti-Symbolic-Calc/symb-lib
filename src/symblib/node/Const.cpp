﻿#include "Const.h"

namespace symb {
//------------------------------------------------------------------------------
Const::Const(Real val, const std::string& label)
    : Var(label, val, false)
{
}
//------------------------------------------------------------------------------
std::string Const::GetType() const
{
    return "Const";
}
//------------------------------------------------------------------------------
}
