#include <iostream>
#include "MainWindow.h"

namespace view {
/*
 * Source: https://milindapro.blogspot.com/2012/10/create-gui-with-gtkmm-glade-with-gtkmm.html
 */

MainWindow::MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade) :
		Gtk::Window(cobject), builder(refGlade), button1(nullptr)
{
	builder->get_widget("button1", button1);
	button1->signal_clicked().connect(sigc::mem_fun(*this, &MainWindow::on_ok_button_clicked));
	set_title("Test App");
}

void MainWindow::on_ok_button_clicked(){
	std::cout << "OK clicked" << std::endl;
}

MainWindow::~MainWindow() {
	// TODO Auto-generated destructor stub
}

} /* namespace view */
