#pragma once
#include "Camera.h"
#include "Mouse.h"
#include "Vec2.h"
#include "MainWindow.h"
class CameraController
{
private:
	bool engadged = false;
	Mouse& mouse;
	Vec2 startingPos;
	Vec2 currentCamPos;
	Camera& cam;
public:
	CameraController(MainWindow & w, Camera& cam);
	~CameraController();
	void Update();
	
};

