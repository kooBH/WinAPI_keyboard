#include <stdio.h>     
#include <Windows.h>

int main() {

	bool run = true;

	bool event;
	bool key_pressed[0xFF] = { 0, };
	while (run) {
		event = false;
		

		// Key | 0x01 : Left mouse button ~ 0xFE : Clear key
		for (int key = 0x01; key < 0xFF; key++) {

			/*
			  VK_HANGUEL
			  0x15
		      IME Hanguel mode(maintained for compatibility; use VK_HANGUL)

			  is always pressed
			  */
			//if (key == 0x15)continue;

			if (GetAsyncKeyState(key) < 0 && !key_pressed[key]) {
				key_pressed[key] = true;
				event = true;
				printf("PRESS %X\n",key);
			}

			if (GetAsyncKeyState(key) >= 0 && key_pressed[key]) {
				key_pressed[key] = false;
				event = true;
				printf("RELEASE %X\n", key);
			}
			
		}

		if (event)
			printf("CLICK\n");
		
		Sleep(100);
		
	}

	return 0;
}