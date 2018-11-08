#pragma once
#include "Camera.h"
#include "Mouse.h"
#include "Vec2.h"
#include "MainWindow.h"
class CameraController
{
public:
	Mouse& mouse;
	Vec2 startingPos;
	Vec2 currentCamPos;
	Camera& cam;
	bool engadged = false;
	CameraController(MainWindow & w, Camera& cam);
	void Update(float dt);
	~CameraController();
};

