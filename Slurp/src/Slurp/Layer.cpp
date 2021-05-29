#include "pch.h"
#include "Layer.h"

namespace Slurp {
	Layer::Layer(const std::string& debugName /*= "Layer"*/)
		: m_DebugName(debugName)
	{}

	Layer::~Layer()
	{}
}
