#include "inputSystem.h"
#include <SDL.h>
#include <iostream>

namespace vl
{
	const uint32_t key_space = SDL_SCANCODE_SPACE;
	const uint32_t key_up = SDL_SCANCODE_UP;
	const uint32_t key_down = SDL_SCANCODE_DOWN;
	const uint32_t key_left = SDL_SCANCODE_LEFT;
	const uint32_t key_right = SDL_SCANCODE_RIGHT;
	const uint32_t key_escape = SDL_SCANCODE_ESCAPE;

	void InputSystem::Initialize()
	{
		const uint8_t* keyboardState = SDL_GetKeyboardState(&m_numKeys);

		m_keybardState.resize(m_numKeys);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keybardState.begin());

		m_prevKeybardState = m_keybardState;
	}

	void InputSystem::Shutdown()
	{
		//
	}
	void InputSystem::Update()
	{
		SDL_Event event;
		SDL_PollEvent(&event);

		// save prev state
		m_prevKeybardState = m_keybardState;

		// save current state
		const uint8_t* keyboardState = SDL_GetKeyboardState(nullptr);
		std::copy(keyboardState, keyboardState + m_numKeys, m_keybardState.begin());

		//std::cout << (bool)m_keybardState[SDL_SCANCODE_1] << std::endl;

		//for (auto state : m_keybardState)
		//{
		//	std::cout << (bool)state;
		//}
		//std::cout << std::endl;
	}
}