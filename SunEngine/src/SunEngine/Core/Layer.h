#pragma once
#include "SunEngine/Core/Base.h"
#include "SunEngine/Core/TimeStep.h"
#include "SunEngine/Events/Event.h"
namespace SunEngine {
	class Layer{
	public:
		Layer(const std::string& name = "Layout");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(Timestep ts) {}
		virtual void OnEvent(Event& e) {}
		virtual void OnImGuiRender() {}

		inline const std::string& GetName() const { return m_DebugName; }

	private:
		std::string m_DebugName;
	};
}


