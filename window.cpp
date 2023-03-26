#include "window.h"
#include <iostream>

Window::Window(QWidget *parent)
	: window(new QMainWindow)
    , canvas(new Canvas(window)) {
	// Definición
    widget = new QWidget(window);
    topFiller = new QWidget;
	bottomFiller = new QWidget;
	layout = new QVBoxLayout;

	
	// Sets
    window->setCentralWidget(widget);
	window->resize(1000,800);
	window->setWindowTitle("Hewo");

    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

	layout->setContentsMargins(5,5,5,5);
	layout->addWidget(topFiller);
	layout->addWidget(bottomFiller);
	widget->setLayout(layout);

	createActions();

}

void Window::createActions() {
    QMenu* menu = window->menuBar()->addMenu("File");
	file = new QAction("Open");
	menu->addAction(file);
	// QObject::connect(file, &QAction::triggered, canvas, &Canvas::drawCircle);
	connect(file, &QAction::triggered, this, &Window::openFile);
}

void Window::showMessage() {
	QMessageBox msgBox;
	msgBox.setText("HEWO!");
	msgBox.setInformativeText("Me cago en dios");
	int ret = msgBox.exec();
}

QString Window::selectFile() {
	QFileDialog dialog;
	QString fileName;
	dialog.setDirectory(QDir::currentPath());
	dialog.setNameFilter("Text Files: (*.txt)");
	if (dialog.exec() == dialog.Accepted)
		fileName = dialog.selectedFiles().at(0);
	return fileName;
}

void Window::openFile() {
	QString fileName = Window::selectFile();
	std::string path = fileName.toStdString();
	std::cout << path << std::endl;
	graph g;
	g = loadGraph(path);
	canvas->getGraph(g);
	canvas->drawCircle();
}

void Window::show() {
    window->show();
}
