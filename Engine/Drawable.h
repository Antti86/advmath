#pragma once

#include "Graphics.h"
#include <vector>
#include "Vec2.h"

class Drawable
{
public:
	Drawable( const std::vector<Vec2>& model,Color c )
		:
		c( c ),
		model( &model )
	{}
	void Translate( const Vec2& translation_in )
	{
		translation += translation_in;
	}
	void Scale( float scale_in )
	{
		scale_x *= scale_in;
		scale_y *= scale_in;
		translation *= scale_in;
	}
	void ScaleIndependent( float scale_in_x,float scale_in_y )
	{
		scale_x *= scale_in_x;
		scale_y *= scale_in_y;
		translation.x *= scale_in_x;
		translation.y *= scale_in_y;
	}
	void Rotate( float angle_in )
	{
		angle += angle_in;
		translation.Rotate( angle_in );
	}
	float GetAngle() const
	{
		return angle;
	}
	void Render( Graphics& gfx ) const
	{
		gfx.DrawClosedPolyline( *model,translation,scale_x,scale_y,angle,c );
	}
private:
	Color c;
	const std::vector<Vec2>* model;
	float angle = 0.0f;
	Vec2 translation = {0.0f,0.0f};
	float scale_x = 1.0f;
	float scale_y = 1.0f;
};