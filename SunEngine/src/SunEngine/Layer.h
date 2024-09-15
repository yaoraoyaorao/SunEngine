#pragma once
#include "SunEngine/Core.h"
#include "SunEngine/Events/Event.h"
namespace SunEngine {
	class SUN_API Layer{
	public:
		Layer(const std::string& name = "Layout");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate() {}
		virtual void OnEvent(Event& e) {}

		inline const std::string& GetName() const { return m_DebugName; }

	private:
		std::string m_DebugName;
	};
}


