#pragma once

struct Player;
struct Camera
{
	VECTOR pos;
	VECTOR drawOffset;
}; 

void InitCamera(Camera& camera);
void UpdateCamera(Camera& camera,const Player& player);