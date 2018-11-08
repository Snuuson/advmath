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
	cam.Scale(1);
	cam.MoveTo(Vec2(-100, -100));
	cell1.ChangeColor(Colors::Magenta);
	for (int i = 0; i < 1000; i++) {
		movingCells.emplace_back(new Cell({25,25},10));
	}
	for each (Cell* c in movingCells)
	{
		int min = 0;
		int max = 255;
		int r = rand() % (max - min + 1) + min;
		int g = rand() % (max - min + 1) + min;
		int b = rand() % (max - min + 1) + min;
		Color col = Color(r, g, b);
		c->ChangeColor(col);
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
	camContrl.Update(0.0f);
	float dt = ft.Mark();
	for each (Cell* c in movingCells)
	{
		c->Update(dt);
	}
}

void Game::ComposeFrame()
{

	//TODO asdsalkdasdksad
	
	
	allCells.clear();
	movingCellsDrawables.clear();
	for each (Cell* c in movingCells)
	{
		movingCellsDrawables.emplace_back(c->GetDrawableCell());
	}
	for (float i = 0; i < 50; i++) {
		for (float j = 0; j < 50; j++) {
			cell0.MoveTo(Vec2(i, j));
			int min = 0;
			int max = 255;
			int r = rand() % (max - min + 1) + min;
			int g = rand() % (max - min + 1) + min;
			int b = rand() % (max - min + 1) + min;
			Color c = Color(r, g, b);
			cell0.ChangeColor(c);
			allCells.emplace_back(cell0.GetDrawableCell());
		}
	}
	
	
	
	
	
	cam.Do(allCells);
	cam.Do(movingCellsDrawables);
	
	


	//gfx.PutPixel(gfx.ScreenWidth / 2, gfx.ScreenHeight/2, Colors::White);

	


	//DrawableCell dc1 = cell0.GetDrawableCell();
	//DrawableCell dc2 = cell0.GetDrawableCell();
	//DrawableCell dc3 = cell0.GetDrawableCell();
	//dc->Translate(Vec2(0*cell0.size, 0 * cell0.size));
	//dc1.Translate(Vec2(1 * cell0.size,1 * cell0.size));
	//dc2.Translate(Vec2(2 * cell0.size, 2 * cell0.size));
	//dc3.Translate(Vec2(3 * cell0.size, 3 * cell0.size));
	//int scale = 2;
	//dc->Scale(scale);
//	dc1.Scale(scale);
//dc2.Scale(scale);
	//dc3.Scale(scale);
	//dc->Render(gfx);
	//dc1.Render(gfx);
	//dc2.Render(gfx);
//	dc3.Render(gfx);
	
}
