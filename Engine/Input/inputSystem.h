#pragma once
#include <vector>
#include <cstdint>

namespace vl
{
	class InputSystem
	{
	public:
		InputSystem() = default;
		~InputSystem() = default;

		void Initialize();
		void Shutdown();

		void Update();

		bool GetKeyState(int key) { return m_keybardState[key]; }

	private:
		int m_numKeys;
		std::vector<uint8_t> m_keybardState;
		std::vector<uint8_t> m_prevKeybardState;
	};

	extern const uint32_t key_space;
	extern const uint32_t key_up;
	extern const uint32_t key_down;
	extern const uint32_t key_left;
	extern const uint32_t key_right;
}