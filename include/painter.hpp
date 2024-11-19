#pragma once
#include "abstract_painter.hpp"
#include "point.hpp"

class Painter : public AbstractPainter {
public:
    virtual void DrawImage(Point topLeft, Point bottomRight, char** image) override;
    virtual void WriteText(Point position, const char* text) override; 
};


