#ifndef __LABEL_H_INCLUDED__
#define __LABEL_H_INCLUDED__

#include <string>
#include "widget.h"
#include "gui_manager.h"
#include "tools/expression_noboost.h"
#include "tools/stringhelpers.h"

///////////////////////////////////////////////////////////////////////////////
class Label : public Widget
{
	Expression<int>   int_val;
	Expression<float> float_val;
public:
	Expression<float> x, y, width, height;
	std::string text;

	Label(std::string text) {setText(text);};

	void setText(std::string text);
	void setInt(Expression<int>& val);
	void setFloat(Expression<float>& val);
	virtual void draw();
};
///////////////////////////////////////////////////////////////////////////////

#endif
