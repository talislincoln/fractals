#ifndef _IDRAWABLE_H
#define _IDRAWABLE_H
#include "IMaster.h"
namespace fractal {
	class IDrawable : public IMaster
	{
	public:
		IDrawable();
		virtual ~IDrawable();

		//we'll probably create two private functions:
		//beginDraw and endDraw
		//it seems to be something required to draw in sdl
		virtual void draw() = 0;

		void setCanDraw(bool canDraw);
		bool getCanDraw() const;

	private:
		bool m_canDraw;
	};
}

#endif