#include <iostream>
#include <sstream>
#include <iomanip>  // Для std::setprecision

#include "input_reader.h"
#include "transport_catalogue.h"

/*
    void TransportCatalogue::AddRoute(      const std::string& route_name, const std::vector<std::string>& stops, bool is_circular)      {
        // Реализация добавления маршрута
    }

    void TransportCatalogue::AddStop(       const std::string& stop_name, double latitude, double longitude     ) {
        // Реализация добавления остановки
    }

    auto TransportCatalogue::GetRouteInfo(      const std::string& route_name   ) const {
        // Реализация получения информации о маршруте
    }
*/
void ProcessAddStopQuery(const inout::Query& query, tc::TransportCatalogue& catalogue) {
    std::istringstream iss(query.data);
    std::string stop_name;
    double latitude, longitude;

    std::getline(iss, stop_name, ':');
    iss >> latitude >> longitude;

    // catalogue.AddStop(stop_name, latitude, longitude);
    std::cout << "Stop added"  << std::endl;
}

void ProcessAddBusQuery(const inout::Query& query, tc::TransportCatalogue& catalogue) {
    std::istringstream iss(query.data);
    std::string bus_name, stop_name;
    std::vector<std::string> stops;
    bool is_circular = true;  // По умолчанию считаем маршрут кольцевым

    std::getline(iss, bus_name, ':');
    while (std::getline(iss, stop_name, ' ')) {
        if (stop_name == "-") {
            is_circular = false;  // Обнаружили "-", значит маршрут не кольцевой
            continue;
        }
        stops.push_back(stop_name);
    }

    // catalogue.AddRoute(bus_name, stops, is_circular);
    std::cout << "Bus added" << std::endl;
}

void ProcessGetBusInfoQuery(const inout::Query& query, const tc::TransportCatalogue& catalogue) {
    // auto bus_info = catalogue.GetRouteInfo(query.data);
    // if (bus_info) {
    //     std::cout << "Bus " << query.data << ": "
    //               << bus_info->R << " stops on route, "
    //               << bus_info->U << " unique stops, "
    //               << std::setprecision(6) << bus_info->L << " route length\n";
    // } else {
    //     std::cout << "Bus " << query.data << ": not found\n";
    // }
}

void ProcessQueries(const std::vector<inout::Query>& raw_queries, tc::TransportCatalogue& catalogue) {
    for (const auto& query : raw_queries) {
        switch (query.type) {
        case inout::RequestType::STOP:
            ProcessAddStopQuery(query, catalogue);
            break;
        case inout::RequestType::BUS:
            ProcessAddBusQuery(query, catalogue);
            break;
        case inout::RequestType::GET_BUS_INFO:  // Новый case
            // ProcessGetBusInfoQuery(query, catalogue);
            std::cout << "GET_BUS_INFO" << std::endl;
            break;
        }
    }
}


int main() {
    std::cout << "Hello World!\n";
    tc::TransportCatalogue tc;
    std::vector<inout::Query> raw_query = inout::readQueriesFromStream(std::cin);
    ProcessQueries(raw_query, tc);
}
