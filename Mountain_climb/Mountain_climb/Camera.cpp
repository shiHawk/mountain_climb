#include "DxLib.h"
#include "Camera.h"
#include "Player.h"
#include "game.h"


const float CameraScrollRangeH = 300;

void InitCamera(Camera& camera)
{
	camera.pos = VGet(0, 0, 0);
}

void UpdateCamera(Camera& camera, const Player& player)
{
	if (player.GetTop() > camera.pos.y + (CameraScrollRangeH * 0.5f))
	{
		camera.pos.y = player.GetTop() - (CameraScrollRangeH * 0.5f);
	}
	else if (player.GetTop() < camera.pos.y - (CameraScrollRangeH * 0.5f))
	{
		camera.pos.y = player.GetTop() + (CameraScrollRangeH * 0.5f);
	}

	camera.drawOffset.x = camera.pos.x * -1;
	camera.drawOffset.y = camera.pos.y * -1;

	camera.drawOffset.x = camera.drawOffset.x + (Game::kScreenWidth * 0.5f);
	camera.drawOffset.y = camera.drawOffset.y + (Game::kScreenHeight * 0.5f);
}
