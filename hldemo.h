#ifndef HLDEMO_H
#define HLDEMO_H
#include <string>
#include <iostream>
#include <QFile>

namespace HLDemo
{
    /*!
     * \brief Holds Information about a Source engine demo file.
     */
    struct DemoInfo
    {
        std::string fileName;
        std::string mapName;
        std::string clientName;
        std::string serverName;
        float playbackTime;
        int numTicks;
    };
    enum DemoInfoReturnCode
    {
        SUCCESS = 0,
        FILE_NOT_FOUND,
        INVALID_FILE
    };
    /*!
     * \brief Fetches metadata of a Source engine demo file.
     * \param path path to the demo file
     */
    DemoInfoReturnCode getDemoInfo(const std::string path, DemoInfo & demoInfo);
}
#endif // HLDEMO_H
