#include <QApplication>
#include <QPushButton>
#include "Repository/AstronomersRepo.h"
#include "Repository/StarsRepo.h"
#include "Service/Service.h"
#include "GUI/GUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    std::string filename = "../Files/astronomers.txt";
    auto astronomersRepo = new AstronomersRepo(filename);
    filename = "../Files/stars.txt";
    auto starsRepo = new StarsRepo(filename);
    auto service = new Service(*astronomersRepo, *starsRepo);
    auto models = new Models();
    std::vector<Astronomer> astronomers = astronomersRepo->getAstronomers();

    for (auto astronomer : astronomers)
    {
        auto model = new TableModel(*service, astronomer);
        models->addModel(model);
        auto gui = new GUI(*service, astronomer, *model, *models);
        gui->show();
    }

    return QApplication::exec();
}
