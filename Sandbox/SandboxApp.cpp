#include <Bagel.h>
#include "Platform/OpenGL/OpenGLShader.h"
#include "imgui.h"
#include "Sandbox2D.h"

//#include <Bagel/Core/EntryPoint.h>
#include <Bagel/EnterPoint.h>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class ExampleLayer :public Bagel::Layer
{
public:
	ExampleLayer()
		:Layer("Example"), m_CameraController(1280.0f / 720.0f)
	{
		float vertices[3 * 7] = {
				-0.5f, -0.5f, 0.0f, 0.8f, 0.2f, 0.8f, 1.0f,
				 0.5f, -0.5f, 0.0f, 0.2f, 0.3f, 0.8f, 1.0f,
				 0.0f,  0.5f, 0.0f, 0.8f, 0.8f, 0.2f, 1.0f
		};
		unsigned int indices[3] = { 0, 1, 2 };

		m_VertexArray = Bagel::VertexArray::Create();

		Bagel::Ref<Bagel::VertexBuffer> vertexBuffer;
		vertexBuffer.reset(Bagel::VertexBuffer::Create(vertices, sizeof(vertices)));

		Bagel::BufferLayout layout = {
			{Bagel::ShaderDataType::Float3, "a_Position"},
			{Bagel::ShaderDataType::Float4, "a_Color"}
		};

		vertexBuffer->SetLayout(layout);

		m_VertexArray->AddVertexBuffer(vertexBuffer);

		Bagel::Ref<Bagel::IndexBuffer> indexBuffer;
		indexBuffer.reset(Bagel::IndexBuffer::Create(indices, sizeof(indices) / sizeof(uint32_t)));

		m_VertexArray->SetIndexBuffer(indexBuffer);

		std::string vertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;
			layout(location = 1) in vec4 a_Color;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;
			out vec4 v_Color;

			void main()
			{
				v_Position = a_Position;
				v_Color = a_Color;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";
		std::string fragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			in vec4 v_Color;

			void main()
			{
				color = v_Color;
			}
		)";
		m_Shader = Bagel::Shader::Create("VertexPosColor", vertexSrc, fragmentSrc);

		float squareVertices[5 * 4] = {
			-0.5f, -0.5f, 0.0f, 0.0f, 0.0f,
			 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
			 0.5f,  0.5f, 0.0f, 1.0f, 1.0f,
			-0.5f,  0.5f, 0.0f, 0.0f, 1.0f
		};
		uint32_t squareIndices[6] = { 0, 1, 2, 2, 3, 0 };
		m_SquareVA = Bagel::VertexArray::Create();
		Bagel::Ref<Bagel::VertexBuffer> squareVB;
		squareVB.reset(Bagel::VertexBuffer::Create(squareVertices, sizeof(squareVertices)));
		squareVB->SetLayout({
			{ Bagel::ShaderDataType::Float3, "a_Position" },
			{ Bagel::ShaderDataType::Float2, "a_TexCoord" }
			});
		m_SquareVA->AddVertexBuffer(squareVB);

		Bagel::Ref<Bagel::IndexBuffer> squareIB;
		squareIB.reset(Bagel::IndexBuffer::Create(squareIndices, sizeof(squareIndices) / sizeof(uint32_t)));
		m_SquareVA->SetIndexBuffer(squareIB);

		std::string flatColorShaderVertexSrc = R"(
			#version 330 core

			layout(location = 0) in vec3 a_Position;

			uniform mat4 u_ViewProjection;
			uniform mat4 u_Transform;

			out vec3 v_Position;

			void main()
			{
				v_Position = a_Position;
				gl_Position = u_ViewProjection * u_Transform * vec4(a_Position, 1.0);	
			}
		)";

		std::string flatColorShaderFragmentSrc = R"(
			#version 330 core

			layout(location = 0) out vec4 color;
			in vec3 v_Position;
			uniform vec3 u_Color;

			void main()
			{
				color = vec4(u_Color, 1.0);
			}
		)";
		m_FlatColorShader = Bagel::Shader::Create("FlatColor", flatColorShaderVertexSrc, flatColorShaderFragmentSrc);

		auto textureShader = m_ShaderLibrary.Load("assets/shaders/Texture.glsl");

		m_Texture = Bagel::Texture2D::Create("assets/textures/Checkerboard.png"); 
		m_ChernoLogoTexture = Bagel::Texture2D::Create("assets/textures/ChernoLogo.png");

		std::dynamic_pointer_cast<Bagel::OpenGLShader>(textureShader)->Bind();
		std::dynamic_pointer_cast<Bagel::OpenGLShader>(textureShader)->UploadUniformInt("u_Texture", 0);
	}

	void OnUpdate(Bagel::Timestep ts) override
	{
		//BG_TRACE("DeltaTime:{0}, millionTime({1})", ts.GetSeconds(), ts.GetMilliseconds());
		m_CameraController.OnUpdate(ts);

		// Render
		Bagel::RenderCommand::SetClearColor({ 0.1f, 0.1f, 0.1f, 1 });
		Bagel::RenderCommand::Clear();

		Bagel::Renderer::BeginScene(m_CameraController.GetCamera());

		glm::mat4 scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1f));

		std::dynamic_pointer_cast<Bagel::OpenGLShader>(m_FlatColorShader)->Bind();
		std::dynamic_pointer_cast<Bagel::OpenGLShader>(m_FlatColorShader)->UploadUniformFloat3("u_Color", m_SquareColor);

		for (int y = 0; y < 20; y++)
		{
			for (int x = 0; x < 20; x++)
			{
				glm::vec3 pos(x * 0.11f, y * 0.11f, 0.0f);
				glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos) * scale;
				Bagel::Renderer::Submit(m_FlatColorShader, m_SquareVA, transform);
			}
		}

		auto textureShader = m_ShaderLibrary.Get("Texture");

		m_Texture->Bind();
		Bagel::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		m_ChernoLogoTexture->Bind();
		Bagel::Renderer::Submit(textureShader, m_SquareVA, glm::scale(glm::mat4(1.0f), glm::vec3(1.5f)));

		Bagel::Renderer::EndScene();
	}

	virtual void OnImGuiRender() override
	{
		ImGui::Begin("Settings");
		ImGui::ColorEdit3("Square Color", glm::value_ptr(m_SquareColor));
		ImGui::End();
	}

	void OnEvent(Bagel::Event& e) override
	{
		m_CameraController.OnEvent(e);
	}

private:

	Bagel::ShaderLibrary m_ShaderLibrary;
	Bagel::Ref<Bagel::Shader> m_Shader;
	Bagel::Ref<Bagel::VertexArray> m_VertexArray;

	Bagel::Ref<Bagel::Shader> m_FlatColorShader;
	Bagel::Ref<Bagel::VertexArray> m_SquareVA;

	Bagel::Ref<Bagel::Texture2D> m_Texture, m_ChernoLogoTexture;

	Bagel::OrthographicCameraController m_CameraController;

	glm::vec3 m_SquareColor = { 0.2f, 0.3f, 0.8f };
};

class Sandbox :public Bagel::Application
{
public:
	Sandbox()
	{
		//PushLayer(new ExampleLayer());
		//PushLayer(new Bagel::ImGuiLayer());
		PushLayer(new Sandbox2D());
	}

	~Sandbox()
	{

	}
};

Bagel::Application* Bagel::CreateApplication()
{
	return new Sandbox();
}