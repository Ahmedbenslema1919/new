#include "connection.h"

Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
    QSqlDatabase db= QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("projet");
    db.setUserName("ahmed");//inserer nom de l'utilisateur
    db.setPassword("sys");//inserer mot de passe de cet utilisateur

    if (db.open())
    {
        test=true;
    }

    return  test;
}

void Connection::closeConnection()
{
    db.close();
}
