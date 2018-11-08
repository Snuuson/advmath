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

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd ),
	ct(gfx)
{
	for (float i = 0; i < 100; i++) {
		cell0.MoveBy(Vec2(i,0));
		allCells.emplace_back(cell0.GetDrawableCell());
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
}

void Game::ComposeFrame()
{

	//TODO asdsalkdasdksad
	cell0.MoveTo(Vec2(0, 0));
	allCells.clear();
	for (float i = 0; i < 100; i++) {
		cell0.MoveTo(Vec2(i, 0));
		allCells.emplace_back(cell0.GetDrawableCell());
	}
	for each (DrawableCell* dc in allCells)
	{
		
		dc->ScaleIndependent(4.0f, 4.0);
	}
	
	
		ct.Do(allCells);
	
	DrawableCell* tmp = cell0.GetDrawableCell();

	cell0.MoveTo(Vec2(0,0));
	tmp = cell0.GetDrawableCell();
	ct.Do(tmp);
	cell0.MoveTo(Vec2(0, 1));
	tmp = cell0.GetDrawableCell();
	ct.Do(tmp);
	cell0.MoveTo(Vec2(0, 2));
	tmp = cell0.GetDrawableCell();
	ct.Do(tmp);
	cell0.MoveTo(Vec2(0, 3));
	tmp = cell0.GetDrawableCell();
	ct.Do(tmp);



	gfx.PutPixel(gfx.ScreenWidth / 2, gfx.ScreenHeight/2, Colors::White);

	


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
