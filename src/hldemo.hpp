#ifndef HLDEMO_H
#define HLDEMO_H
#include <string>
#include <vector>
#include <iostream>
#include <filesystem>

namespace fs = std::filesystem;

namespace HLDemo
{
enum DemoInfoReturnCode
{
    SUCCESS = 0,
    FILE_NOT_FOUND,
    INVALID_FILE
};

struct DemoEvent
{
    int tick;
    std::string type;
    std::string value;
};

class HLDemo
{
public:
    HLDemo();

    /*!
     * \brief Fetches metadata of a Source engine demo file.
     * \param path path to the demo file
     */
    DemoInfoReturnCode open(std::string path);

    fs::path GetFileName();
    std::string GetMapName();
    std::string GetClientName();
    std::string GetServerName();
    float GetPlaybackTime();
    int GetNumTicks();
    std::vector<DemoEvent> * GetEvents();
    void WriteEvents();
private:
    fs::path fileName;
    std::string mapName;
    std::string clientName;
    std::string serverName;
    float playbackTime;
    int numTicks;
    std::vector<DemoEvent> events;
    fs::path getJSONPath();
    void LoadEvents();
};

std::vector<HLDemo> getDemosInDirectory(const std::string path);
}
#endif // HLDEMO_H
