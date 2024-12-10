#pragma once

#include "Bagel.h"

class Sandbox2D : public Bagel::Layer
{
public:
	Sandbox2D();
	virtual ~Sandbox2D() = default;

	virtual void OnAttach() override;
	virtual void OnDetach() override;

	void OnUpdate(Bagel::Timestep ts) override;
	virtual void OnImGuiRender() override;
	void OnEvent(Bagel::Event& e) override;
private:
	Bagel::OrthographicCameraController m_CameraController;

	// Temp
	Bagel::Ref<Bagel::VertexArray> m_SquareVA;
	Bagel::Ref<Bagel::Shader> m_FlatColorShader;
	Bagel::Ref<Bagel::Texture2D> m_CheckerboardTexture;

	glm::vec4 m_SquareColor = { 0.2f, 0.3f, 0.8f, 1.0f };
};