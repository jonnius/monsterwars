/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 *                                                                         *
 *  Copyright (C) 2015 Simon Stuerz <stuerz.simon@gmail.com>               *
 *                                                                         *
 *  This file is part of Monster Wars.                                     *
 *                                                                         *
 *  Monster Wars is free software: you can redistribute it and/or modify   *
 *  it under the terms of the GNU General Public License as published by   *
 *  the Free Software Foundation, version 3 of the License.                *
 *                                                                         *
 *  Monster Wars is distributed in the hope that it will be useful,        *
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of         *
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the           *
 *  GNU General Public License for more details.                           *
 *                                                                         *
 *  You should have received a copy of the GNU General Public License      *
 *  along with Monster Wars. If not, see <http://www.gnu.org/licenses/>.   *
 *                                                                         *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QIcon>
#include <QCommandLineParser>
#include <QCommandLineOption>
#include <QtQml>
#include <QtQml/QQmlContext>

#include "gameengine.h"
#include "player.h"
#include "monster.h"
#include "level.h"
#include "board.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    app.setApplicationVersion("1.0.0");
    app.setApplicationDisplayName("Monster Wars");

    // register qml types
    qmlRegisterType<GameEngine>("MonsterWars", 1, 0, "GameEngine");
    qmlRegisterUncreatableType<Board>("MonsterWars", 1, 0, "Board", "Can't create this in QML. Get it from the GameEngine.");
    qmlRegisterUncreatableType<Monster>("MonsterWars", 1, 0, "Monster", "Can't create this in QML. Get it from Board.");
    qmlRegisterUncreatableType<MonsterModel>("MonsterWars", 1, 0, "MonsterModel", "Can't create this in QML. Get it from Board.");
    qmlRegisterUncreatableType<Level>("MonsterWars", 1, 0, "Level", "Can't create this in QML. Get it from Board.");
    qmlRegisterUncreatableType<LevelModel>("MonsterWars", 1, 0, "LevelModel", "Can't create this in QML. Get it from Board.");
    qmlRegisterUncreatableType<AttackPillowModel>("MonsterWars", 1, 0, "AttackPillowModel", "Can't create this in QML. Get it from the GameEngine.");
    qmlRegisterUncreatableType<Player>("MonsterWars", 1, 0, "Player", "Can't create this in QML. Get it from Board.");
    qmlRegisterUncreatableType<PlayerSettings>("MonsterWars", 1, 0, "PlayerSettings", "Can't create this in QML. Get it from GameEngine.");

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("dataDirectory", "assert:");
    engine.rootContext()->setContextProperty("fullscreen", true);
    engine.rootContext()->setContextProperty("version", app.applicationVersion());

    engine.load(QUrl(QLatin1String("qrc:/MonsterWars.qml")));

    // connect quit signal from QML engine (quit button pressed)
    //QObject::connect(engine, SIGNAL(quit()), qApp, SLOT(quit()));

    return app.exec();
}

