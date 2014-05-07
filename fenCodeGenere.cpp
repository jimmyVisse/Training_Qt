#include "fenCodeGenere.h"

fenGeneree::fenGeneree(): QDialog()
{
    setFixedSize(300, 600);

    //création des différents widgets
    m_texte = new QTextEdit;
    m_layout = new QVBoxLayout;
    m_fermer = new QPushButton("Fermer");

    m_texte->setText("Bonjour");
    m_texte->setReadOnly(true);

    m_layout->addWidget(m_texte);
    m_layout->addWidget(m_fermer);

    QObject::connect(m_fermer, SIGNAL(clicked()), this, SLOT(close()));

    setLayout(m_layout);
}
