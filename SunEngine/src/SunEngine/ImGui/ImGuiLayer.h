#pragma once
#include "SunEngine/Layer.h"
namespace SunEngine {
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		virtual void OnImGuiRender() override;
		void OnBegin();
		void OnEnd();
	private:
		float m_Time = 0.0f;
	};
}


