#include "MainWindow.h"
#include "ui_MainWindow.h"

#include "xcursor.h"

#include <QDebug>
#include <QCursor>
#include <QFile>

#include <iostream>
#include <fstream>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
      , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    try {
        // read data using the Qt functions to be able to read cursors from Qt resources
        const QString xcurFilePath = ":/xcursors/openzone-cursors/white-copy";
        QFile qFile(xcurFilePath);
        if (!qFile.open(QIODevice::ReadOnly)) {
            Q_ASSERT(false);
        }

        std::string fileDataStr = qFile.readAll().toStdString();
        kaitai::kstream ks(fileDataStr);
        xcursor_t xcur = xcursor_t(&ks);
        if (xcur.ntoc() > 0) {
            xcursor_t::toc_entry_t* toc = xcur.toc()->at(0);
            if (toc->type() == xcursor_t::CHUNK_TYPE_IMAGE) {
                auto shunk = toc->chunk();
                Q_ASSERT(toc->type() == shunk->type());
                xcursor_t::chunk_image_t *img = dynamic_cast<xcursor_t::chunk_image_t *>(shunk->body());
                Q_ASSERT(img);
                if (img) {
                    qDebug() << img->width() << img->height() << img->xhot() << img->yhot();
                    const QImage qimg(img->pixels()->data(), img->width(), img->height(), QImage::Format_ARGB32);

                    ui->label->setPixmap(QPixmap::fromImage(qimg).scaled(qimg.size() * 8));
                    ui->label->adjustSize();

                    QCursor qcursor(QPixmap::fromImage(qimg), img->xhot(), img->yhot());
                    setCursor(qcursor);
                }
            }
        }
    } catch (const std::exception& e) {
        qDebug() << "exception:" << e.what();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

