#include "keyBindsConfig.h"
#include <map>
#include "imgui/imgui.h"

static const std::map<uint8_t, const char*> KeyMap = {
    
    {0x02, "MOUSE 2"},
    {0x04, "MOUSE 3"},
    {0x05, "MOUSE 4"},
    {0x06, "MOUSE 5"},
    {0x08, "BACKSPACE"},
    {0x09, "TAB"},
    {0x0C, "CLEAR"},
    {0x0D, "RETURN"},
    {0x10, "SHIFT"},
    {0x11, "CTRL"},
    {0x12, "ALT"},
    {0x13, "PAUSE"},
    {0x14, "CAPS LOCK"},
    {0x1B, "ESC"},
    {0x20, "SPACE"},
    {0x21, "PG UP"},
    {0x22, "PG DN"},
    {0x23, "END"},
    {0x24, "HOME"},
    {0x2D, "INS"},
    {0x2E, "DEL"},
    {0x2C, "PRNTSCR"},
    {0x30, "0"},
    {0x31, "1"},
    {0x32, "2"},
    {0x33, "3"},
    {0x34, "4"},
    {0x35, "5"},
    {0x36, "6"},
    {0x37, "7"},
    {0x38, "8"},
    {0x39, "9"},
    {0x42, "B"},
    {0x43, "C"},
    {0x46, "F"},
    {0x47, "G"},
    {0x48, "H"},
    {0x49, "I"},
    {0x4A, "J"},
    {0x4B, "K"},
    {0x4C, "L"},
    {0x4D, "M"},
    {0x4E, "N"},
    {0x4F, "O"},
    {0x50, "P"},
    {0x54, "T"},
    {0x55, "U"},
    {0x56, "V"},
    {0x58, "X"},
    {0x59, "Y"},
    {0x5A, "Z"},
    {0x5B, "WINDOWS"},
    {0x5C, "WINDOWS"},
    {0x60, "NUM 0"},
    {0x61, "NUM 1"},
    {0x62, "NUM 2"},
    {0x63, "NUM 3"},
    {0x64, "NUM 4"},
    {0x65, "NUM 5"},
    {0x66, "NUM 6"},
    {0x67, "NUM 7"},
    {0x68, "NUM 8"},
    {0x69, "NUM 9"},
    {0x6A, "MULTIPLY"},
    {0x6B, "ADD"},
    {0x6C, "SEPARATOR"},
    {0x6D, "SUBTRACT"},
    {0x6E, "DECIMAL"},
    {0x6F, "DIVIDE"},
    {0x70, "F1"},
    {0x71, "F2"},
    {0x72, "F3"},
    {0x73, "F4"},
    {0x74, "F5"},
    {0x75, "F6"},
    {0x76, "F7"},
    {0x77, "F8"},
    {0x78, "F9"},
    {0x79, "F10"},
    {0x7A, "F11"},
    {0x7B, "F12"},
    {0xA0, "L SHIFT"},
    {0xA1, "R SHIFT"},
    {0xA2, "L CTRL"},
    {0xA3, "R CTRL"},
};

KeyBindsConfig KeyBindsConfig::fromJson(nlohmann::ordered_json json)
{
    KeyBindsConfig keyBinds = KeyBindsConfig();

    keyBinds.Toggle_Menu = json["Toggle_Menu"].get<uint8_t>();
    keyBinds.Toggle_Radar = json["Toggle_Radar"].get<uint8_t>();
    keyBinds.Toggle_Console = json["Toggle_Console"].get<uint8_t>();
    keyBinds.Repair_Sabotage = json["Repair_Sabotage"].get<uint8_t>();
    keyBinds.Repair_Sabotage = json["Toggle_Noclip"].get<uint8_t>();
    keyBinds.Close_All_Doors = json["Close_All_Doors"].get<uint8_t>();
    keyBinds.Toggle_Zoom = json["Toggle_Zoom"].get<uint8_t>();
    keyBinds.Toggle_Freecam = json["Toggle_Freecam"].get<uint8_t>();
    keyBinds.Close_Current_Room_Door = json["Close_Current_Room_Door"].get<uint8_t>();

    return keyBinds;
}

nlohmann::ordered_json KeyBindsConfig::toJson(KeyBindsConfig keyBinds)
{
    nlohmann::ordered_json json = nlohmann::ordered_json();

    json["Toggle_Menu"] = keyBinds.Toggle_Menu;
    json["Toggle_Radar"] = keyBinds.Toggle_Radar;
    json["Toggle_Console"] = keyBinds.Toggle_Console;
    json["Repair_Sabotage"] = keyBinds.Repair_Sabotage;
    json["Toggle_Noclip"] = keyBinds.Toggle_Noclip;
    json["Close_All_Doors"] = keyBinds.Close_All_Doors;
    json["Toggle_Zoom"] = keyBinds.Toggle_Zoom;
    json["Toggle_Freecam"] = keyBinds.Toggle_Freecam;
    json["Close_Current_Room_Door"] = keyBinds.Close_Current_Room_Door;

    return json;
}

const char* KeyBindsConfig::toString(uint8_t key)
{
    auto iter = KeyMap.find(key);
    if (iter != KeyMap.end())
        return iter->second;

    return "NONE";
}

std::vector<uint8_t> KeyBindsConfig::getValidKeys()
{
    std::vector<uint8_t> validKeys = std::vector<uint8_t>();

    for (auto const& [key, value] : KeyMap)
        validKeys.push_back(key);

    return validKeys;
}

bool KeyBindsConfig::IsReleased(uint8_t key)
{
    if (key == 0x02)
        return ImGui::IsMouseReleased(1);
    else if (key == 0x04)
        return ImGui::IsMouseReleased(2);
    else if (key == 0x05)
        return ImGui::IsMouseReleased(3);
    else if (key == 0x06)
        return ImGui::IsMouseReleased(4);
    else
        return ImGui::IsKeyReleased(key);
}