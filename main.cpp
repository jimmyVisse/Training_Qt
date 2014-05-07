#include <QApplication>
#include "fenPrincipale.h"
#include "fenCodeGenere.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    fenPrincipale fen;

    fen.show();

    return app.exec();
}
