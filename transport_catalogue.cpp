#include "transport_catalogue.h"

namespace tc {

    TransportCatalogue::TransportCatalogue() {
        // Конструктор по умолчанию
    }

    void TransportCatalogue::AddRoute(const std::string& route_name, const std::vector<std::string>& stops, bool is_circular) {
        // Реализация добавления маршрута
    }

    void TransportCatalogue::AddStop(const std::string& stop_name, double latitude, double longitude) {
        // Реализация добавления остановки
    }

    auto TransportCatalogue::GetRouteInfo(const std::string& route_name) const {
        // Реализация получения информации о маршруте
    }

    auto TransportCatalogue::FindRouteByName(const std::string& route_name) const {
        // Реализация поиска маршрута по имени
    }

    auto TransportCatalogue::FindStopByName(const std::string& stop_name) const {
        // Реализация поиска остановки по имени
    }

    

}  // namespace tc
