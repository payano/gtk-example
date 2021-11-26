
#include <iostream>

#include "src/gui/ViewStarter.h"

int main(int argc, char *argv[]) {
	(void)argc;
	(void)argv;
	view::ViewStarter *newView = new view::ViewStarter;
	newView->start();
}
