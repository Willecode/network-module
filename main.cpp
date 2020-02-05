#include <iostream>
#include <QNetworkAccessManager>
#include "network.h"
using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Network handler;
    handler.postRequest("https://www.finlandiahiihto.fi/Tulokset/Tulosarkisto");

    return a.exec();
}
