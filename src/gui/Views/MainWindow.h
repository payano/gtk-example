#pragma once

#include <gtkmm.h>

namespace view {

class MainWindow: public Gtk::Window {
private:
	Glib::RefPtr<Gtk::Builder> builder;
	Gtk::Button *button1;
	void on_ok_button_clicked();
public:
	MainWindow(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade);
	virtual ~MainWindow();
};

} /* namespace view */

