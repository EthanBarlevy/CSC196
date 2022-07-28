#pragma once
#include "Framework/game.h"

namespace vl
{
	class Font;
	class Text;
}

class ThreeLaneRunner : public vl::Game
{
public:
	ThreeLaneRunner() = default;
	~ThreeLaneRunner() = default;

	virtual void Initialize() override;
	virtual void Shutdown() override;
	virtual void Update() override;
	virtual void Draw(vl::Renderer& renderer) override;

	void generateRandom();
private:
	float m_spawnTimer;
	std::unique_ptr<vl::Font> m_font;
	std::unique_ptr<vl::Font> m_fontSmall;
	std::unique_ptr<vl::Text> m_titleTxt;
	std::unique_ptr<vl::Text> m_scoreTxt;
};