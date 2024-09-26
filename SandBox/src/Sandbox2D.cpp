#include "Sandbox2D.h"
#include <imgui/imgui.h>
#include <glm/gtc/type_ptr.hpp>
#include <Platform/OpenGL/OpenGLShader.h>
#include <chrono>

Sandbox2D::Sandbox2D() : 
	Layer("SandBox2D"),
	m_CameraController(1280.0f / 720.0f, false)
{

}

void Sandbox2D::OnAttach()
{
	m_Texture = SunEngine::Texture2D::Create("assets/textures/Checkerboard.png");
}

void Sandbox2D::OnDetach()
{

}

void Sandbox2D::OnUpdate(SunEngine::Timestep ts)
{

	m_CameraController.OnUpdate(ts);
	SunEngine::RendererCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
	SunEngine::RendererCommand::Clear();

	SunEngine::Renderer2D::BeginScene(m_CameraController.GetCamera());
	{
		//SunEngine::Renderer2D::DrawRotatedQuad({ 0.6f,0.6f }, { 0.75f,0.75f }, glm::radians(-45.0f), {0.1f,0.3f,0.2f,1.0f});
		SunEngine::Renderer2D::DrawQuad({ 0.5f, 0.5f }, { 0.5f,0.75f }, { 0.2f,0.3f,0.8f,1.0f });
		SunEngine::Renderer2D::DrawQuad({ -1.0f,0.0f }, { 0.8f,0.8f }, { 0.1f,0.12f,0.11f,1.0f });
		SunEngine::Renderer2D::DrawQuad({ 0.5f, 0.5f }, { 10.0f,10.0f }, m_Texture, m_TextureData.TilingFactor, m_TextureData.Color);
	}
	SunEngine::Renderer2D::EndScene();

}

void Sandbox2D::OnEvent(SunEngine::Event& event)
{
	m_CameraController.OnEvent(event);
}

void Sandbox2D::OnImGuiRender()
{
	ImGui::Begin("Setting");
	{
		ImGui::ColorEdit4("Square Color", glm::value_ptr(m_TextureData.Color));

		ImGui::DragFloat("Texture", &m_TextureData.TilingFactor, 1.0f, 1.0f, 10.0f);
	}
	ImGui::End();
}
