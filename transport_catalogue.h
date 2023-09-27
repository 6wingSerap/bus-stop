#pragma once
#include <string>
#include <unordered_map>
#include <vector>

namespace tc {

    class TransportCatalogue {
    public:
        TransportCatalogue();
        
        void AddRoute(const std::string& route_name, const std::vector<std::string>& stops, bool is_circular = false);
        
        void AddStop(const std::string& stop_name, double latitude, double longitude);
        
        auto FindRouteByName(const std::string& route_name) const;
        
        auto FindStopByName(const std::string& stop_name) const;
        
        auto GetRouteInfo(const std::string& route_name) const;

    private:
        // Внутренние структуры данных для хранения информации об остановках и маршрутах
    };

}  // namespace tc