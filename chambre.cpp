#include "chambre.h"
#include <QSqlQuery>
#include <QSqlRecord>
#include <QVariant>
#include <QSqlQueryModel>

#include <QPdfWriter>
#include <QPainter>
#include <QPrinter>
#include <QFile>
#include <QTextDocument>
#include <QDate>
#include <QSqlError>

// Constructeurs
Chambre::Chambre() : id(0), capacite(0) {}
Chambre::Chambre(int id, int numero, QString type, int capacite, QString status_d, QString service, QString status_n)
    : id(id), numero(numero), type(type), capacite(capacite), status_d(status_d), service(service), status_n(status_n) {}

// Getters
int Chambre::getId() const { return id; }
int Chambre::getNumero() const { return numero; }
QString Chambre::getType() const { return type; }
int Chambre::getCapacite() const { return capacite; }
QString Chambre::getStatusD() const { return status_d; }
QString Chambre::getService() const { return service; }
QString Chambre::getStatusN() const { return status_n; }

// Setters
void Chambre::setId(int id) { this->id = id; }
void Chambre::setNumero(int numero) { this->numero = numero; }
void Chambre::setType(const QString &type) { this->type = type; }
void Chambre::setCapacite(int capacite) { this->capacite = capacite; }
void Chambre::setStatusD(const QString &status_d) { this->status_d = status_d; }
void Chambre::setService(const QString &service) { this->service = service; }
void Chambre::setStatusN(const QString &status_n) { this->status_n = status_n; }

// Ajouter
bool Chambre::ajouter() {
    QSqlQuery query;
    query.prepare("INSERT INTO chambre (id,numero, type, capacite, status_d, service, status_n) "
                  "VALUES (chambre_seq.NEXTVAL,:numero, :type, :capacite, :status_d, :service, :status_n)");
    query.bindValue(":numero", numero);
    query.bindValue(":type", type);
    query.bindValue(":capacite", capacite);
    query.bindValue(":status_d", status_d);
    query.bindValue(":service", service);
    query.bindValue(":status_n", status_n);
    return query.exec();
}

// Supprimer
bool Chambre::supprimer(int id) {
    QSqlQuery query;
    query.prepare("DELETE FROM chambre WHERE id = :id");
    query.bindValue(":id", id);
    return query.exec();
}

// Modifier
bool Chambre::modifier() {
    QSqlQuery query;
    query.prepare("UPDATE chambre SET numero = :numero, type = :type, capacite = :capacite, "
                  "status_d = :status_d, service = :service, status_n = :status_n WHERE id = :id");
    query.bindValue(":id", id);
    query.bindValue(":numero", numero);
    query.bindValue(":type", type);
    query.bindValue(":capacite", capacite);
    query.bindValue(":status_d", status_d);
    query.bindValue(":service", service);
    query.bindValue(":status_n", status_n);
    return query.exec();
}

// Afficher
QSqlQueryModel* Chambre::afficher() {
    QSqlQueryModel *model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM chambre");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Numéro"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Capacité"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Status Jour"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Service"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Status Nuit"));
    return model;
}

// Vérifier l'existence d'un ID
bool Chambre::existeId(int id) {
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM chambre WHERE id = :id");
    query.bindValue(":id", id);
    query.exec();
    if (query.next()) {
        return query.value(0).toInt() > 0;
    }
    return false;
}



// Recherche par critère
QSqlQueryModel* Chambre::rechercher(QString critere, QString valeur) {
    QSqlQueryModel* model = new QSqlQueryModel();
    QString queryStr = QString("SELECT * FROM chambre WHERE %1 LIKE '%%2%'").arg(critere, valeur);
    model->setQuery(queryStr); // envoye requete
    return model;
}

// Trier par critère
QSqlQueryModel* Chambre::trier(QString critere) {
    QSqlQueryModel* model = new QSqlQueryModel();//pour afficher les résultats d'une requête SQL


    QString queryStr = QString("SELECT * FROM chambre ORDER BY %1").arg(critere);
    model->setQuery(queryStr);
    return model;//renvoie un modèle
}
// Générer le modèle HTML pour le PDF
QString Chambre::genererContenuPDF() {
    // Définir un modèle HTML avec du CSS pour la mise en page
    QString html = R"(
    <html>
    <head>
        <style>
            body {
                font-family: Arial, sans-serif;
                margin: 0;
                padding: 0;
            }
            h1 {
                text-align: center;
                color: #333;
                margin-bottom: 20px;
            }
            table {
                width: 100%;
                border-collapse: collapse;
                margin: 0;
            }
            th, td {
                border: 1px solid #dddddd;
                padding: 10px;
                text-align: left;
                font-size: 9px;
            }
            th {
                background-color: #f2f2f2;
                font-weight: bold;
            }
            .footer {
                text-align: center;
                font-size: 12px;
                color: #666;
                margin-top: 30px;
            }
        </style>
    </head>
    <body>
        <h1>Rapport des Chambres</h1>
        <table>
            <tr>
                <th>ID chambre</th>
                <th>Numero</th>
                <th>Type</th>
                <th>capacité</th>
                <th>status_d</th>
                <th>service</th>
                <th>status_n</th>

            </tr>
    )";

    // Ajouter les pieces à la table dans la boucle
    QSqlQuery query("SELECT * FROM chambre");
    while (query.next()) {
        int id = query.value("id").toInt();
        int numero = query.value("numero").toInt();
        QString type = query.value("type").toString();
        int capacite = query.value("capacite").toInt();
        QString status_d = query.value("status_d").toString();
        QString service = query.value("service").toString();
        QString status_n = query.value("status_n").toString();



        html += QString(
                    "<tr>"
                    "<td>%1</td>"
                    "<td>%2</td>"
                    "<td>%3</td>"
                    "<td>%4</td>"
                    "<td>%5</td>"
                    "<td>%6</td>"
                    "<td>%7</td>"


                    "</tr>"
                    )
                    .arg(id)
                    .arg(numero)
                    .arg(type)
                    .arg(capacite)
                    .arg(status_d)
                    .arg(service)
                    .arg(status_n)
            ;

    }

    html += QString(R"(
        </table>
        <div class='footer'>
            <p>Ce rapport a été généré automatiquement le %1.</p>
        </div>
    </body>
    </html>
    )").arg(QDate::currentDate().toString("dd/MM/yyyy"));

    return html;
}

// Gérer la génération du PDF
void Chambre::genererPDF(const QString& fichierPDF) {
    QString contenuHTML = genererContenuPDF(); // Récupérer le contenu HTML généré

    QTextDocument document;
    document.setHtml(contenuHTML);

    // Configurer le QPrinter pour créer un PDF
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fichierPDF);

    // Définir les marges de la page
    printer.setPageMargins(QMarginsF(15, 15, 15, 15));

    // Imprimer le document dans le fichier PDF
    document.print(&printer);
}
QPieSeries* Chambre::statistiques() {
    QPieSeries* series = new QPieSeries();

    // Requête SQL pour compter les chambre par service
    QSqlQuery query;
    query.prepare("SELECT service, COUNT(*) FROM chambre GROUP BY service");

    if (query.exec()) {
        while (query.next()) {
            QString service = query.value(0).toString();
            int count = query.value(1).toInt();
            series->append(service, count);
        }
    } else {
        qDebug() << "Erreur lors de la récupération des statistiques par etat : " << query.lastError().text();
    }

    return series;
}

