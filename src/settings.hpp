#ifndef SETTINGS_HPP
#define SETTINGS_HPP

#include <QSettings>
#include <filesystem>

class Settings
{
public:
    static QSettings *GetSettings();
private:
    static QSettings *settings;
    static bool _initialized;
};

#endif // SETTINGS_HPP
