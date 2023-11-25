#include <iostream>
#include <string>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <sstream>
#include <fstream>

#include "../src/libs/json.hpp"
#include "Layout.hpp"

using json = nlohmann::json;

class Config
{
private:
  template <typename T>
  static T getJsonValue(const json &config, const std::string &key)
  {
    if (config.find(key) != config.end())
    {
      return config[key].get<T>();
    }
    else
    {
      throw std::runtime_error("Key '" + key + "' not found");
    }
  }

public:
  static void layout_change()
  {
    std::ifstream file("/home/serjei/projects/zizi/config/config.json");

    json config;
    try
    {
      file >> config;
    }
    catch (const nlohmann::json::parse_error &e)
    {
      throw std::runtime_error("Error parsing JSON: " + std::string(e.what()));
    }

    int layout = getJsonValue<int>(config, "layout");

    if (layout == 1)
    {
      Layout::Layout1();
    }
    else if (layout == 2)
    {
    }
  }
};
