﻿#include "Const.h"

namespace symb
{

Const::Const(Real val, const std::string& label)
	: Var(label, false, val)
{
}

}
