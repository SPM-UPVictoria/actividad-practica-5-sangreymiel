#pragma once
#include <QWidget>
#include <QPainter>
#include <QLabel>
#include <string>
#include <iostream>
#include <vector>
#include "graph.h"

class Canvas : public QWidget {
	public:
		Canvas(QWidget *parent = nullptr);
		void drawCircle();
		void getGraphSize(int x);
		void getGraph(graph g);
		void drawLine();
	protected:
		void paintEvent(QPaintEvent *event) override;
		void loadFile(std::string path);
	private:
		enum class Shape {
			Circle,
			Line
		};
		QList<Shape> shapes;
		QList<QLabel*> names;
		std::pair<int,int> coords;
		std::vector<std::pair<int,int>> pos;
		graph g;
};
