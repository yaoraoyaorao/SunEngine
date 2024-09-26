#pragma once
#include "SunEngine/Core/Layer.h"
namespace SunEngine {
	class ImGuiLayer : public Layer
	{
	public:
		ImGuiLayer();
		~ImGuiLayer();
		virtual void OnAttach() override;
		virtual void OnDetach() override;
		void OnBegin();
		void OnEnd();
	private:
		float m_Time = 0.0f;
	};
}