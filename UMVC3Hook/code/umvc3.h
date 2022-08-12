#pragma once
#include "mk10utils.h"

#define UMVC3HOOK_VERSION "0.1"


struct vector {
	float X;
	float Y;
	float Z;
};



struct camera_info {
	char pad[0x4C];
	float FOV;
	vector Pos; // 50
	char _pad[0x20];
	vector   Rotation;
};

struct gamepad_info {
	char data[736];
};

struct input_info {
	char header[88];
	gamepad_info gamepadinput[4];
};


void SetCamFOV(float value);
float GetCamFOV();

namespace UMVC3Hooks {
	void	HookProcessStuff();
	int64 HookCamera(int64 camera, int64 a2);
}

void HookInput(input_info * input);
