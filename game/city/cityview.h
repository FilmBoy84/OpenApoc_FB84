#pragma once

#include "game/tileview/tileview.h"

namespace OpenApoc {

class Form;

class CityView : public TileView
{
private:
	Form *ui;
public:
	CityView(Framework &fw);
	virtual ~CityView();
	virtual void Update(StageCmd * const cmd);
	virtual void Render();
	virtual void EventOccurred(Event *e);
};

}; //namespace OpenApoc
