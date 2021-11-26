
#include <gtkmm.h>

#include "ViewStarter.h"
#include "MainWindow.h"

namespace view {

ViewStarter::ViewStarter() {
}

void ViewStarter::start()
{
		auto app = Gtk::Application::create("org.gtkmm.examples.base");
		Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("layout.glade");

		MainWindow *frm;
		builder->get_widget_derived("window", frm);
		app->run(*frm);

}

ViewStarter::~ViewStarter() {
	// TODO Auto-generated destructor stub
}

} /* namespace view */
