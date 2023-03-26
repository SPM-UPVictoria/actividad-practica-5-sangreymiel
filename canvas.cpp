#include "canvas.h"

Canvas::Canvas(QWidget *parent) : QWidget(parent) {
    setFixedSize(800, 600);
}

void Canvas::getGraph(graph gp) {
	g = gp;
}

void Canvas::drawCircle() {
	shapes.clear();
	pos.clear();
    shapes.append(Shape::Circle);
    update();
}

void Canvas::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    painter.setPen(Qt::black);
    for (auto shape : shapes) {
        if (shape == Shape::Circle) {
            painter.setBrush(Qt::red);
			for (int i = 0; i < g.size(); i++) {
				coords.first = (std::rand() % 750);
				coords.second = (std::rand() % 550);
				pos.push_back(coords);
				painter.drawEllipse(coords.first, coords.second, 20, 20);
			}
			painter.setPen(Qt::white);
			for (int i = 0; i < g.size(); i++) {
				for (int j = 0; j < g[i].size(); j++) {
					painter.drawLine(pos[i].first, pos[i].second, pos[j].first, pos[j].second);
				}
				// painter.drawLine(pos[i].first,pos[i].second, pos[i+1].first, pos[i+1].second);
			}
        }     
	}
}

