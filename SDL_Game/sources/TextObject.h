#pragma once
#include "Object.h"
#include "TextRenderer.h"
class TextObject : public Object {
private:
	TextRenderer* tr;
public:
	TextObject(std::string text)
		: Object() {
		tr = new TextRenderer(transform,text);
		renderer = tr;
		tr->SetColor(SDL_Color{ 205,50,120,255 });
	}

	void SetText(std::string text) {
		tr->SetText(text);
	}



};