#ifndef _IUSERINTERFACE_H
#define _IUSERINTERFACE_H

#include "IMaster.h"
#include <vector>
namespace fractal {
	class IUserInterface : public IMaster
	{
	public:
		IUserInterface();
		virtual ~IUserInterface();

		//we'll probably create two private functions:
		//beginDraw and endDraw
		//it seems to be something required to draw in sdl
		virtual void draw2D() = 0;

		inline void setUICanDraw(bool canDraw) {
			m_canUIDraw = canDraw;
		}
		inline bool getUICanDraw() const {
			return m_canUIDraw;
		}
	private:
		//flag for setting?  visable
		bool m_canUIDraw;
	};
}

#endif