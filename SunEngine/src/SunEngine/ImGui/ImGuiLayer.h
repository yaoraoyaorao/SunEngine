#pragma once
#include "SunEngine/Layer.h"
namespace SunEngine {
	class SUN_API ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnUpdate() override;
		virtual void OnEvent(Event& e) override;
	private:
		float m_Time = 0.0f;
	};
}


