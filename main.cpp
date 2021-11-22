#include <gtkmm-3.0/gtkmm.h>

#include <iostream>

/*
 * https://milindapro.blogspot.com/2012/10/create-gui-with-gtkmm-glade-with-gtkmm.html
 */

class FrmMain : public Gtk::Window {
public:
	Glib::RefPtr<Gtk::Builder> builder;
	Gtk::Button *button1;
	FrmMain(BaseObjectType* cobject, const Glib::RefPtr<Gtk::Builder>& refGlade)
	: Gtk::Window(cobject), builder(refGlade), button1(nullptr)
	{
		builder->get_widget("button1", button1);
		button1->signal_clicked().connect(sigc::mem_fun(*this, &FrmMain::on_ok_button_clicked));
		set_title("Test App");
	}
	void on_ok_button_clicked(){
		std::cout << "OK clicked" << std::endl;
	}
	~FrmMain() {}
};


int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;

	auto app = Gtk::Application::create("org.gtkmm.examples.base");
	Glib::RefPtr<Gtk::Builder> builder = Gtk::Builder::create_from_file("layout.glade");

	FrmMain *frm;
	builder->get_widget_derived("window", frm);
	app->run(*frm);
}
