#include "hldemo.hpp"

#include <iostream>
#include <fstream>
#include <cstring>
#include <filesystem>

#include "include/json.hpp"

using json = nlohmann::json;
namespace fs = std::filesystem;


namespace HLDemo {
HLDemo::HLDemo()
{

}

DemoInfoReturnCode HLDemo::open(std::string path)
{
    // See https://developer.valvesoftware.com/wiki/Demo
    // for information about the file format
    std::ifstream file;
    file.open(path, std::ios::binary);

    char buf[261];
    if (!file.is_open()) {
        return FILE_NOT_FOUND;
    }
    // Check if the file has the correct header
    file.read(buf, 8);
    if (strcmp("HL2DEMO\0", buf)) {
        return INVALID_FILE;
    }
    // skip over two integer parameters we don't care about
    file.seekg(8, file.cur);

    file.read(buf, 260);
    this->serverName = buf;
    file.read(buf, 260);
    this->clientName = buf;
    file.read(buf, 260);
    this->mapName = buf;
    // skip reading the game directory
    file.seekg(260, file.cur);
    file.read((char *) & this->playbackTime, sizeof (this->playbackTime));
    file.read((char *) & this->numTicks, sizeof (this->numTicks));
    this->fileName = path;

    file.close();

    this->LoadEvents();
    return SUCCESS;
}

void HLDemo::LoadEvents()
{
    fs::path jsonPath = this->fileName.replace_extension(".json");
    if (!fs::exists(jsonPath)) {
        return;
    }
    std::ifstream file;
    json j;
    file.open(jsonPath);
    file >> j;
    file.close();

    this->events.clear();
    for (auto event : j["events"]) {
        DemoEvent _event;
        if (event["name"] == "Killstreak") {
            _event.type = Killstreak;
        }
        else {
            _event.type = Bookmark;
        }
        _event.value = event["value"];
        _event.tick = event["tick"];

        this->events.push_back(_event);
    }
}

std::vector<HLDemo> getDemosInDirectory(const std::string path)
{
    std::vector<HLDemo> demos;
    for (const auto & entry : fs::directory_iterator(path)){
        if (entry.path().extension() == ".dem"){
            HLDemo demo;
            demo.open(entry.path());
            demos.push_back(demo);
        }
    }
    return demos;
}

std::string HLDemo::GetFileName(){return this->fileName;}
std::string HLDemo::GetMapName(){return this->mapName;}
std::string HLDemo::GetClientName(){return this->clientName;}
std::string HLDemo::GetServerName(){return this->serverName;}
float HLDemo::GetPlaybackTime(){return this->playbackTime;}
int HLDemo::GetNumTicks(){return this->numTicks;}

}
