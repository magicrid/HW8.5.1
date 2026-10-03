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

    ~StopWatch();

    void updateTime();
    void startTimer();
    void stopTimer();
    QString& getCurrentTime();
    QString& getCircleTime();

public slots:

    void circleTime();
    void clearTime();


signals:

    void sig_updateTime(QString &strCurrentTime);

private:
    QTimer *timer;
    QTime time;
    QTime stopTime;
    QString strCurrentTime;
    QString strCircleTime;
    int circleTiming;
    int count;
};

#endif // STOPWATCH_H
