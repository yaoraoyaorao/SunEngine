#include "sunpch.h"
#include "LayerStack.h"

namespace SunEngine {
	LayerStack::LayerStack() {

	}

	LayerStack::~LayerStack() {
		for (Layer* layout : m_Layers)
			delete layout;
	}

	void LayerStack::PushLayer(Layer* layout) {
		m_Layers.emplace(m_Layers.begin() + m_LayerInsertIndex, layout);
		m_LayerInsertIndex++;
	}

	void LayerStack::PushOverlay(Layer* layout) {
		m_Layers.emplace_back(layout);
	}

	void LayerStack::PopLayer(Layer* layout) {
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layout);
		if (it != m_Layers.end())
		{
			m_Layers.erase(it);
			m_LayerInsertIndex--;
		}
	}

	void LayerStack::PopOverlay(Layer* layout) {
		auto it = std::find(m_Layers.begin(), m_Layers.end(), layout);
		if (it != m_Layers.end())
			m_Layers.erase(it);
	}
}