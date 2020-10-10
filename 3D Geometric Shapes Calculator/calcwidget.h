#pragma once

#include <QtWidgets/QWidget>
#include "ui_widget.h"

namespace Ui {
    class CalcWidgetClass;
};

class CalcWidget : public QWidget {

    Q_OBJECT

public:
    explicit CalcWidget(QWidget *parent = Q_NULLPTR);                            
    virtual ~CalcWidget();
    void hide_allWidgets();

private slots:
    void show_CubeClass();
    void show_Menu();
    void show_SphereClass();
    void show_CylinderClass();
    void show_ConeClass();
    void show_TetrahedronClass();
    void show_EllipsoidClass();
    void on_coHeight_valueChanged(double d);
    void on_coRadius_valueChanged(double d);
    void on_spRadius_valueChanged(double d);
    void on_cuLength_valueChanged(double d);
    void on_cyHeight_valueChanged(double d);
    void on_cyRadius_valueChanged(double d);
    void on_teEdge_valueChanged(double d);
    void on_elAxis_valueChanged(double d);
    void on_elMajor_valueChanged(double d);
    void on_elMinor_valueChanged(double d);

private:
    Ui::CalcWidgetClass* ui;
};
