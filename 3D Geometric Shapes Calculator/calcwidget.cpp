#define _USE_MATH_DEFINES

#include "calcwidget.h"
#include "ui_widget.h"
#include <cmath>

namespace Cube {
    double computeVolume(double x) { return std::pow(x, 3); }
    double computeArea(double x) { return 6 * std::pow(x, 2); }
};

namespace Sphere {
    double computeVolume(double r) { return (4 * M_PI * std::pow(r, 3)) / 3; }
    double computeArea(double r) { return 4 * M_PI * std::pow(r, 2); }
};

namespace Cylinder {
    double computeVolume(double r, double h) { return M_PI * h * std::pow(r, 2); }
    double computeArea(double r, double h) {
        double arg1 = 2 * M_PI * r * h;
        double arg2 = 2 * M_PI * r * r;
        return arg1 + arg2;
    }
};

namespace Cone {
    double computeVolume(double r, double h) { return (h * M_PI * std::pow(r, 2)) / 3; }
    double computeArea(double r, double h) {
        double arg1 = r * M_PI;
        double arg2 = r + std::sqrt(std::pow(h, 2) + std::pow(r, 2));
        return arg1 * arg2;
    }
};

namespace Tetrahedron {
    double computeVolume(double a) { return std::pow(a, 3) / (6 * M_SQRT2); }
    double computeArea(double a) { return std::sqrt(3) * std::pow(a, 2); }
};

namespace Ellipsoid {
    double computeVolume(double a, double b, double c) { return (4 * M_PI * a * b * c) / 3; }
    double computeArea(double a, double b, double c) {
        double arg1 = std::pow(a * b, 1.6);
        double arg2 = std::pow(a * c, 1.6);
        double arg3 = std::pow(b * c, 1.6);
        double arg4 = arg1 + arg2 + arg3;
        double arg5 = arg4 / 3;
        return 4 * M_PI * std::pow(arg5, 1 / 1.6);
    }
}

CalcWidget::CalcWidget(QWidget *parent) : QWidget(parent), ui(new Ui::CalcWidgetClass) {

    ui->setupUi(this);
    hide_allWidgets();
    ui->MenuClass->show();

    connect(ui->cube, SIGNAL(clicked()), SLOT(show_CubeClass()));
    connect(ui->cuBack, SIGNAL(clicked()), SLOT(show_Menu()));
    connect(ui->sphere, SIGNAL(clicked()), SLOT(show_SphereClass()));
    connect(ui->spBack, SIGNAL(clicked()), SLOT(show_Menu()));
    connect(ui->cylinder, SIGNAL(clicked()), SLOT(show_CylinderClass()));
    connect(ui->cyBack, SIGNAL(clicked()), SLOT(show_Menu()));
    connect(ui->cone, SIGNAL(clicked()), SLOT(show_ConeClass()));
    connect(ui->coBack, SIGNAL(clicked()), SLOT(show_Menu()));
    connect(ui->tetrahedron, SIGNAL(clicked()), SLOT(show_TetrahedronClass()));
    connect(ui->teBack, SIGNAL(clicked()), SLOT(show_Menu()));
    connect(ui->ellipsoid, SIGNAL(clicked()), SLOT(show_EllipsoidClass()));
    connect(ui->elBack, SIGNAL(clicked()), SLOT(show_Menu()));
}

CalcWidget::~CalcWidget() {
    delete ui;
}

void CalcWidget::hide_allWidgets() {
    ui->MenuClass->hide();
    ui->CubeClass->hide();
    ui->SphereClass->hide();
    ui->CylinderClass->hide();
    ui->ConeClass->hide();
    ui->TetrahedronClass->hide();
    ui->EllipsoidClass->hide();
}

void CalcWidget::show_Menu() {
    hide_allWidgets();
    ui->MenuClass->show();
}

void CalcWidget::show_CubeClass() {
    hide_allWidgets();
    ui->CubeClass->show();
}

void CalcWidget::show_SphereClass() {
    hide_allWidgets();
    ui->SphereClass->show();
}

void CalcWidget::show_CylinderClass() {
    hide_allWidgets();
    ui->CylinderClass->show();
}

void CalcWidget::show_ConeClass() {
    hide_allWidgets();
    ui->ConeClass->show();
}

void CalcWidget::show_TetrahedronClass() {
    hide_allWidgets();
    ui->TetrahedronClass->show();
}

void CalcWidget::show_EllipsoidClass() {
    hide_allWidgets();
    ui->EllipsoidClass->show();
}

void CalcWidget::on_cyHeight_valueChanged(double d) {
    ui->cyVolume->display(Cylinder::computeVolume(ui->cyRadius->value(), d));
    ui->cySurfaceArea->display(Cylinder::computeArea(ui->cyRadius->value(), d));
}

void CalcWidget::on_cyRadius_valueChanged(double d) {
    ui->cyVolume->display(Cylinder::computeVolume(d, ui->cyHeight->value()));
    ui->cySurfaceArea->display(Cylinder::computeArea(d, ui->cyHeight->value()));
}

void CalcWidget::on_coHeight_valueChanged(double d) {
    ui->coVolume->display(Cone::computeVolume(ui->coRadius->value(), d));
    ui->coSurfaceArea->display(Cone::computeArea(ui->coRadius->value(), d));
}

void CalcWidget::on_coRadius_valueChanged(double d) {
    ui->coVolume->display(Cone::computeVolume(d, ui->coHeight->value()));
    ui->coSurfaceArea->display(Cone::computeArea(d, ui->coHeight->value()));
}

void CalcWidget::on_spRadius_valueChanged(double d) {
    ui->spVolume->display(Sphere::computeVolume(d));
    ui->spSurfaceArea->display(Sphere::computeArea(d));                                            
}                                                                                                  

void CalcWidget::on_cuLength_valueChanged(double d) {
    ui->cuVolume->display(Cube::computeVolume(d));
    ui->cuSurfaceArea->display(Cube::computeArea(d));
}

void CalcWidget::on_teEdge_valueChanged(double d) {
    ui->teVolume->display(Tetrahedron::computeVolume(d));
    ui->teArea->display(Tetrahedron::computeArea(d));
}

void CalcWidget::on_elMajor_valueChanged(double d) {
    ui->elVolume->display(Ellipsoid::computeVolume(d, ui->elMinor->value(), ui->elAxis->value()));
    ui->elArea->display(Ellipsoid::computeArea(d, ui->elMinor->value(), ui->elAxis->value()));
}

void CalcWidget::on_elMinor_valueChanged(double d) {
    ui->elVolume->display(Ellipsoid::computeVolume(ui->elMajor->value(), d, ui->elAxis->value()));
    ui->elArea->display(Ellipsoid::computeArea(ui->elMajor->value(), d, ui->elAxis->value()));
}

void CalcWidget::on_elAxis_valueChanged(double d) {
    ui->elVolume->display(Ellipsoid::computeVolume(ui->elMajor->value(), ui->elMinor->value(), d));
    ui->elArea->display(Ellipsoid::computeArea(ui->elMajor->value(), ui->elMinor->value(), d));
}