/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
 *	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
 *																						  *
 *	This file is part of The Chili DirectX Framework.									  *
 *																						  *
 *	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
 *	it under the terms of the GNU General Public License as published by				  *
 *	the Free Software Foundation, either version 3 of the License, or					  *
 *	(at your option) any later version.													  *
 *																						  *
 *	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
 *	GNU General Public License for more details.										  *
 *																						  *
 *	You should have received a copy of the GNU General Public License					  *
 *	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
 ******************************************************************************************/
#include "MainWindow.h"
#include "Game.h"
#include <random>

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ct(gfx),
	cam(ct),
	camContrl(wnd,cam)
{
	//Zoom out
	cam.Scale(0.5);

	//Center Camera
	cam.MoveTo(Vec2(-150,-150));
	
	//Initalize Cell-Colletions
	
	for (int i = 0; i < CellCount; i++) {
		movingCells.emplace_back(new Cell({ 10,10 },10));
		movingCells1.emplace_back(new Cell({ 0,0 }, 10));
	}

	//Choose Color for movingCells
	for each (Cell* c in movingCells)
	{
		c->SetColor(Colors::White);
		c->SetStoredColor(Colors::White);

	}
	//Choose Color for movingCells1
	for each (Cell* c in movingCells1)
	{
		c->SetColor(Colors::Green);
		c->SetStoredColor( Colors::Green );

	}
	
	
	
}



void Game::Go()
{
		gfx.BeginFrame();
		UpdateModel();
		ComposeFrame();
		gfx.EndFrame();
}

void Game::UpdateModel()
{

	camContrl.Update();

	//Update Cells
	float dt = ft.Mark();
	for each (Cell* c in movingCells)
	{
		c->Update1(dt);
	}
	dt += ft.Mark();
	for each (Cell* c in movingCells1)
	{
		c->Update1(dt);
	}

	//Reset the Game with UP-Key
	if (wnd.kbd.KeyIsPressed(VK_UP)) {
		for each (Cell* c in movingCells) 
		{
			c->SetSpeed(1);
			c->MoveTo(Vec2( 50,50)) ;
			c->SetColor(Colors::White);
		}
		for each (Cell* c in movingCells1)
		{
			c->SetSpeed(1);
			c->MoveTo(Vec2(0, 0));
			c->SetColor(Colors::Green);
		}
	}
}

Color Game::CreateRandomColor()
{
	int min = 0;
	int max = 255;
	int r = rand() % (max - min + 1) + min;
	int g = rand() % (max - min + 1) + min;
	int b = rand() % (max - min + 1) + min;
	Color col = Color(r, g, b);
	return col;
}

void Game::ComposeFrame()
{

	
	
	//Clear DrawableVectors
	
	movingCellsDrawables.clear();
	movingCellsDrawables0.clear();

	//Fill DrawableVectors
	for each (Cell* c in movingCells)
	{
		movingCellsDrawables.emplace_back(c->GetDrawableCell());
	}
	for each (Cell* c in movingCells1)
	{
		movingCellsDrawables0.emplace_back(c->GetDrawableCell());
	}

	
	//CollisionCheck
	for each (Cell* c in movingCells)
	{
		for each(Cell* c1 in movingCells1) {
			if (c->GetPos() == c1->GetPos()) {

				//Assign the same random Color to collided Cells
				Color col = CreateRandomColor();
				
				c->SetColor(col);
				c->SetStoredColor(col);

				c1->SetColor(col);
				c1->SetStoredColor(col);

			}
		}
	}
	
	
	
	
	//Push into Pipeline
	cam.Do(movingCellsDrawables);
	cam.Do(movingCellsDrawables0);
	
	


	
}
