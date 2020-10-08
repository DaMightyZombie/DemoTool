#include <QApplication>
#include <QDir>

#include "settings.hpp"

namespace fs = std::filesystem;

bool Settings::_initialized = false;
QSettings *Settings::settings = nullptr;

QSettings *Settings::GetSettings()
{
    if (!_initialized) {
        settings = new QSettings(QDir::cleanPath(QApplication::applicationDirPath() + QDir::separator() + "config.ini"), QSettings::NativeFormat);
        _initialized = true;
    }
    return settings;
}
