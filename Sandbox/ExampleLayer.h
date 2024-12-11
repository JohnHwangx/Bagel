#include <Bagel.h>

class ExampleLayer :public Bagel::Layer
{
public:
	ExampleLayer();	
	virtual ~ExampleLayer() = default;

	void OnUpdate(Bagel::Timestep ts) override;

	virtual void OnImGuiRender() override;

	void OnEvent(Bagel::Event& e) override;

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