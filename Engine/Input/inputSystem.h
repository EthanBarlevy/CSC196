#pragma once
#include <vector>
#include <cstdint>

namespace vl
{
	class InputSystem
	{
	public:
		enum State
		{
			Idle,
			Pressed,
			Held,
			Released
		};
	public:
		InputSystem() = default;
		~InputSystem() = default;

		void Initialize();
		void Shutdown();

		void Update();

		bool GetKeyDown(int key) { return m_keybardState[key]; }

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
	extern const uint32_t key_escape;
}