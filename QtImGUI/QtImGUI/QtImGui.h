#ifndef QT_IMGUI_H
#define QT_IMGUI_H

#pragma once

#include <QWidget>
#include <QWindow>

namespace QtImGui {

#ifdef QT_WIDGETS_LIB
void initialize(QWidget *window);
#endif

void initialize(QWindow *window);
void newFrame();

}

#endif
