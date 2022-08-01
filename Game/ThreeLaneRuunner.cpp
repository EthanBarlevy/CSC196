#include "ThreeLaneRuunner.h"
#include "Player.h"
#include "Enemy.h"
#include "Blocker.h"
#include "Coin.h"
#include "engine.h"

void ThreeLaneRunner::Initialize()
{
	m_scene = std::make_unique<vl::Scene>(this);
	
	// create assets
	m_font = std::make_unique<vl::Font>("Fonts/Arcade.ttf", 100);
	m_fontSmall = std::make_unique<vl::Font>("Fonts/Arcade.ttf", 30);

	m_titleTxt = std::make_unique<vl::Text>(m_font.get());
	m_titleTxt->Create(vl::g_renderer, "Game", { 255, 150, 255, 255 });

	m_scoreTxt = std::make_unique<vl::Text>(m_fontSmall.get());
	m_scoreTxt->Create(vl::g_renderer, "00000", { 255, 255, 255, 255 });

	vl::g_audioSystem.AddAudio("laser", "idk.wav");
	vl::g_audioSystem.AddAudio("explosion", "Explosion2.wav");
	vl::g_audioSystem.AddAudio("coin", "Pickup_Coin.wav");
	vl::g_audioSystem.AddAudio("neverHeardOfThisBefore", "bgm.mp3");

	// transforms
	vl::Transform transform;
	transform.position = vl::Vector2{ 250, 450 };
	transform.rotation = -math::HALFPI;
	transform.scale = 7;

	//players
	std::unique_ptr<tlr::Player> player = std::make_unique<tlr::Player>(vl::Model{ "Player.txt" }, transform);
	m_scene->Add(std::move(player));

	// idk what you are talking about this is a completely original song
	vl::g_audioSystem.PlayAudio("neverHeardOfThisBefore", true);
}

void ThreeLaneRunner::Shutdown()
{
}

void ThreeLaneRunner::Update()
{
	m_spawnTimer -= (float)vl::g_time.deltaTime;
	if (m_spawnTimer <= 0)
	{
		m_spawnTimer = vl::randomf(1, 3);

		generateRandom();
	}

	// update scene
	m_scene->Update();

	// update score text
	m_scoreTxt->Create(vl::g_renderer, std::to_string(m_score), {255, 150, 255, 255});
}

void ThreeLaneRunner::Draw(vl::Renderer& renderer)
{
	m_scene->Draw(renderer);
	m_titleTxt->Draw(renderer, { 150, 10 });
	m_scoreTxt->Draw(renderer, { 10, 10 });
}

void ThreeLaneRunner::generateRandom()
{
	//m_scene = std::make_unique<vl::Scene>();
	vl::Transform trans = { vl::Vector2{ 250, 150 }, -math::HALFPI, 0 };
	int pattern = vl::random(5);

	if (pattern == 0)
	{
		m_scene->Add(std::move(std::make_unique<tlr::Coin>(vl::Model{ "Coin.txt" }, trans, tlr::Coin::Lane::Left)));
	}
	if (pattern == 1)
	{
		m_scene->Add(std::move(std::make_unique<tlr::Blocker>(vl::Model{ "Jump.txt" }, trans, "jump",  tlr::Blocker::Lane::Left)));
		m_scene->Add(std::move(std::make_unique<tlr::Blocker>(vl::Model{ "Jump.txt" }, trans, "jump", tlr::Blocker::Lane::Middle)));
		m_scene->Add(std::move(std::make_unique<tlr::Blocker>(vl::Model{ "Jump.txt" }, trans, "jump", tlr::Blocker::Lane::Right)));
	}
	if (pattern == 2)
	{
		m_scene->Add(std::move(std::make_unique<tlr::Blocker>(vl::Model{ "Duck.txt" }, trans, "duck", tlr::Blocker::Lane::Left)));
		m_scene->Add(std::move(std::make_unique<tlr::Blocker>(vl::Model{ "Duck.txt" }, trans, "duck", tlr::Blocker::Lane::Middle)));
		m_scene->Add(std::move(std::make_unique<tlr::Coin>(vl::Model{ "Coin.txt" }, trans, tlr::Coin::Lane::Right)));
	}
	if (pattern == 3)
	{
		m_scene->Add(std::move(std::make_unique<tlr::Coin>(vl::Model{ "Coin.txt" }, trans, tlr::Coin::Lane::Left)));
		m_scene->Add(std::move(std::make_unique<tlr::Coin>(vl::Model{ "Coin.txt" }, trans, tlr::Coin::Lane::Middle)));
		m_scene->Add(std::move(std::make_unique<tlr::Coin>(vl::Model{ "Coin.txt" }, trans, tlr::Coin::Lane::Right)));
	}
	if (pattern == 4)
	{
		m_scene->Add(std::move(std::make_unique<tlr::Blocker>(vl::Model{ "Jump.txt" }, trans, "jump", tlr::Blocker::Lane::Left)));
		m_scene->Add(std::move(std::make_unique<tlr::Blocker>(vl::Model{ "Duck.txt" }, trans, "duck", tlr::Blocker::Lane::Middle)));
		m_scene->Add(std::move(std::make_unique<tlr::Blocker>(vl::Model{ "Jump.txt" }, trans, "jump", tlr::Blocker::Lane::Right)));
	}
}