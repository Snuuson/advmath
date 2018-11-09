#include "CameraController.h"


CameraController::CameraController(MainWindow & w, Camera& cam)
	:
	mouse(w.mouse),
	cam(cam)
{
	
}

CameraController::~CameraController()
{
}

void CameraController::Update()
{

	//Mouse Drag-Navigation
	if (mouse.LeftIsPressed()) {
		if (engadged == false) {
			startingPos.x = (float)mouse.GetPosX();
			startingPos.y = (float)mouse.GetPosY();
			engadged = true;
		}
		else {
			Vec2 offset = Vec2(startingPos.x - mouse.GetPosX(),( startingPos.y - mouse.GetPosY()) * -1);
			cam.MoveTo(currentCamPos-offset);
			
		}
	}
	else {
		engadged = false;
		currentCamPos = cam.GetPos();
		
		
	}

	//Zoom
	Mouse::Event e = mouse.Read();
	if (e.IsValid()) {
		switch (e.GetType())
		{
		case Mouse::Event::Type::WheelUp:
			cam.Scale(1.05);
			break;
		case Mouse::Event::Type::WheelDown:
			cam.Scale(0.95);
			break;
		default:
			break;
		}
	}
	


	

}


