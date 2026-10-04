#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QWidget>
#include <QTimer>
#include <QTime>
#include <QDebug>

class StopWatch : public QObject
{
    Q_OBJECT

public:

    explicit StopWatch(QObject *parent = nullptr);

    ~StopWatch() override;;

    void updateTime();
    void startTimer();
    void stopTimer();
    QString& getCurrentTime() const;
    QString& getCircleTime();

signals:
    void sig_updateTime(const QString& timeStr);

private slots:
    void updateTime();

private:
    QTimer* timer = nullptr;
    QTime time;
    QTime stopTime;
    int circleTiming = 0;
    int count = 1;
    QString strCurrentTime;
    QString strCircleTime;
};

#endif // STOPWATCH_H
