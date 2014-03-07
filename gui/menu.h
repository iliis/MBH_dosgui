#ifndef __MENU_H_INCLUDED__
#define __MENU_H_INCLUDED__

#include <list>
#include "tools/expression_noboost.h"
#include "selectable_label.h"

///////////////////////////////////////////////////////////////////////////////
class Menu : public Widget
{
	std::list<SelectableLabel*> entries;
public:
	Expression<float> x,y,width,height;
	virtual ~Menu();

	void addEntry(string text);
	virtual void draw();

	std::list<SelectableLabel*>& getEntries() {return entries;}
};
///////////////////////////////////////////////////////////////////////////////

#endif
