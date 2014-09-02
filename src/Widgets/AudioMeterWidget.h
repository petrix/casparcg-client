#pragma once

#include "Shared.h"
#include "ui_AudioMeterWidget.h"

#include "OscSubscription.h"
#include "Events/Rundown/RundownItemSelectedEvent.h"
#include "Models/LibraryModel.h"

#if QT_VERSION >= 0x050000
#include <QImage>
#include <QtWidgets/QWidget>
#else
#include <QtGui/QImage>
#include <QtGui/QWidget>
#endif

class WIDGETS_EXPORT AudioMeterWidget : public QWidget, Ui::AudioMeterWidget
{
    Q_OBJECT

    public:
        explicit AudioMeterWidget(QWidget* parent = 0);

        void configureAudioMeter(int channel);

    private:
        int channel;
        LibraryModel* model;
        AbstractCommand* command;

        OscSubscription* audioSubscription;

        void configureOscSubscriptions();

        Q_SLOT void rundownItemSelected(const RundownItemSelectedEvent&);
        Q_SLOT void audioSubscriptionReceived(const QString&, const QList<QVariant>&);
};
