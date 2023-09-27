#pragma once
#include <iostream>
#include <vector>
#include <string>

namespace inout {

enum class RequestType {
    STOP,
    BUS,
    GET_BUS_INFO  // Новый тип запроса для получения информации о маршруте
};


struct Query {
    RequestType type;   // Тип запроса
    std::string data;   // Дополнительные данные запроса в виде строки
};

std::vector<Query> readQueriesFromStream(std::istream& inStream);

}  // namespace inout
