#include "fenPrincipale.h"
#include "fenCodeGenere.h"
#include <Windows.h>

fenPrincipale::fenPrincipale(): QWidget()
{
    //Layout global
    m_box = new QVBoxLayout;

    //Layout pour les boutons Générer et Quitter
    m_boxBoutons = new QHBoxLayout;
    m_boxBoutons->setDirection(QBoxLayout::RightToLeft);

    //Définitions des groupbox
    m_def = new QGroupBox("Définition de la classe");
    m_cases = new QGroupBox("Options");
    m_autres = new QGroupBox("Autres");


    //Formulaire pour la définition de la classe
    m_magicien = new QLineEdit;
    m_mere = new QLineEdit;
    m_form = new QFormLayout;
    m_form->addRow("Nom:", m_magicien);
    m_form->addRow("Classe mère:", m_mere);
    m_def->setLayout(m_form);

    //Cases des options
    m_case1 = new QCheckBox("Protéger le header");
    m_case2 = new QCheckBox("Générer un constructeur par défaut");
    m_case3 = new QCheckBox("Générer un destructeur");
    m_boxCases = new QVBoxLayout;
    m_boxCases->addWidget(m_case1);
    m_boxCases->addWidget(m_case2);
    m_boxCases->addWidget(m_case3);
    m_cases->setLayout(m_boxCases);


    //Formulaire complémentaire
    m_commentaires = new QCheckBox("Ajouter des commentaires");
    m_date = new QDateEdit(QDate(2014,02,07));
    m_date->setEnabled(false);
    m_plus = new QFormLayout;
    m_auteur = new QLineEdit;
    m_auteur->setEnabled(false);     //pour bloquer si ce n'est pas coché
    m_blocTexte = new QTextEdit;
    m_blocTexte->setEnabled(false);
    m_plus->addRow("Auteur:", m_auteur);
    m_plus->addRow("Date:", m_date);
    m_plus->addRow("Commentaires:", m_blocTexte);
    m_autres->setLayout(m_plus);


    //Boutons en bas de la fenêtre
    m_generer = new QPushButton("Générer");
    m_quitter = new QPushButton("Quitter");
    m_boxBoutons->addWidget(m_quitter);
    m_boxBoutons->addWidget(m_generer);


    //Ajout des éléments dans le bloc de la fenêtre
    m_box->addWidget(m_def);
    m_box->addWidget(m_cases);
    m_box->addWidget(m_commentaires);
    m_box->addWidget(m_autres);
    m_box->addLayout(m_boxBoutons);

    setLayout(m_box);

    QObject::connect(m_quitter, SIGNAL(clicked()), qApp, SLOT(quit()));
    QObject::connect(m_commentaires, SIGNAL(clicked(bool)), this, SLOT(OkCommentaires(bool)));
    QObject::connect(m_generer, SIGNAL(clicked()), this, SLOT(appelerFenetre()));
}

//slot activé quand on active la case d'ajout de commentaire, en récupérant si la case est cochée ou décochée
void fenPrincipale::OkCommentaires(bool c)
{
    if(c)
    {
        m_auteur->setEnabled(true);
        m_date->setEnabled(true);
        m_blocTexte->setEnabled(true);
    }
    else
    {
        m_auteur->setEnabled(false);
        m_date->setEnabled(false);
        m_blocTexte->setEnabled(false);
    }
}

void fenPrincipale::appelerFenetre()
{
    fenGeneree *resultat = new fenGeneree;

    resultat->exec();
}
