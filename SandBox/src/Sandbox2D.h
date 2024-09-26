#pragma once
#include <SunEngine.h>
class Sandbox2D : public SunEngine::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;
	virtual void OnAttach() override;
	virtual void OnDetach() override;
	void OnUpdate(SunEngine::Timestep ts) override;
	void OnEvent(SunEngine::Event& event) override;
	virtual void OnImGuiRender() override;
private:
	SunEngine::OrthographicCameraController m_CameraController;

	//Temp
	SunEngine::Ref<SunEngine::Shader> m_Shader;
	SunEngine::Ref<SunEngine::Texture2D> m_Texture;
	SunEngine::Ref<SunEngine::VertexArray> m_SquareVertexArray;
	SunEngine::Ref<SunEngine::IndexBuffer> m_IndexBuffer;

	struct TextureData {
		float TilingFactor = 1.0f;
		glm::vec4 Color = glm::vec4(1.0f);
	};

	TextureData m_TextureData;
};