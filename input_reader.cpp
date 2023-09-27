#include "input_reader.h"
#include <sstream>

namespace inout {

std::vector<Query> readQueriesFromStream(std::istream& inStream) {
    std::vector<Query> queries;
    int N;  // Число запросов
    std::string line;

    // Считывание запросов для обновления базы данных
    inStream >> N;
    std::getline(inStream, line);
    for (int i = 0; i < N; ++i) {
        std::getline(inStream, line);
        Query query;
        if (line.find("Stop") == 0) {
            query.type = RequestType::STOP;
            query.data = line.substr(5);
        } else if (line.find("Bus") == 0) {
            query.type = RequestType::BUS;
            query.data = line.substr(4);
        }
        queries.push_back(query);
    }

    // Считывание запросов к базе данных
    inStream >> N;
    std::getline(inStream, line);
    for (int i = 0; i < N; ++i) {
        std::getline(inStream, line);
        Query query;
        if (line.find("Bus") == 0) {
            query.type = RequestType::GET_BUS_INFO;
            query.data = line.substr(4);
        }
        queries.push_back(query);
    }

    return queries;
}

}  // namespace inout