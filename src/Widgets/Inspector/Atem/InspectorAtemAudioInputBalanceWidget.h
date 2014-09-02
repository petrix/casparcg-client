#pragma once

#include "../../Shared.h"
#include "ui_InspectorAtemAudioInputBalanceWidget.h"

#include "AtemDevice.h"

#include "Events/Atem/AtemDeviceChangedEvent.h"
#include "Commands/Atem/AtemAudioInputBalanceCommand.h"
#include "Events/Rundown/RundownItemSelectedEvent.h"
#include "Models/LibraryModel.h"

#include <QtCore/QEvent>
#include <QtCore/QObject>

#if QT_VERSION >= 0x050000
#include <QtWidgets/QWidget>
#else
#include <QtGui/QWidget>
#endif

class WIDGETS_EXPORT InspectorAtemAudioInputBalanceWidget : public QWidget, Ui::InspectorAtemAudioInputBalanceWidget
{
    Q_OBJECT

    public:
        explicit InspectorAtemAudioInputBalanceWidget(QWidget* parent = 0);

    private:
        LibraryModel* model;
        AtemAudioInputBalanceCommand* command;

        void blockAllSignals(bool block);
        void loadAtemAudioInput(QMap<quint16, QAtemConnection::InputInfo> inputs);

        Q_SLOT void inputChanged(int);
        Q_SLOT void sliderBalanceChanged(int);
        Q_SLOT void doubleSpinBoxBalanceChanged(double);
        Q_SLOT void triggerOnNextChanged(int);
        Q_SLOT void rundownItemSelected(const RundownItemSelectedEvent&);
        Q_SLOT void atemDeviceChanged(const AtemDeviceChangedEvent&);
};
