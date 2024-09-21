#include <SunEngine.h>
#include <imgui/imgui.h>
#include <Platform/OpenGL/OpenGLShader.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
class TestLayer :public SunEngine::Layer {
public:
	TestLayer()
		:Layer("Test"),
		m_CameraController(1280.0f / 720.0f, false)
	{
		
		#pragma region 绘制三角形
		m_VertexArray.reset(SunEngine::VertexArray::Create());

		float vertices[3 * 7] = {
		   -0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 1.0f, 1.0f,
			0.5f, -0.5f, 0.0f, 1.0f, 0.5f, 1.0f, 1.0f,
			0.0f,  0.5f, 0.0f, 1.0f, 1.0f, 0.2f, 1.0f
		};

		m_VertexBuffer.reset(SunEngine::VertexBuffer::Create(vertices, sizeof(vertices)));
		SunEngine::BufferLayout layout = {
			{SunEngine::ShaderDataType::Float3,"a_Position"},
			{SunEngine::ShaderDataType::Float4,"a_Color"}
		};
		m_VertexBuffer->SetLayout(layout);
		m_VertexArray->AddVertexBuffer(m_VertexBuffer);

		uint32_t indices[3] = { 0,1,2 };
		m_IndexBuffer.reset(SunEngine::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));
		m_VertexArray->SetIndexBuffer(m_IndexBuffer);

		std::string vertexSrc = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Pos;
			layout(location = 1) in vec4 a_Color;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;
			
			out vec3 v_Position;
			out vec4 v_Color;

			void main(){
				v_Position = a_Pos;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Pos,1.0);
			}
		)";

		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			in vec4 v_Color;

			void main(){	
				color = v_Color;
			}
		)";
		m_Shader = SunEngine::Shader::Create("Shader", vertexSrc, fragmentSrc);
		#pragma endregion

		#pragma region 绘制矩形
		m_SquareVertexArray.reset(SunEngine::VertexArray::Create());
		float vertices2[5 * 4] = {
		   -0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
		   -0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};

		SunEngine::Ref<SunEngine::VertexBuffer> squareVB;
		squareVB.reset(SunEngine::VertexBuffer::Create(vertices2, sizeof(vertices2)));
		squareVB->SetLayout({
			{SunEngine::ShaderDataType::Float3,"a_Position"},
			{SunEngine::ShaderDataType::Float2,"a_TexCoord"}
			});
		m_SquareVertexArray->AddVertexBuffer(squareVB);

		uint32_t indices2[6] = { 0,1,2,2,3,0 };
		SunEngine::Ref<SunEngine::IndexBuffer> squareIB;
		squareIB.reset(SunEngine::IndexBuffer::Create(indices2, sizeof(indices2) / sizeof(uint32_t)));
		m_SquareVertexArray->SetIndexBuffer(squareIB);

		#pragma region Shader2
		std::string vertexSrc2 = R"(
			#version 330 core
			
			layout(location = 0) in vec3 a_Pos;
			
			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;			
			out vec3 v_Position;
			out vec4 v_Color;

			void main(){
				v_Position = a_Pos;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Pos,1.0);
			}
		)";

		std::string fragmentSrc2 = R"(
			#version 330 core

			layout(location = 0) out vec4 color;

			in vec3 v_Position;
			uniform vec3 u_Color;

			void main(){	
				color = vec4(u_Color,1.0);
			}
		)";

		m_Shader2 = SunEngine::Shader::Create("Shader2", vertexSrc2, fragmentSrc2);
		#pragma endregion

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");
		m_AplhaTexture = SunEngine::Texture2D::Create("assets/textures/sun.png");
		m_Texture = SunEngine::Texture2D::Create("assets/textures/Checkerboard.png");
		std::dynamic_pointer_cast<SunEngine::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<SunEngine::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);

		#pragma endregion
	}

	void OnUpdate(SunEngine::Timestep ts) override
	{
		#pragma region 移动物体
		//物体变换
		if (SunEngine::Input::IsKeyPressed(SUN_KEY_J))
		{
			m_SquarePosition.x -= m_SquareSpeed * ts;
		}
		if (SunEngine::Input::IsKeyPressed(SUN_KEY_L))
		{
			m_SquarePosition.x += m_SquareSpeed * ts;
		}
		if (SunEngine::Input::IsKeyPressed(SUN_KEY_I))
		{
			m_SquarePosition.y += m_SquareSpeed * ts;
		}
		if (SunEngine::Input::IsKeyPressed(SUN_KEY_K))
		{
			m_SquarePosition.y -= m_SquareSpeed * ts;
		}
		#pragma endregion

		//摄像机控制更新
		m_CameraController.OnUpdate(ts);
		
		//清屏
		SunEngine::RendererCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1.0f });
		SunEngine::RendererCommand::Clear();
		
		//开始场景
		SunEngine::Renderer::BeginScene(m_CameraController.GetCamera());
		{
			m_Texture->Bind();
			SunEngine::Renderer::Submit(m_ShaderLibrary.Get("Texture"), m_SquareVertexArray,
				glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

			m_AplhaTexture->Bind();
			SunEngine::Renderer::Submit(m_ShaderLibrary.Get("Texture"), m_SquareVertexArray,
				glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));
		}
		SunEngine::Renderer::EndScene();
	}

	void OnEvent(SunEngine::Event& event) override
	{
		m_CameraController.OnEvent(event);
	}

	void OnImGuiRender() {
		//ImGui::Begin("Setting");
		//ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		//ImGui::End();
	}
private:
	SunEngine::ShaderLibrary m_ShaderLibrary;

	SunEngine::Ref<SunEngine::Shader> m_Shader, m_TextureShader;
	SunEngine::Ref<SunEngine::VertexArray> m_VertexArray;
	SunEngine::Ref<SunEngine::VertexBuffer> m_VertexBuffer;
	SunEngine::Ref<SunEngine::IndexBuffer> m_IndexBuffer;

	SunEngine::Ref<SunEngine::Shader> m_Shader2;
	SunEngine::Ref<SunEngine::VertexArray> m_SquareVertexArray;

	SunEngine::Ref<SunEngine::Texture2D> m_Texture,m_AplhaTexture;

	SunEngine::OrthographicCameraController m_CameraController;

	float m_SquareSpeed = 10;
	glm::vec3 m_SquarePosition;
	glm::vec3 m_SquareColor = { 0.8f, 0.2f, 0.3f };
};

class SandBox :public SunEngine::Application {
public:
	SandBox()
	{
		PushLayer(new TestLayer());
	}

	~SandBox()
	{
		
	}
};

SunEngine::Application* SunEngine::CreateApplication() {
	return new SandBox();
}