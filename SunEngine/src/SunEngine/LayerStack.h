#pragma once
#include "SunEngine/Core.h"
#include "SunEngine/Layer.h"
#include <vector>
namespace SunEngine
{
	class SUN_API LayerStack {
	public:
		LayerStack();
		~LayerStack();

		void PushLayer(Layer* layout);
		void PushOverlay(Layer* layout);
		void PopLayer(Layer* layout);
		void PopOverlay(Layer* layout);

		std::vector<Layer*>::iterator begin() { return m_Layers.begin(); }
		std::vector<Layer*>::iterator end() { return m_Layers.end(); }

	private:
		std::vector<Layer*> m_Layers;
		std::vector<Layer*>::iterator m_LayerInsert;
	};
}
